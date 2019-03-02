#include "GameElement.hpp"

GameElement::GameElement(const Sommet<VSommet> &position, const sf::Texture &texture,int largeur,int hauteur,int nbTextures)
    : position(position), texture(texture),sprite(texture,largeur,hauteur,nbTextures)
{
   sprite.setPosition(position.v.p.x+10,position.v.p.y+248);
   cout <<"x="<< position.v.p.x << " y=" << position.v.p.y << endl ;
 }

GameElement::~GameElement() {}

double GameElement::getX() const { return position.v.p.x; }
double GameElement::getY() const {return position.v.p.y;}

void GameElement::setX(double x) {position.v.p.x = x;}
void GameElement::setY(double y) {position.v.p.y = y;}

sf::Texture& GameElement::getTexture() {return texture;}

void GameElement::setTexture(const sf::Texture &t) {
    texture = t;
}

Orientation GameElement::getOrientation() const {
    return orientation;
}

void GameElement::setOrientation(Orientation orientation) {
    this->orientation = orientation;
}

Sommet<VSommet>& GameElement::getSommet() {
    return position;
}

void GameElement::setSommet(Sommet<VSommet> const &pos) {
    position = pos;
}
