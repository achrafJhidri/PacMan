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
