#pragma once 
#include "Vecteur2D.h"
#include "InfoSommet.h"
#include "Sommet.h"
#include "Orientation.h"

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"

class GameElement
{ 
public:
    Sommet<InfoSommet>  * position;
    sf::Texture texture;
    // Orientation orientation = Orientation::WEST;
    AnimatedSprite sprite;

    GameElement( Sommet<InfoSommet> *, const sf::Texture &,int largeur,int hauteur,int nbTextures);
    virtual ~GameElement();

    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);

    sf::Texture& getTexture();
    void setTexture(const sf::Texture &);

    // Orientation getOrientation() const;
    // void setOrientation(Orientation);

    Sommet<InfoSommet>* getSommet();
    void setSommet(Sommet<InfoSommet> *);

    void animate();

    bool checkAlignement(Orientation, Sommet<InfoSommet> const&);
    
    template <class Fenetre>
    bool dessine( Fenetre & f ) {
      return   f.dessine(this);
    }
};
