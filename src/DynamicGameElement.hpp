#pragma once
#include "GameElement.hpp"
#include "PElement.h"

#include <functional>

using namespace sf ;
class DynamicGameElement : public GameElement
{
private:
    double speed;
public:

    DynamicGameElement( Sommet<VSommet> *, const sf::Texture &, double speed,int largeur,int hauteur,int nbTextures);
    virtual ~DynamicGameElement();

    double getSpeed() const;
    void setSpeed(double);

    virtual void move( Orientation orientation );
};
