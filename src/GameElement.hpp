#pragma once 
#include "Vecteur2D.h"
#include "VSommet.h"
#include "Sommet.h"

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

enum class Orientation {
    // Basic
    NORTH, SOUTH, EAST, WEST,
    // Composed
    NORTH_EAST, NORTH_WEST,
    SOUTH_EAST, SOUTH_WEST
};

class GameElement
{ 
public:
    Sommet<VSommet>  * position;
    sf::Texture texture;
    // Orientation orientation = Orientation::WEST;
    AnimatedSprite sprite;
    
    GameElement( Sommet<VSommet> *, const sf::Texture &,int largeur,int hauteur,int nbTextures);
    virtual ~GameElement();

    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);

    sf::Texture& getTexture();
    void setTexture(const sf::Texture &);

    // Orientation getOrientation() const;
    // void setOrientation(Orientation);

    Sommet<VSommet>* getSommet();
    void setSommet(Sommet<VSommet> *);

    void animate();

    
    template <class Fenetre>
    bool dessine( Fenetre & f ) {
      return   f.dessine(this);
    }
};
