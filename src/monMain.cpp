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

using namespace std;
using namespace sf;

int main() {
    string titre = "The Seven Kingdoms" ;
    Font font;
    font.loadFromFile("Action Man Bold.ttf");
    FenetreGrapheSFML f(titre, 10000000,  Vecteur2D(0, 200),  Vecteur2D(300, 0), 760, 800,font);
    unsigned int magenta = Color::Magenta.toInteger();
    
    Graphe<Peinture, VSommet> g1;    // crÃ©ation Ã  vide

    Sommet<VSommet> * s11, *s21, *s31, *s41, *s51;
    Sommet<VSommet> * s12, *s22, *s32, *s42, *s52;
    Sommet<VSommet> * s13, *s23, *s33, *s43, *s53;
    Sommet<VSommet> * s14, *s24, *s34, *s44, *s54;
    Sommet<VSommet> * s15, *s25, *s35, *s45, *s55;

    s12 = g1.creeSommet(VSommet("12", Vecteur2D(100, 250), magenta));
    s22 = g1.creeSommet(VSommet("22", Vecteur2D(250, 250), magenta));
    s32 = g1.creeSommet(VSommet("32", Vecteur2D(400, 250), magenta));
    s42 = g1.creeSommet(VSommet("42", Vecteur2D(550, 250), magenta));
    s52 = g1.creeSommet(VSommet("52", Vecteur2D(700, 250), magenta));


    s13 = g1.creeSommet(VSommet("13", Vecteur2D(100, 400), magenta));
    s23 = g1.creeSommet(VSommet("23", Vecteur2D(250, 400), magenta));
    s33 = g1.creeSommet(VSommet("33", Vecteur2D(400, 400), magenta));
    s43 = g1.creeSommet(VSommet("43", Vecteur2D(550, 400), magenta));
    s53 = g1.creeSommet(VSommet("53", Vecteur2D(700, 400), magenta));

    s14 = g1.creeSommet(VSommet("14", Vecteur2D(100, 550), magenta));
    s24 = g1.creeSommet(VSommet("24", Vecteur2D(250,550), magenta));
    s34 = g1.creeSommet(VSommet("34", Vecteur2D(400, 550), magenta));
    s44 = g1.creeSommet(VSommet("44", Vecteur2D(550, 550), magenta));
    s54 = g1.creeSommet(VSommet("54", Vecteur2D(700, 550), magenta));

    s15 = g1.creeSommet(VSommet("15", Vecteur2D(100, 700), magenta));
    s25 = g1.creeSommet(VSommet("25", Vecteur2D(250, 700), magenta));
    s35 = g1.creeSommet(VSommet("35", Vecteur2D(400, 700), magenta));
    s45 = g1.creeSommet(VSommet("45", Vecteur2D(550, 700), magenta));
    s55 = g1.creeSommet(VSommet("55", Vecteur2D(700, 700), magenta));



    //----------------- on connecte certains sommets -------------------

    Arete<Peinture, VSommet> * a1112, *a1213, *a1314, *a1415;
    Arete<Peinture, VSommet> * a2122, *a2223, *a2324, *a2425;
    Arete<Peinture, VSommet> * a3132, *a3233, *a3334, *a3435;
    Arete<Peinture, VSommet> * a4142, *a4243, *a4344, *a4445;
    Arete<Peinture, VSommet> * a5152, *a5253, *a5354, *a5455;



    a1112 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s11, s12);
    a1213 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s12, s13);
    a1314 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s13, s14);
    a1415 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s14, s15);

    a2122 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s21, s22);
    a2223 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s22, s23);
    a2324 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s23, s24);
    a2425 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s24, s25);

    a3132 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s31, s32);
    a3233 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s32, s33);
    a3334 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s33, s34);
    a3435 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s34, s35);


    a4142 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s41, s42);
    a4243 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s42, s43);
    a4344 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s43, s44);
    a4445 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s44, s45);


    a5152 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s51, s52);
    a5253 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s52, s53);
    a5354 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s53, s54);
    a5455 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s54, s55);


    Arete<Peinture, VSommet> * a1121, *a2131, *a3141, *a4151;
    Arete<Peinture, VSommet> * a1222, *a2232, *a3242, *a4252;
    Arete<Peinture, VSommet> * a1323, *a2333, *a3343, *a4353;
    Arete<Peinture, VSommet> * a1424, *a2434, *a3444, *a4454;
    Arete<Peinture, VSommet> * a1525, *a2535, *a3545, *a4555;

    a1121 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s11, s21);
    a2131 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s21, s31);
    a3141= g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s31, s41);
    a4151 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s41, s51);

    a1222 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s12, s22);
    a2232 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s22, s32);
    a3242 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s32, s42);
    a4252 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s42, s52);



    a1323 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s13, s23);
    a2333 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s23, s33);
    a3343 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s33, s43);
    a4353 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s43, s53);

    a1424 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s14, s24);
    a2434 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s24, s34);
    a3444 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s34, s44);
    a4454 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s44, s54);

    a1525 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s15, s25);
    a2535 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s25, s35);
    a3545 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s35, s45);
    a4555 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s45, s55);

    
    Arete<Peinture, VSommet> * a1122, *a1223, *a1423, *a1524;
    Arete<Peinture, VSommet> * a2132, *a2233, *a2433, *a2534;
    Arete<Peinture, VSommet> * a3241, *a3342, *a3344, *a3445;
    Arete<Peinture, VSommet> * a4251, *a4352, *a4354, *a4455;
    
    a1122 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s11, s22);
    a1223 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s12, s23);
    a1423 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s14, s23);
    a1524 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s15, s24);

    a2132= g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s21, s32);
    a2233 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s22, s33);
    a2433 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s24, s33);
    a2534 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s25, s34);

    a3241 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s32, s41);
    a3342 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s33, s42);
    a3344 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s33, s44);
    a3445 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s34, s45);

    a4251 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s42, s51);
    a4352 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s43, s52);
    a4354 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s43, s54);
    a4455 = g1.creeArete(Peinture(Color::Blue.toInteger(), Color::Red.toInteger()), s44, s55);

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
        f.fenetre.display();
    }

    return EXIT_SUCCESS;
}
