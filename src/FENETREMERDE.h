#pragma once
#include <SFML/graphics.hpp>
#include "Sommet.h"
#include "Arete.h"
#include "TransfoAffine2D.h"
#include "VSommet.h"
#include "Peinture.h"

/**
Prend en charge le dessin d'un graphe
Prend en charge le passage de coordonn�es monde ---> �cran
*/
using namespace sf ;
using namespace std ;
class FenetreGrapheSFML
{
public:
	RenderWindow fenetre;
	const Font & font;


	TransfoAffine2D t;	// r�alise le passage fen�tre-cl�ture
					// (ou encore monde vers �cran)

	/**
	Cr�e la fen�tre qui va contenir le dessin du graphe.

	DONNEES : titre : titre de la fen�tre
			 fondCarte : couleur du fond de la sc�ne au format RGBA
			  coinBG : coin Bas Gauche de la sc�ne en coordonn�es monde
			  coinHD : coin Haut Droit de la sc�ne en coordonn�es monde
			  largeur : largeur de la fen�tre �cran (en pixels)
			  hauteur : hauteur de la fen�tre �cran (en pixels)
			  font : police � utiliser pour les annotations sur les sommets

	*/
	FenetreGrapheSFML(const string & titre,
		const unsigned int fondCarte,
		const Vecteur2D & coinBG,
		const Vecteur2D & coinHD,
		const int largeur,
		const int hauteur,
		const Font & font) :
		fenetre(sf::VideoMode(largeur, hauteur), titre), font(font)
	{
		fenetre.clear(Color(fondCarte));
		// calcul de la transformation affine - changement de rep�re : monde ---> �cran
		Vecteur2D coinEcranBG(0, hauteur), coinEcranHD(largeur, 0);

		t = TransfoAffine2D::passageMondeEcran(coinBG, coinHD,
			coinEcranBG, coinEcranHD);
	}
	/**
	Dessine un sommet du graphe. Exemples :  nom, couleur, informations associ�es, etc.
	renvoie true en cas de succ�s, false en cas d'�chec
	On suppose que les coordonn�es du sommet sont d�finies par rapport au rep�re du monde
	*/
	template <class T>
	bool dessine(const Sommet<T> * sommet);

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
	bool dessine(const Arete<S, T> * arete);

};
template <>
bool FenetreGrapheSFML::dessine<VSommet>(const Sommet<VSommet> * sommet)
{
	CircleShape s(sommet->v.rayonDisquePixels);
	s.setFillColor(Color(sommet->v.couleurBord));
	s.setPosition(Vector2f(sommet->v.p.x, sommet->v.p.y));

	Text t(sommet->v.nom,font,16);
	t.setPosition(Vector2f(sommet->v.p.x+ sommet->v.rayonDisquePixels, sommet->v.p.y+ sommet->v.rayonDisquePixels));
	fenetre.draw(s);
	fenetre.draw(t);


	return true ;
}
template <>
bool FenetreGrapheSFML::dessine<VSommet>(const Sommet<VSommet> * debut, const Sommet<VSommet> * fin, unsigned int couleur) {

	Vertex v(sf::Vector2f(fin->v.p.x + fin->v.rayonDisquePixels, fin->v.p.y + fin->v.rayonDisquePixels));
	Vertex v2(sf::Vector2f(debut->v.p.x + debut->v.rayonDisquePixels, debut->v.p.y + debut->v.rayonDisquePixels));

	v.color = Color(couleur);
	v2.color = Color(couleur);


	Vertex line[] = { v,v2 };
	
	fenetre.draw(line, 2, Lines);

	
	
	return true;
}



template <>
bool FenetreGrapheSFML::dessine<Peinture, VSommet>(const Arete<Peinture, VSommet> * arete)
{
	dessine(arete->debut, arete->fin, arete->v.fond);
	dessine(arete->debut, arete->fin, arete->v.devant);
	dessine(arete->debut);
	
	dessine(arete->fin);



	return true ;
}

