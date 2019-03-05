#pragma once
#include <string>
#include "Vecteur2D.h"
#include <sstream>


using namespace std;
/**

Classes VSommet et Peinture : elles sont utilisées dans TestDessinGraphe pour dessiner un graphe.


informations associée à un sommet : nom, position, couleur
sert à tester l'opération "dessiner un graphe"

VSommet comme "valeur associée à un sommet"

*/
class VSommet
{
public:
	constexpr static  int rayonDisquePixels = 30;
	constexpr static unsigned int couleurBord = 0xA10684FF; // couleur violine opaque
	string nom;
	Vecteur2D p;		  	// position
	unsigned int couleur; 	// couleur au format rgba
	


	/**
	par défaut, la couleur d'un sommet est rouge opaque
	*/
	VSommet(const string & nom, const Vecteur2D & p, const unsigned int couleur = 0xFF0000FF) : nom(nom), p(p), couleur(couleur) {}

	virtual
		operator string () const { ostringstream o; o << "( " << nom << ", " << p << ", " << couleur << ")"; return o.str(); }

	friend ostream & operator << (ostream & o, const VSommet & vSommet) { return o << (string)vSommet; }
};
