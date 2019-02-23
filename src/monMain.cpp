#include "PElement.h"
#include "Erreur.h"

#include <SFML/Graphics.hpp>
#include "TransfoAffine2D.h"
#include "VSommet.h"
#include "Peinture.h"
#include "Graphe.h"
#include "FenetreGrapheSFML.h"
#include <string>

using namespace std;
using namespace sf;




int main() {



	 string  titre = "The Seven Kingdoms" ;
	Font font;
	font.loadFromFile("Action Man Bold.ttf");
	FenetreGrapheSFML f(titre, 10000000,  Vecteur2D(0, 200),  Vecteur2D(300, 0), 760, 800,font);
	unsigned int magenta = Color::Magenta.toInteger();
	
	Graphe<Peinture, VSommet> g1;	// création à vide

	Sommet<VSommet> * s0, *s1, *s2, *s3, *s4;





s0 = g1.creeSommet(VSommet("Kings Landing",Vecteur2D(100,700),magenta));
s1 = g1.creeSommet(VSommet("Winterfell",Vecteur2D(100,200),magenta));
s2 = g1.creeSommet(VSommet("DragonStone",Vecteur2D(400,400),magenta));
s3 = g1.creeSommet(VSommet("The wall",Vecteur2D(300,100),magenta));
s4 = g1.creeSommet(VSommet("Volantis",Vecteur2D(500,600),magenta));


	//----------------- on connecte certains sommets -------------------

	Arete<Peinture, VSommet> * a0, *a1, *a2, *a3, *a4;

	unsigned int jaune0 = 0xDFFF00FF;   // jaune opaque
	unsigned int jaune1 = 0xDFFF00C0;   // jaune presque opaque
	unsigned int jaune2 = 0xDFFF0064;   // jaune un peu transparent
	unsigned int jaune3 = 0xDFFF0020;	// jaune presque transparent

	unsigned int tangerine0 = 0xFF7F00FF; // tangerine opaque
	unsigned int tangerine1 = 0xFF7F00DF; // tangerine presque opaque
	unsigned int tangerine2 = 0xFF7F00BF; // tangerine un peu transparent
	unsigned int tangerine3 = 0xFF7F0060; // tangerine presque transparent
	unsigned int tangerine4 = 0xFF7F0000; // tangerine  transparent


	//unsigned int jauneOpaque

	unsigned int turquoise = 0x00CED1FF;	// couleur turquoise opaque. préfixe 0x pour héxadécimal. format RGBA
	unsigned int vertCitron = 0x00FF00FF;


	a0 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s2, s1);
	a1 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s3, s2);
	a2 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s1, s3);
	a3 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s0, s1);
	a4 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s0, s4);

		

	while (f.fenetre.isOpen()) {
		
		Event event;
		while (f.fenetre.pollEvent(event)) {
			if (event.type == event.Closed)
				f.fenetre.close();

			if (event.type == event.KeyPressed) {
				if (event.key.code == Keyboard::Up)
				{
					PElement <Arete<Peinture, VSommet>> * lA;

					for (lA = g1.lAretes; lA; lA = lA->s) {
					
							lA->v->v.devant -= 50;
					}


				}

			}
		}


		g1.dessine(f);
		
		f.fenetre.display();

	}



	Graphe<Peinture, VSommet> graphePacMan;	// création à vide

	Sommet<VSommet> * s11, *s21, *s31, *s41, *s51;
	Sommet<VSommet> * s12, *s22, *s32, *s42, *s52;
	Sommet<VSommet> * s13, *s23, *s33, *s43, *s53;
	Sommet<VSommet> * s14, *s24, *s34, *s44, *s54;
	Sommet<VSommet> * s15, *s25, *s35, *s45, *s55;


	s11 = g1.creeSommet(VSommet("11", Vecteur2D(20, 20), magenta));
	s21 = g1.creeSommet(VSommet("21", Vecteur2D(40, 20), magenta));
	s31 = g1.creeSommet(VSommet("31", Vecteur2D(50, 20), magenta));
	s41 = g1.creeSommet(VSommet("41", Vecteur2D(60, 20), magenta));
	s51 = g1.creeSommet(VSommet("51", Vecteur2D(80, 20), magenta));






}