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
#include <stdlib.h>     
#include <time.h>   

#include "InfoSommet.h"
#include "InfoArete.h"
#include "World.hpp"
#include <vector>
#include "OutilsCarte.h"


using namespace std;
using namespace sf;

#define GRAPH_W 7
#define GRAPH_H 7
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

    Graphe<InfoArete, InfoSommet>   g1 = Graphe <InfoArete,InfoSommet>() ;
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
    InfoArete info(10);
    int i_offset, j_offset;
    for (int i = 0; i < GRAPH_H; ++i) {
	for (int j = 0; j < GRAPH_W; ++j) {
	    // Create horizontal vertex
	    if (j < GRAPH_H - 1) {
		//g1->creeArete(info, graphMatrix[i][j], graphMatrix[i][j + 1]);
        OutilsCarte::creeArete( graphMatrix[i][j], graphMatrix[i][j + 1], g1);
	    }
	    // Create vertical vertex
	    if (i < GRAPH_W - 1) {
		//g1->creeArete(info, graphMatrix[i][j], graphMatrix[i + 1][j]);
        OutilsCarte::creeArete( graphMatrix[i][j], graphMatrix[i + 1][j], g1);
            }
	    // Diagonals
            if (i != (GRAPH_H - 1) / 2.f && j != (GRAPH_W - 1) / 2.f) {
		i_offset = (i <= GRAPH_H / 2) ? +1 : -1;
		j_offset = (j <= GRAPH_W / 2) ? +1 : -1;
		//g1->creeArete(info, graphMatrix[i][j], graphMatrix[i + i_offset][j + j_offset]);
         OutilsCarte::creeArete( graphMatrix[i][j], graphMatrix[i + i_offset][j + j_offset], g1);
        
            }
        }
    }
    g1.majSommets();


    
    Pacman  * pacman =  new Pacman(graphMatrix[1][1],usine.getTexturePacman(),1,32,32,6);
    Ghost * ghost =  new Ghost(graphMatrix[4][0],usine.getTextureRedFantome(),1,true,32,32,1);
    Ghost * ghost1 =  new Ghost(graphMatrix[4][4],usine.getTextureBlueFantome(),1,true,32,32,1);
    Ghost * ghost2 = new  Ghost(graphMatrix[0][4],usine.getTextureYellowFantome(),1,true,32,32,1);
    vector<Ghost *> v ;
    v.push_back(ghost);
    // v.push_back(ghost1);
    // v.push_back(ghost2);
    World world(pacman,v,&g1);


    // Main loop
    int gameLevel = 1;
    while (f.fenetre.isOpen() && pacman->estVivant() && gameLevel <= 3){
        Event event;
        while (f.fenetre.pollEvent(event)) {
            switch (event.type) {
                default: break;
                case event.Closed:
                f.fenetre.close(); break;
                case event.KeyPressed:
                #define C(a) case Keyboard::a:
                #define K(a) { pacman->move(Orientation::a); break; }
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
		    // Update level if necessary
		    if (pacman->getNbPieceGagnee() == GRAPH_H * GRAPH_W) {
			if (gameLevel < 3) {
			    gameLevel++;
			    world.resetContent();
			    std::cout << "level up!" << std::endl;
			} else {
			    std::cout << "hey good job" << std::endl;
			    // return; // logic moved to while loop condition
			}
		    }
		    // Animate world
		    world.moveGhosts(gameLevel);
		    world.checkCollision();
                #undef C
                #undef K
            }
        }
		
        // Affichage
        f.fenetre.clear();
        world.dessine(f);
        f.fenetre.display();
    }

    return EXIT_SUCCESS;
}
