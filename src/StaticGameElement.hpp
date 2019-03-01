#pragma once
#include "GameElement.hpp"

class StaticGameElement : public GameElement
{
private:
    int points; // Points gagnés lors de l'absorption de l'élément
    
public:
    StaticGameElement(const Sommet<VSommet> &, const sf::Texture &, int = 1);
    virtual ~StaticGameElement();

    int getPoints() const;
};