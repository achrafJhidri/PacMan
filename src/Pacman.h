#pragma once
#include "DynamicGameElement.h"
#include "Ghost.h"

class Pacman : public DynamicGameElement
{
private:
    
public:
    int nbPieceGagnee;
    Pacman( Sommet<InfoSommet> *, const sf::Texture &, double ,int largeur,int hauteur,int nbTextures);
    virtual ~Pacman();

    void move( Orientation orientation );
    void check(const Ghost * ghost);
};
