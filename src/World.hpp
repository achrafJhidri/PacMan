#pragma once

#include "DynamicGameElement.hpp"
#include "Graphe.h"
#include <vector>
#include "Pacman.hpp"
#include "Ghost.hpp"
#include "Peinture.h"
#include "InfoSommet.h"
class World
{
private:
    
    Pacman * hero; 
    vector<Ghost *> ghosts ;
    Graphe <Peinture,InfoSommet> * laby;
    
public:
    World( Pacman * pacman,const vector<Ghost *> & ghosts ,   Graphe<Peinture,InfoSommet> * graphe );
    virtual ~World();

     Pacman *  getHero() const ;
    const vector<Ghost * > & getGhosts() const  ; 
     Graphe< Peinture,InfoSommet> * getLaby() const ;


    template <class FENETRE>
    bool dessine(FENETRE & fenetre)  ;


    void moveGhosts()const;
    void checkCollision()const;
};

template <class FENETRE>
bool World::dessine(FENETRE & fenetre){
    fenetre.dessine(this);
    return true ;
}