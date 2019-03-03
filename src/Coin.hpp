#pragma once

#include "StaticGameElement.hpp"


class Coin : public StaticGameElement
{
private:
  // /* static const*/ sf::Texture texture;
public:

    Coin(const Sommet<VSommet> &, const sf::Texture & , int p=1,int largeur=16,int hauteur=16,int nbTextures=1);
    virtual ~Coin();
};
