#pragma once

#include "StaticGameElement.hpp"

class Coin : public StaticGameElement
{
private:
    static const sf::Texture texture;
public:
    Coin(const Sommet<VSommet> &, const sf::Texture & = texture, int = 1);
    virtual ~Coin();
};
