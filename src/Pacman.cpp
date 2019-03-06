#include "Pacman.hpp"

Pacman::Pacman( Sommet<InfoSommet> *s, const sf::Texture &t, double speed,int largeur,int hauteur,int nbTextures)
    : DynamicGameElement( s, t, speed,largeur,hauteur,nbTextures),nbPieceGagnee(0)
{}

Pacman::~Pacman() {}

void Pacman::move(Orientation orientation){
    if( position->pacGomme ){
        nbPieceGagnee++;
        cout << nbPieceGagnee << endl ;
        position->pacGomme=false ;
    }
    DynamicGameElement::move(orientation);
}

void Pacman::check(const Ghost * ghost)
{
	if (this->position == ghost->position)
	{
		if (ghost->estOffensif())
		{
			cout << "pacman est mort " << endl;
		}
		else
		{
			cout << "fantome est mort" << endl;
		}
	}
}
