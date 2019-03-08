#include "DynamicGameElement.h"
#include "Pacman.h"

DynamicGameElement::DynamicGameElement( Sommet<InfoSommet> *sommet, const sf::Texture &texture, double speed,int largeur,int hauteur,int nbTextures)
    : GameElement(sommet, texture,largeur,hauteur,nbTextures), speed(speed)
{}

DynamicGameElement::~DynamicGameElement() {}

double DynamicGameElement::getSpeed() const {
    return speed;
}

void DynamicGameElement::setSpeed(double s) {
    speed = s;
}

void DynamicGameElement::move(Orientation orientation) {
    // Determine how to rotate the sprite
    int angle;
#define CASE(o, a) case Orientation::o: angle = a; break;
    switch (orientation) {
	CASE(SOUTH,        90);
	CASE(NORTH,       -90);
	CASE(EAST,          0);
	CASE(WEST,        180);
	CASE(NORTH_EAST,  -45);
	CASE(NORTH_WEST, -135);
	CASE(SOUTH_EAST,   45);
	CASE(SOUTH_WEST,  135);
    }
#undef CASE
    this->sprite.setRotation(angle);

    // Iterate through neighbours
    PElement<Sommet<InfoSommet> > *ns;
    Sommet<InfoSommet> *neighbour;
    for (ns = this->position->listVoisin; ns != nullptr; ns = ns->s) {
	neighbour = ns->v;
	// Move if neighbour is in the right orientation
        if (checkAlignement(orientation, *neighbour)) {
	        position = neighbour;
            cout << position->v.vSommet << endl;
	        break;
        }
    }
}
