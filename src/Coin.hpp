#pragma once

#include "StaticGameElement.hpp"


class Coin : public StaticGameElement
{
private:
  
public:

    Coin(const Sommet<VSommet> &, const sf::Texture & , int p=1,int largeur=16,int hauteur=16,int nbTextures=1);
    virtual ~Coin();
};
