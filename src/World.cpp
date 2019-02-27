#include "World.hpp"

DynamicGameElement const &World::getHero() {
    return this->hero;
}

DynamicGameElement* const &World::getGhosts() {
    return this->ghosts;
}
