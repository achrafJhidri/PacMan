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
	int degre;
	PElement<Sommet > * listVoisin ;
	bool pacGomme ; 
	Sommet(const int clef, const T & v,bool aGomme = true ) :GElement<T>(clef, v), degre(0) ,listVoisin(NULL),pacGomme(aGomme){}

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
