
#ifndef FENETREGRAPHESFML_H
#define FENETREGRAPHESFML_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>


#include "Sommet.h"
#include "VSommet.h"
#include "Arete.h"
#include "World.hpp"
#include "InfosGrapheDessin.h"

#include "TransfoAffine2D.h"
#include "Peinture.h"
#include "GameElement.hpp"
#include "TextureFactory.h"
using namespace sf;
using namespace std;




inline const Vector2f vecteur2DToVector2f( const Vecteur2D & v) { float x,y; v.arrondit(x,y); return Vector2f(x,y);}



/**

vSommet : en coordonn�es monde
*/
inline bool dessinePetitRond(RenderWindow & fenetre, const TransfoAffine2D & t, const VSommet & vSommet, const Font & font,
							const Vecteur2D & deltaTextePixels = Vecteur2D(VSommet::rayonDisquePixels, VSommet::rayonDisquePixels))
{
Vecteur2D position = t.applique(vSommet.p);
Vecteur2D position1 = position -VSommet::rayonDisquePixels*Vecteur2D(1,1);

// si on appliquait la transfo t globalement � tout le graphe avant de commencer � dessiner, on optimiserait
// bcp de calculs !!!!

CircleShape disque((float)VSommet::rayonDisquePixels);
disque.setFillColor(Color(vSommet.couleur));
float epaisseurBord = (float)(0.15*VSommet::rayonDisquePixels);
disque.setOutlineThickness(epaisseurBord);
disque.setOutlineColor(Color(VSommet::couleurBord));

Vector2f p1 = vecteur2DToVector2f(position1);

disque.setPosition(p1);
disque.setOrigin( VSommet::rayonDisquePixels, VSommet::rayonDisquePixels);
fenetre.draw(disque);

Vecteur2D position2 = position - deltaTextePixels;
unsigned int tailleEnPixels = 17;
Text texte(vSommet.nom, font,tailleEnPixels);
texte.setFillColor(Color::Black);
texte.setPosition(vecteur2DToVector2f(position2));
fenetre.draw(texte);
return true;
}




/**
d�but et fin sont en coordonn�es monde
*/
inline bool dessineSegment( RenderWindow & fenetre, const TransfoAffine2D & t, const unsigned int couleur,
						const Vecteur2D & debut, const Vecteur2D & fin, const unsigned int epaisseurTraitPixels = 1)
{
// on va dessiner un rectangle tr�s fin pour repr�senter l'ar�te

Vecteur2D A, B;	// {AB] est l'ar�te � repr�senter

A = t.applique(debut); B = t.applique(fin);		// on passe des coordonn�es monde aux coordonn�es �cran

Vecteur2D u = B-A;

double nU = norme(u);
u /=nU;
Vecteur2D  n = u.rotationDirecteQuartDeTour();

//double e = 1;	// �paisseur du rectangle = 2*e. longueur du rectangle == AB
double e = 0.5*epaisseurTraitPixels;	// �paisseur du rectangle = 2*e. longueur du rectangle == AB


Vecteur2D v = e*n;

Vecteur2D A0= A-v,A1 = B-v, A2 = B+v,A3 = A+v; // on calcule les 4 sommets du rectangle dont l'ar�te [AB] est un axe de sym�trie

Vector2f F0 = vecteur2DToVector2f(A0);
Vector2f F1 = vecteur2DToVector2f(A1);
Vector2f F2 = vecteur2DToVector2f(A2);
Vector2f F3 = vecteur2DToVector2f(A3);

ConvexShape rectangle(4);
rectangle.setPoint(0,F0);
rectangle.setPoint(1,F1);
rectangle.setPoint(2,F2);
rectangle.setPoint(3,F3);

rectangle.setFillColor(Color(couleur));

fenetre.draw(rectangle);

return true;
}


/**
Prend en charge le dessin d'un graphe

Prend en charge le passage de coordonn�es monde ---> �cran

*/
class FenetreGrapheSFML
{
public:


RenderWindow fenetre;
const Font & font;


TransfoAffine2D t;	// r�alise le passage fen�tre-cl�ture (ou encore monde vers �cran)

FenetreGrapheSFML( const string & titre, const unsigned int fondCarte,
				const Vecteur2D & coinBG, const Vecteur2D & coinHD,
								  const int largeur, const int hauteur, const Font & font):
								  	fenetre(sf::VideoMode(largeur,hauteur), titre), font(font)
{
fenetre.clear(Color(fondCarte));
// calcul de la transformation affine - changement de rep�re : monde ---> �cran
Vecteur2D coinEcranBG(0,hauteur), coinEcranHD(largeur,0);
t = TransfoAffine2D::passageMondeEcran(coinBG,coinHD,coinEcranBG,coinEcranHD);
fenetre.setFramerateLimit(30);
}
/**
Dessine un sommet du graphe. Exemples :  nom, couleur, informations associ�es, etc.
renvoie true en cas de succ�s, false en cas d'�chec
On suppose que les coordonn�es du sommet sont d�finies par rapport au rep�re du monde
*/
template <class T>
bool dessine(const Sommet<T> * sommet) ;

/**
Dessine l'ar�te (d�but->fin) en utilisant la couleur "couleur"
renvoie true en cas de succ�s, false en cas d'�chec
On suppose que les coordonn�es des sommets sont d�finies par rapport au rep�re du monde
*/
template <class T>
bool dessine(const Sommet<T> * debut, const Sommet<T> * fin, unsigned int couleur);

/**
Dessine un ar�te du graphe. Exemples :  nom, couleur, informations associ�es, etc.
renvoie true en cas de succ�s, false en cas d'�chec
On suppose que les coordonn�es des sommets sont d�finies par rapport au rep�re du monde
*/
template <class S, class T>
bool dessine(const Arete<S,T> * arete) ;

bool dessine( GameElement * gameElement);
bool dessine( World * world);
};

bool FenetreGrapheSFML::dessine( GameElement * gameElement){
	
	gameElement->animate();
	Vecteur2D position = t.applique(gameElement->position->v.vSommet.p);
	Vecteur2D position1 = position -VSommet::rayonDisquePixels*Vecteur2D(1,1);
	Vector2f p1 =  vecteur2DToVector2f(position1);

	gameElement->sprite.setPosition(p1);
	
	fenetre.draw(gameElement->sprite);
	return true ;	
}
bool FenetreGrapheSFML::dessine( World * world){
	

	world->getLaby()->dessine(*this);
	dessine(world->getHero());
	vector<Ghost * >::const_iterator it ;
	for (it = world->getGhosts().begin() ; it != world->getGhosts().end(); it++ )
		{	
			dessine(*it);
			
		}


	return true ;	
}












// template <>
// bool FenetreGrapheSFML::dessine<VSommet>(const Sommet<VSommet> * sommet)
// { dessinePetitRond(this->fenetre,this->t, sommet->v, this->font);	// m�thode ordinaire. cf. d�but de ce fichier
// 	if( sommet->pacGomme ){
// 	TextureFactory usine ;
// 	sf::Texture texture = usine.getTextureCoin();
// 	sf::RectangleShape rect(sf::Vector2f(32,32));
// 	rect.setTexture(&texture);

// 	Vecteur2D position = t.applique(sommet->v.p);
// 	Vecteur2D position1 = position -VSommet::rayonDisquePixels*Vecteur2D(1,1);
// 	Vector2f p1 =  vecteur2DToVector2f(position1);

// 	rect.setPosition(p1);
// 	rect.setOrigin(16,16);
// 	fenetre.draw(rect);
// }
// return true;
// }

template <>
bool FenetreGrapheSFML::dessine<InfoSommet>(const Sommet<InfoSommet> * sommet)
{ dessinePetitRond(this->fenetre,this->t, sommet->v.vSommet, this->font);	// m�thode ordinaire. cf. d�but de ce fichier
	if( sommet->pacGomme ){
	TextureFactory usine ;
	sf::Texture texture = usine.getTextureCoin();
	sf::RectangleShape rect(sf::Vector2f(32,32));
	rect.setTexture(&texture);

	Vecteur2D position = t.applique(sommet->v.vSommet.p);
	Vecteur2D position1 = position -VSommet::rayonDisquePixels*Vecteur2D(1,1);
	Vector2f p1 =  vecteur2DToVector2f(position1);

	rect.setPosition(p1);
	rect.setOrigin(16,16);
	fenetre.draw(rect);
}
return true;
}


// template <>
// bool FenetreGrapheSFML::dessine<Peinture,VSommet>(const Arete<Peinture,VSommet> * arete)
// {
// 	   dessineSegment( this->fenetre, this->t,   arete->v.fond, arete->debut->v.p, arete->fin->v.p);
// return dessineSegment( this->fenetre, this->t, arete->v.devant, arete->debut->v.p, arete->fin->v.p);
// }

template <>
bool FenetreGrapheSFML::dessine<Peinture,InfoSommet>(const Arete<Peinture,InfoSommet> * arete)
{
	   dessineSegment( this->fenetre, this->t,   arete->v.fond, arete->debut->v.vSommet.p, arete->fin->v.vSommet.p);
return dessineSegment( this->fenetre, this->t, arete->v.devant, arete->debut->v.vSommet.p, arete->fin->v.vSommet.p);
}



#endif // FENETRE_H
