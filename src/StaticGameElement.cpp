#include "StaticGameElement.hpp"

StaticGameElement::StaticGameElement( Sommet<VSommet> *pos, const sf::Texture &tex, int pts,int largeur,int hauteur,int nbTextures)
    : GameElement(pos, tex,largeur,hauteur,nbTextures), points(pts)
{}

StaticGameElement::~StaticGameElement() {}

int StaticGameElement::getPoints() const {
    return points;
}
