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
using namespace std;
using namespace sf;

int main() {

    string titre = "The Seven Kingdoms" ;
    Font font;
    font.loadFromFile("Action Man Bold.ttf");
    FenetreGrapheSFML f(titre, 10000000,  Vecteur2D(0, 200),  Vecteur2D(300, 0), 760, 800,font);
    unsigned int magenta = Color::Magenta.toInteger();

    TextureFactory  usine;
	
    Sprite sprite ;
    sprite.setTexture(usine.getTextureFantome());

#pragma region gestionGraphe
    Graphe<Peinture, VSommet> g1; // creation a vide
#pragma region créationSommet
    Sommet<VSommet> * s11, *s21, *s31, *s41, *s51;
    Sommet<VSommet> * s12, *s22, *s32, *s42, *s52;
    Sommet<VSommet> * s13, *s23, *s33, *s43, *s53;
    Sommet<VSommet> * s14, *s24, *s34, *s44, *s54;
    Sommet<VSommet> * s15, *s25, *s35, *s45, *s55;

    s11 = g1.creeSommet(VSommet("11", Vecteur2D(20, 1), magenta));
    s21 = g1.creeSommet(VSommet("21", Vecteur2D(60, 1), magenta));
    s31 = g1.creeSommet(VSommet("31", Vecteur2D(100, 1), magenta));
    s41 = g1.creeSommet(VSommet("41", Vecteur2D(140, 1), magenta));
    s51 = g1.creeSommet(VSommet("51", Vecteur2D(180, 1), magenta));
	
    s12 = g1.creeSommet(VSommet("12", Vecteur2D(20, 40), magenta));
    s22 = g1.creeSommet(VSommet("22", Vecteur2D(60, 40), magenta));
    s32 = g1.creeSommet(VSommet("32", Vecteur2D(100, 40), magenta));
    s42 = g1.creeSommet(VSommet("42", Vecteur2D(140, 40), magenta));
	s52 = g1.creeSommet(VSommet("52", Vecteur2D(180, 40), magenta));

	s13 = g1.creeSommet(VSommet("12", Vecteur2D(20, 80), magenta));
    s23 = g1.creeSommet(VSommet("22", Vecteur2D(60, 80), magenta));
    s33 = g1.creeSommet(VSommet("32", Vecteur2D(100, 80), magenta));
    s43 = g1.creeSommet(VSommet("42", Vecteur2D(140, 80), magenta));
	s53 = g1.creeSommet(VSommet("52", Vecteur2D(180, 80), magenta));

    s14 = g1.creeSommet(VSommet("12", Vecteur2D(20, 120), magenta));
    s24 = g1.creeSommet(VSommet("22", Vecteur2D(60, 120), magenta));
    s34 = g1.creeSommet(VSommet("32", Vecteur2D(100, 120), magenta));
    s44 = g1.creeSommet(VSommet("42", Vecteur2D(140, 120), magenta));
	s54 = g1.creeSommet(VSommet("52", Vecteur2D(180, 120), magenta));

    s15 = g1.creeSommet(VSommet("12", Vecteur2D(20, 160), magenta));
    s25 = g1.creeSommet(VSommet("22", Vecteur2D(60, 160), magenta));
    s35 = g1.creeSommet(VSommet("32", Vecteur2D(100, 160), magenta));
    s45 = g1.creeSommet(VSommet("42", Vecteur2D(140, 160), magenta));
	s55 = g1.creeSommet(VSommet("52", Vecteur2D(180, 160), magenta));
#pragma endregion creeSommet
#pragma region créationAretes

	Arete< Peinture, VSommet > * a1121,* a2131,*a3141 ,* a4151; // ligne 1
	a1121 = g1.creeArete(Peinture(222244444,1111111),s11,s21);
	a2131 = g1.creeArete(Peinture(222244444,1111111),s21,s31);
	a3141 = g1.creeArete(Peinture(222244444,1111111),s31,s41);
	a4151 = g1.creeArete(Peinture(222244444,1111111),s41,s51);

	Arete< Peinture, VSommet > * a1112,* a2122,*a3132, *a4142,*a5152;  // Colone ligne 1 ligne 2
	a1112 = g1.creeArete(Peinture(222244444,1111111),s11,s12);
	a2122 = g1.creeArete(Peinture(222244444,1111111),s21,s22);
	a3132 = g1.creeArete(Peinture(222244444,1111111),s31,s32);
	a4142 = g1.creeArete(Peinture(222244444,1111111),s41,s42);
	a5152 =  g1.creeArete(Peinture(222244444,1111111),s51,s52);

	Arete< Peinture, VSommet > * a1122,*a2132,*a4132,*a5142; // DIAGONALE entre ligne 1 et 2
	a1122 = g1.creeArete(Peinture(222244444,1111111),s11,s22);
	a2132 = g1.creeArete(Peinture(222244444,1111111),s21,s32);
	a4132 = g1.creeArete(Peinture(222244444,1111111),s41,s32);
	a5142 = g1.creeArete(Peinture(222244444,1111111),s51,s42);

	Arete< Peinture, VSommet > * a1222,* a2232,*a3242 ,* a4252; // ligne 2
	a1222 = g1.creeArete(Peinture(222244444,1111111),s12,s22);
	a2232 =	g1.creeArete(Peinture(222244444,1111111),s22,s32);
	a3242 =	g1.creeArete(Peinture(222244444,1111111),s32,s42);
	a4252 =	g1.creeArete(Peinture(222244444,1111111),s42,s52);

	Arete< Peinture, VSommet > * a1323,* a2333,*a3343 ,* a4353; // ligne 3
	a1323 = g1.creeArete(Peinture(222244444,1111111),s13,s23);
	a2333 = g1.creeArete(Peinture(222244444,1111111),s23,s33);
	a3343 = g1.creeArete(Peinture(222244444,1111111),s33,s43);
	a4353 = g1.creeArete(Peinture(222244444,1111111),s43,s53);

	Arete< Peinture, VSommet > * a1213,* a2223,*a3233, *a4243,*a5253;  // Colone ligne 2 ligne 3
	a1213 = g1.creeArete(Peinture(222244444,1111111),s12,s13);
	a2223 = g1.creeArete(Peinture(222244444,1111111),s22,s23);
	a3233 = g1.creeArete(Peinture(222244444,1111111),s32,s33);
	a4243 = g1.creeArete(Peinture(222244444,1111111),s42,s43);
	a5253 =  g1.creeArete(Peinture(222244444,1111111),s52,s53);

	Arete< Peinture, VSommet > * a1223,*a2233,*a4233,*a5243; // DIAGONALE entre ligne 2 et 3
	a1223 = g1.creeArete(Peinture(222244444,1111111),s12,s23);
	a2233 = g1.creeArete(Peinture(222244444,1111111),s22,s33);
	a4233 = g1.creeArete(Peinture(222244444,1111111),s42,s33);
	a5243 = g1.creeArete(Peinture(222244444,1111111),s52,s43);

	Arete< Peinture, VSommet > * a1424,* a2434,*a3444 ,* a4454; // ligne 4
	a1424 = g1.creeArete(Peinture(222244444,1111111),s14,s24);
	a2434 =	g1.creeArete(Peinture(222244444,1111111),s24,s34);
	a3444 =	g1.creeArete(Peinture(222244444,1111111),s34,s44);
	a4454 =	g1.creeArete(Peinture(222244444,1111111),s44,s54);

	Arete< Peinture, VSommet > * a1314,* a2324,*a3334, *a4344,*a5354;  // Colone ligne 1 ligne 2
	a1314 = g1.creeArete(Peinture(222244444,1111111),s13,s14);
	a2324 = g1.creeArete(Peinture(222244444,1111111),s23,s24);
	a3334 = g1.creeArete(Peinture(222244444,1111111),s33,s34);
	a4344 = g1.creeArete(Peinture(222244444,1111111),s43,s44);
	a5354 =  g1.creeArete(Peinture(222244444,1111111),s53,s54);


	Arete< Peinture, VSommet > * a1423,*a2433,*a4433,*a5443; // DIAGONALE entre ligne 3 et 4
	a1423 = g1.creeArete(Peinture(222244444,1111111),s14,s23);
	a2433 = g1.creeArete(Peinture(222244444,1111111),s24,s33);
	a4433 = g1.creeArete(Peinture(222244444,1111111),s44,s33);
	a5443 = g1.creeArete(Peinture(222244444,1111111),s54,s43);


	Arete< Peinture, VSommet > * a1525,* a2535,*a3545 ,* a4555; // ligne 5
	a1525 = g1.creeArete(Peinture(222244444,1111111),s15,s25);
	a2535 = g1.creeArete(Peinture(222244444,1111111),s25,s35);
	a3545 = g1.creeArete(Peinture(222244444,1111111),s35,s45);
	a4555 = g1.creeArete(Peinture(222244444,1111111),s45,s55);


	Arete< Peinture, VSommet > * a1415,* a2425,*a3435, *a4445,*a5455;  // Colone ligne 4 ligne 5
	a1415 = g1.creeArete(Peinture(222244444,1111111),s14,s15);
	a2425 = g1.creeArete(Peinture(222244444,1111111),s24,s25);
	a3435 = g1.creeArete(Peinture(222244444,1111111),s34,s35);
	a4445 = g1.creeArete(Peinture(222244444,1111111),s44,s45);
	a5455 =  g1.creeArete(Peinture(222244444,1111111),s54,s55);


	Arete< Peinture, VSommet > * a1524,*a2534,*a4534,*a5544; // DIAGONALE entre ligne 1 et 2
	a1524 = g1.creeArete(Peinture(222244444,1111111),s15,s24);
	a2534 = g1.creeArete(Peinture(222244444,1111111),s25,s34);
	a4534 = g1.creeArete(Peinture(222244444,1111111),s45,s34);
	a5544 = g1.creeArete(Peinture(222244444,1111111),s55,s44);

#pragma endregion créationAretes
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
                    PElement <Arete<Peinture, VSommet>> * lA;
                    for (lA = g1.lAretes; lA; lA = lA->s) lA->v->v.devant -= 50;
                }
            }
        }

        // Affichage
        f.fenetre.clear();
        g1.dessine(f);
	f.fenetre.draw(sprite);
        f.fenetre.display();
    }
#pragma endregion FentetreMainLoop

    return EXIT_SUCCESS;
}

