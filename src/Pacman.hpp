#pragma once

#include "DynamicGameElement.hpp"

#include "Ghost.hpp"

class Pacman : public DynamicGameElement

{
public:

	int nbPieceGagnee;
	bool enVie;

	Pacman(Sommet<InfoSommet> *, const sf::Texture &, double, int largeur, int hauteur, int nbTextures );

	virtual ~Pacman();


	bool estVivant()const ;
	void meurt();
	int getNbPieceGagnee()const;
	
	bool move(Orientation orientation);

	void check(const Ghost * ghost);

};