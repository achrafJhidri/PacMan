#pragma once

#include "DynamicGameElement.hpp"
#include "Graphe.h"
#include <vector>
#include "Pacman.hpp"
#include "Ghost.hpp"
#include "Peinture.h"
#include "InfoSommet.h"
#include "InfoArete.h"
#include "AstarT.h"
#include "OutilsCarte.h"
class World
{
private:
    
    Pacman * hero; 
    vector<Ghost *> ghosts ;
    Graphe <InfoArete,InfoSommet> * laby;
    
public:
    World( Pacman * pacman,const vector<Ghost *> & ghosts ,   Graphe<InfoArete,InfoSommet> * graphe );
    virtual ~World();

     Pacman *  getHero() const ;
    const vector<Ghost * > & getGhosts() const  ; 
     Graphe< InfoArete,InfoSommet> * getLaby() const ;


    template <class FENETRE>
    bool dessine(FENETRE & fenetre)  ;


    void moveGhosts(int niveau)const;
    void checkCollision()const;

    void resetContent();
};

template <class FENETRE>
bool World::dessine(FENETRE & fenetre){
    fenetre.dessine(this);
    return true ;
}
