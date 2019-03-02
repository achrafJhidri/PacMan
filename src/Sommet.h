#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "GElement.h"
#include "PElement.h"

using namespace std;

/**

Sommet d'un graphe en général

v est l'information associée au sommet : elle dépend de l'application du graphe
*/
template <class T>
class Sommet : public GElement<T>
{
public:
	int degre;		// Rappel : degré = nombre d'arêtes adjacentes à ce sommet
	/**

	Un sommet est toujours créé isolé (c'est-à-dire qu'il n'y a pas d'arête adjacente à ce sommet)
	*/
	PElement<Sommet > * listVoisin ;
	Sommet(const int clef, const T & v) :GElement<T>(clef, v), degre(0) ,listVoisin(NULL){}

	operator string () const;

};

template <class T>
Sommet<T>::operator string () const
{
	ostringstream oss;

	oss << "Sommet(" << endl;
	oss << GElement<T>::operator string() << endl;
	oss << "degré = " << degre << endl;
	oss << ")";
	return oss.str();
}

template <class T>
ostream & operator << (ostream & os, const Sommet<T> & sommet)
{
	return os << (string)sommet;
}
