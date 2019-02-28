#include "StaticGameElement.hpp"

StaticGameElement::StaticGameElement(const Sommet<VSommet> &pos, const sf::Texture &tex, int pts)
    : GameElement(pos, tex), points(pts)
{}

StaticGameElement::~StaticGameElement() {}

int StaticGameElement::getPoints() const {
    return points;
}
