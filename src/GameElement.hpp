#pragma once 
#include "Vecteur2D.h"
#include "VSommet.h"
#include "Sommet.h"

#include <SFML/Graphics.hpp>

enum class Orientation {
    // Basic
    NORTH, SOUTH, EAST, WEST,
    // Composed
    NORTH_EAST, NORTH_WEST,
    SOUTH_EAST, SOUTH_WEST
};

class GameElement
{
private:
    Sommet<VSommet> position;
    sf::Texture texture;
    Orientation orientation = Orientation::WEST;

public:
    GameElement(const Sommet<VSommet> &position,
                const sf::Texture &texture)
	: position(position), texture(texture)
    {};
    virtual ~GameElement();

    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);

    sf::Texture &getTexture();
    void setTexture(const sf::Texture &);

    Orientation getOrientation() const;
    void setOrientation(Orientation);

    Sommet<VSommet> getPosition();
    void setPosition(Sommet<VSommet> const&);
};
