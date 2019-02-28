#pragma once

#include "DynamicGameElement.hpp"
#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"
#include "VSommet.h"

class World
{
private:
    // type PacMan ou Dynamic.... ? 
    DynamicGameElement *hero; 
    DynamicGameElement *ghosts;
    // graphe <S,T>
    
public:
    World();
    virtual ~World();

    DynamicGameElement const& getHero();
    DynamicGameElement* const& getGhosts();
};
