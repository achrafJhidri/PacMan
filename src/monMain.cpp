#include "PElement.h"
#include "Erreur.h"

#include <SFML/Graphics.hpp>
#include "TransfoAffine2D.h"
#include "VSommet.h"
#include "Peinture.h"
#include "Graphe.h"
#include "FenetreGrapheSFML.h"
#include <string>
#include <vector>
#include "TextureFactory.h"

//#include "Ghost.hpp"
#include "Coin.hpp"
#include "Pacman.hpp"
#include "AnimatedSprite.hpp"
using namespace std;
using namespace sf;

int main() {

    string titre = "PacMan Demo" ;
    Font font;
    font.loadFromFile("src/Action Man Bold.ttf");
    FenetreGrapheSFML f(titre, 10000000,  Vecteur2D(0, 200),  Vecteur2D(500, 0), 760, 800,font);
    unsigned int magenta = Color::Magenta.toInteger();



    TextureFactory  usine;


#pragma region gestionGraphe
    Graphe<Peinture, VSommet> g1; // creation a vide
#pragma region créationSommet

    Sommet<VSommet> * s11 = g1.creeSommet(VSommet("11", Vecteur2D(20, 1), magenta));
    Sommet<VSommet> * s21 = g1.creeSommet(VSommet("21", Vecteur2D(60, 1), magenta));
    Sommet<VSommet> * s31 = g1.creeSommet(VSommet("31", Vecteur2D(100, 1), magenta));
    Sommet<VSommet> * s41 = g1.creeSommet(VSommet("41", Vecteur2D(140, 1), magenta));
    Sommet<VSommet> * s51 = g1.creeSommet(VSommet("51", Vecteur2D(180, 1), magenta));
	
    Sommet<VSommet> * s12 = g1.creeSommet(VSommet("12", Vecteur2D(20, 40), magenta));
    Sommet<VSommet> * s22 = g1.creeSommet(VSommet("22", Vecteur2D(60, 40), magenta));
    Sommet<VSommet> * s32 = g1.creeSommet(VSommet("32", Vecteur2D(100, 40), magenta));
    Sommet<VSommet> * s42 = g1.creeSommet(VSommet("42", Vecteur2D(140, 40), magenta));
	Sommet<VSommet> * s52 = g1.creeSommet(VSommet("52", Vecteur2D(180, 40), magenta));

	Sommet<VSommet> * s13 = g1.creeSommet(VSommet("13", Vecteur2D(20, 80), magenta));
    Sommet<VSommet> * s23 = g1.creeSommet(VSommet("23", Vecteur2D(60, 80), magenta));
    Sommet<VSommet> * s33 = g1.creeSommet(VSommet("33", Vecteur2D(100, 80), magenta));
    Sommet<VSommet> * s43 = g1.creeSommet(VSommet("43", Vecteur2D(140, 80), magenta));
	Sommet<VSommet> * s53 = g1.creeSommet(VSommet("53", Vecteur2D(180, 80), magenta));

    Sommet<VSommet> * s14 = g1.creeSommet(VSommet("14", Vecteur2D(20, 120), magenta));
    Sommet<VSommet> * s24 = g1.creeSommet(VSommet("24", Vecteur2D(60, 120), magenta));
    Sommet<VSommet> * s34 = g1.creeSommet(VSommet("34", Vecteur2D(100, 120), magenta));
    Sommet<VSommet> * s44 = g1.creeSommet(VSommet("44", Vecteur2D(140, 120), magenta));
	Sommet<VSommet> * s54 = g1.creeSommet(VSommet("54", Vecteur2D(180, 120), magenta));

    Sommet<VSommet> * s15 = g1.creeSommet(VSommet("15", Vecteur2D(20, 160), magenta));
    Sommet<VSommet> * s25 = g1.creeSommet(VSommet("25", Vecteur2D(60, 160), magenta));
    Sommet<VSommet> * s35 = g1.creeSommet(VSommet("35", Vecteur2D(100, 160), magenta));
    Sommet<VSommet> * s45 = g1.creeSommet(VSommet("45", Vecteur2D(140, 160), magenta));
	Sommet<VSommet> * s55 = g1.creeSommet(VSommet("55", Vecteur2D(180, 160), magenta));
#pragma endregion creeSommet
#pragma region créationAretes

	// ligne 1
	g1.creeArete(Peinture(222244444,1111111),s11,s21);
	g1.creeArete(Peinture(222244444,1111111),s21,s31);
	g1.creeArete(Peinture(222244444,1111111),s31,s41);
	g1.creeArete(Peinture(222244444,1111111),s41,s51);

	// Colone ligne 1 ligne 2
	g1.creeArete(Peinture(222244444,1111111),s11,s12);
	g1.creeArete(Peinture(222244444,1111111),s21,s22);
	g1.creeArete(Peinture(222244444,1111111),s31,s32);
	g1.creeArete(Peinture(222244444,1111111),s41,s42);
	g1.creeArete(Peinture(222244444,1111111),s51,s52);

	// DIAGONALE entre ligne 1 et 2
	g1.creeArete(Peinture(222244444,1111111),s11,s22);
	g1.creeArete(Peinture(222244444,1111111),s21,s32);
	g1.creeArete(Peinture(222244444,1111111),s41,s32);
	g1.creeArete(Peinture(222244444,1111111),s51,s42);

	// ligne 2
	g1.creeArete(Peinture(222244444,1111111),s12,s22);
	g1.creeArete(Peinture(222244444,1111111),s22,s32);
	g1.creeArete(Peinture(222244444,1111111),s32,s42);
	g1.creeArete(Peinture(222244444,1111111),s42,s52);

	// ligne 3
	g1.creeArete(Peinture(222244444,1111111),s13,s23);
	g1.creeArete(Peinture(222244444,1111111),s23,s33);
	g1.creeArete(Peinture(222244444,1111111),s33,s43);
	g1.creeArete(Peinture(222244444,1111111),s43,s53);

	// Colone ligne 2 ligne 3
	g1.creeArete(Peinture(222244444,1111111),s12,s13);
	g1.creeArete(Peinture(222244444,1111111),s22,s23);
	g1.creeArete(Peinture(222244444,1111111),s32,s33);
	g1.creeArete(Peinture(222244444,1111111),s42,s43);
	g1.creeArete(Peinture(222244444,1111111),s52,s53);

	// DIAGONALE entre ligne 2 et 3
	g1.creeArete(Peinture(222244444,1111111),s12,s23);
	g1.creeArete(Peinture(222244444,1111111),s22,s33);
	g1.creeArete(Peinture(222244444,1111111),s42,s33);
	g1.creeArete(Peinture(222244444,1111111),s52,s43);

	// ligne 4
	g1.creeArete(Peinture(222244444,1111111),s14,s24);
	g1.creeArete(Peinture(222244444,1111111),s24,s34);
	g1.creeArete(Peinture(222244444,1111111),s34,s44);
	g1.creeArete(Peinture(222244444,1111111),s44,s54);

	// Colone ligne 1 ligne 2
	g1.creeArete(Peinture(222244444,1111111),s13,s14);
	g1.creeArete(Peinture(222244444,1111111),s23,s24);
	g1.creeArete(Peinture(222244444,1111111),s33,s34);
	g1.creeArete(Peinture(222244444,1111111),s43,s44);
	g1.creeArete(Peinture(222244444,1111111),s53,s54);


	// DIAGONALE entre ligne 3 et 4
	g1.creeArete(Peinture(222244444,1111111),s14,s23);
	g1.creeArete(Peinture(222244444,1111111),s24,s33);
    g1.creeArete(Peinture(222244444,1111111),s44,s33);
	g1.creeArete(Peinture(222244444,1111111),s54,s43);


	// ligne 5
	g1.creeArete(Peinture(222244444,1111111),s15,s25);
	g1.creeArete(Peinture(222244444,1111111),s25,s35);
	g1.creeArete(Peinture(222244444,1111111),s35,s45);
	g1.creeArete(Peinture(222244444,1111111),s45,s55);


	 // Colone ligne 4 ligne 5
	g1.creeArete(Peinture(222244444,1111111),s14,s15);
	g1.creeArete(Peinture(222244444,1111111),s24,s25);
	g1.creeArete(Peinture(222244444,1111111),s34,s35);
	g1.creeArete(Peinture(222244444,1111111),s44,s45);
	g1.creeArete(Peinture(222244444,1111111),s54,s55);


	// DIAGONALE entre ligne 4 et 5
	g1.creeArete(Peinture(222244444,1111111),s15,s24);
	g1.creeArete(Peinture(222244444,1111111),s25,s34);
	g1.creeArete(Peinture(222244444,1111111),s45,s34);
	g1.creeArete(Peinture(222244444,1111111),s55,s44);

#pragma endregion créationAretes



RectangleShape  rectangle(Vector2f(16,16));
rectangle.setPosition(Vector2f(50,50));
rectangle.setTexture(&usine.getTexturePomme());




g1.majSommets() ;

Pacman p = Pacman(*s22,usine.getTexturePacman(),1,16,16,6);

//Coin c = Coin(*s14,usine.getTexturePomme());

#pragma endregion gestionGraphe
#pragma region FentetreMainLoop
    // Affichage de la fenetre
    while (f.fenetre.isOpen()) {
		
	// Traitement des evenements
        Event event;
        while (f.fenetre.pollEvent(event)) {
			
	    // Fermeture
            if (event.type == event.Closed)
                f.fenetre.close();

	    // Evenements clavier
            if (event.type == event.KeyPressed) {
                if (event.key.code == Keyboard::Up)
                {
					p.move(Orientation::NORTH );
                }
				if (event.key.code == Keyboard::Down)
                {
					p.move(Orientation::SOUTH );
                }
				if (event.key.code == Keyboard::Left)
                {
					p.move(Orientation::WEST );
                }
				if (event.key.code == Keyboard::Right)
                {
					p.move(Orientation::EAST );
                }
				if (event.key.code == Keyboard::E)
                {
					p.move(Orientation::NORTH_EAST );
                }
				if (event.key.code == Keyboard::A)
                {
					p.move(Orientation::NORTH_WEST );
                }
				if (event.key.code == Keyboard::C)
                {
					p.move(Orientation::SOUTH_EAST );
                }
				if (event.key.code == Keyboard::W)
                {
					p.move(Orientation::SOUTH_WEST );
                }
            }
        }
		
        // Affichage
        f.fenetre.clear();
		f.fenetre.draw(rectangle);
        g1.dessine(f);
		//c.dessine(f);
		p.dessine(f);
        f.fenetre.display();
    }
#pragma endregion FentetreMainLoop

    return EXIT_SUCCESS;
}

