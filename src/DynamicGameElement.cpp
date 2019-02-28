#include "DynamicGameElement.hpp"

DynamicGameElement::DynamicGameElement(const Sommet<VSommet> &sommet, const sf::Texture &texture, double speed)
    : GameElement(sommet, texture), speed(speed)
{}

DynamicGameElement::~DynamicGameElement() {}

double DynamicGameElement::getSpeed() const {
    return speed;
}

void DynamicGameElement::setSpeed(double s) {
    speed = s;
}
