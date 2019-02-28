#include "Coin.hpp"

// FIXME
const sf::Texture Coin::texture = *new sf::Texture;

Coin::Coin(const Sommet<VSommet> &sommet, const sf::Texture &texture, int value)
    : StaticGameElement(sommet, texture, value)
{}

Coin::~Coin() {}
