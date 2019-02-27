#include "DynamicGameElement.hpp"

DynamicGameElement::DynamicGameElement(const Sommet<VSommet> &sommet, const sf::Texture &texture)
    : GameElement(sommet, texture), speed(1)
{}

double DynamicGameElement::getSpeed() const {
    return speed;
}

void DynamicGameElement::setSpeed(double s) {
    speed = s;
}
