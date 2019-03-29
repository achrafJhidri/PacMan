#pragma once
#include "GameElement.hpp"

class StaticGameElement : public GameElement
{
private:
    int points; // Points gagnés lors de l'absorption de l'élément
    
public:

    StaticGameElement( Sommet<InfoSommet> *, const sf::Texture &, int p,int largeur,int hauteur,int nbTextures);
    virtual ~StaticGameElement();

    int getPoints() const;
};
