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

#include "Ghost.hpp"
#include "Coin.hpp"
#include "Pacman.hpp"
#include "AnimatedSprite.hpp"
#include "Orientation.hpp"

#include <functional>
#include <stdlib.h>     /* srand, rand */
#include <time.h>   

#include "InfoSommet.h"
#include "InfoArete.h"
#include "InfoArete.h"


using namespace std;
using namespace sf;

#define GRAPH_W 5
#define GRAPH_H 5
#define GRAPH_SPACE_W 40
#define GRAPH_SPACE_H GRAPH_SPACE_W

int main() {
    srand(time(NULL));
    string titre = "PacMan Demo" ;
    Font font;
    font.loadFromFile("src/Action Man Bold.ttf");
    FenetreGrapheSFML f(titre, 99999999,  Vecteur2D(0, 200),  Vecteur2D(500, 0), 760, 800,font);
    unsigned int magenta = Color::Black.toInteger();
    TextureFactory  usine;

    
    

    Graphe<Peinture, InfoSommet> g1;
    Sommet<InfoSommet> *graphMatrix[GRAPH_H][GRAPH_W];
    for (int i = 0; i < GRAPH_H; ++i) {
	for (int j = 0; j < GRAPH_W; ++j) {
	    std::stringstream s;
	    int a = GRAPH_SPACE_W * (j + 1), b = GRAPH_SPACE_H * (i + 1);
	    s << i << j;
	    graphMatrix[i][j] = g1.creeSommet(InfoSommet(VSommet(s.str(), Vecteur2D(a, b), magenta),InfoAStar()));
	}
    }
   
    // Fill map
    Peinture paint(222244444,1111111);
    int i_offset, j_offset;
    for (int i = 0; i < GRAPH_H; ++i) {
	for (int j = 0; j < GRAPH_W; ++j) {
	    // Create horizontal vertex
	    if (j < GRAPH_H - 1) {
		g1.creeArete(paint, graphMatrix[i][j], graphMatrix[i][j + 1]);
	    }
	    // Create vertical vertex
	    if (i < GRAPH_W - 1) {
		g1.creeArete(paint, graphMatrix[i][j], graphMatrix[i + 1][j]);
            }
	    // Diagonals
            if (i != (GRAPH_H - 1) / 2.f && j != (GRAPH_W - 1) / 2.f) {
		i_offset = (i <= GRAPH_H / 2) ? +1 : -1;
		j_offset = (j <= GRAPH_W / 2) ? +1 : -1;
		g1.creeArete(paint, graphMatrix[i][j], graphMatrix[i + i_offset][j + j_offset]);
            }
        }
    }
    g1.majSommets();



    Pacman pacman = Pacman(graphMatrix[1][1],usine.getTexturePacman(),1,32,32,6);
    Ghost ghost = Ghost(graphMatrix[3][3],usine.getTextureRedFantome(),1,true,32,32,1);
    Coin coin = Coin(graphMatrix[3][0],usine.getTextureCoin());

    // Main loop
    while (f.fenetre.isOpen()) {
        Event event;
        while (f.fenetre.pollEvent(event)) {
            switch (event.type) {
                default: break;
                case event.Closed:
                f.fenetre.close(); break;
                case event.KeyPressed:
                ghost.move();
                #define C(a) case Keyboard::a:
                #define K(a) { pacman.move(Orientation::a); break; }
                            switch (event.key.code) {
                                C(Up); C(Z); K(NORTH);
                                C(Down); C(X); K(SOUTH);
                                C(Left); C(Q); K(WEST);
                                C(Right); C(D); K(EAST);

                                C(E); K(NORTH_EAST);
                                C(A); K(NORTH_WEST);
                                C(W); K(SOUTH_WEST);
                                C(C); K(SOUTH_EAST);
                            default:
                                break;
                            }
                #undef C
                #undef K
            }
        }
		
        // Affichage
        f.fenetre.clear();
        g1.dessine(f);
	    coin.dessine(f);
	    pacman.dessine(f);
	    ghost.dessine(f);
        f.fenetre.display();
    }













    return EXIT_SUCCESS;
}

