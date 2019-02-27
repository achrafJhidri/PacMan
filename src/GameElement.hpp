#pragma once 
#include "Vecteur2D.h"
#include "VSommet.h"
#include "Sommet.h"

#include <SFML/Graphics.hpp>


class GameElement
{
private:
    Sommet<VSommet> position;
    sf::Texture texture;

public:
    GameElement(const Sommet<VSommet> &position, const sf::Texture &texture)
	: position(position), texture(texture)
    {};

    ~GameElement();


    double getX() const;
    double getY() const;
};
