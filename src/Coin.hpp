#pragma once

#include "Sommet.h"
#include "InfoSommet.h"
#include "StaticGameElement.hpp"

class Coin : public StaticGameElement
{
private:
  
public:

    Coin( Sommet<InfoSommet> *, const sf::Texture & , int p=1,int largeur=16,int hauteur=16,int nbTextures=1);
    virtual ~Coin();
};
