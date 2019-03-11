#include "Pacman.hpp"



Pacman::Pacman(Sommet<InfoSommet> *s, const sf::Texture &t, double speed, int largeur, int hauteur, int nbTextures)

	: DynamicGameElement(s, t, speed, largeur, hauteur, nbTextures), nbPieceGagnee(0), enVie(true)

{}



Pacman::~Pacman() {}

bool Pacman::estVivant()const {
	return enVie;
}
void Pacman::meurt() {
	enVie = false;
}
int Pacman::getNbPieceGagnee()const 
{
	return nbPieceGagnee;
}


bool Pacman::move(Orientation orientation) {

	if (position->pacGomme) {

		nbPieceGagnee++;
		
		cout << nbPieceGagnee << endl;

		position->pacGomme = false;

	}

	return DynamicGameElement::move(orientation);

}



void Pacman::check(const Ghost * ghost)

{

	if (this->position == ghost->position)

	{

		if (ghost->estOffensif())

		{

			cout << "pacman est mort " << endl;
			meurt();
		}

		else

		{

			cout << "fantome est mort" << endl;

		}

	}

}