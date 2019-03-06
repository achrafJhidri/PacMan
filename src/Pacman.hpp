#pragma once
#include "DynamicGameElement.hpp"
#include "Ghost.hpp"

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
