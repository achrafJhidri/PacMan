#include "GameElement.hpp"

double GameElement::getX() const {
    return position.v.p.x;
}

double GameElement::getY() const {
    return position.v.p.y;
}

void GameElement::setX(double x) {
    position.v.p.x = x;
}

void GameElement::setY(double y) {
    position.v.p.y = y;
}

sf::Texture &GameElement::getTexture() {
    return texture;
}

void GameElement::setTexture(const sf::Texture &t) {
    texture = t;
}

Orientation GameElement::getOrientation() const {
    return orientation;
}

void GameElement::setOrientation(Orientation orientation) {
    this->orientation = orientation;
}

Sommet<VSommet> GameElement::getPosition() {
    return position;
}

void GameElement::setPosition(Sommet<VSommet> const &pos) {
    position = pos;
}
