#include "GameElement.h"

GameElement::GameElement( Sommet<InfoSommet> *position, const sf::Texture &texture,int largeur,int hauteur,int nbTextures)
    : position(position), texture(texture),sprite(texture,largeur,hauteur,nbTextures)
{
   sprite.setPosition(position->v.vSommet.p.x,position->v.vSommet.p.y);
   
 }

GameElement::~GameElement() {}

double GameElement::getX() const { return position->v.vSommet.p.x; }
double GameElement::getY() const {return position->v.vSommet.p.y;}

void GameElement::setX(double x) {position->v.vSommet.p.x = x;}
void GameElement::setY(double y) {position->v.vSommet.p.y = y;}

sf::Texture& GameElement::getTexture() {return texture;}

void GameElement::setTexture(const sf::Texture &t) {
    texture = t;
}

// Orientation GameElement::getOrientation() const {
    
//     return orientation;
// }

// void GameElement::setOrientation(Orientation orientation) {
//     this->orientation = orientation;
   
// }

Sommet<InfoSommet>* GameElement::getSommet() {
    return position;
}

bool GameElement::checkAlignement(Orientation o, Sommet<InfoSommet> const &s) {
    // Retourne vrai si `this' est à `o' de `s'
    bool aligned = true;
    if (o & Orientation::NORTH) {
	aligned &= this->getY() > s.v.vSommet.p.y;
    } else if (o & Orientation::SOUTH) {
	aligned &= this->getY() < s.v.vSommet.p.y;
    } else {
	// Ni au nord, ni au sud
	aligned &= this->getY() == s.v.vSommet.p.y;
    }

    if (o & Orientation::EAST) {
	aligned &= this->getX() < s.v.vSommet.p.x;
    } else if (o & Orientation::WEST) {
	aligned &= this->getX() > s.v.vSommet.p.x;
    } else {
	// Ni à l'est ni à l'ouest
	aligned &= this->getX() == s.v.vSommet.p.x;
    }

    return aligned;
}

void GameElement::setSommet(Sommet<InfoSommet>  *pos) {
    position = pos;
}
void GameElement::animate(){
    sprite.update();
}
