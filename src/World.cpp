#include "World.hpp"

World::World() {}

DynamicGameElement const &World::getHero() {
    return *this->hero;
}

DynamicGameElement* const &World::getGhosts() {
    return this->ghosts;
}

World::~World() {
    delete ghosts ;
}
