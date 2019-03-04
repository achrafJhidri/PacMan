#include "Coin.hpp"


Coin::Coin(const Sommet<VSommet> &sommet, const sf::Texture &texture, int value,int largeur,int hauteur,int nbTextures)
    : StaticGameElement(sommet, texture, value,largeur,hauteur,nbTextures)
{}

Coin::~Coin() {}
