#pragma once

#include "DynamicGameElement.hpp"

class World
{
private:
    DynamicGameElement hero;
    DynamicGameElement *ghosts;

public:
    World();
    virtual ~World();

    DynamicGameElement const& getHero();
    DynamicGameElement* const& getGhosts();
};
