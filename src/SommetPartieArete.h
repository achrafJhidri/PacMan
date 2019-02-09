#pragma once
#include "Sommet.h"
#include "Arete.h"
template <class S,class T> 
class SommetPartieArete
{
	Sommet<T> * original;
public:
	SommetPartieArete(const Sommet<T> * o) :original(const_cast<Sommet <T> *> (o)) {};
	
	bool operator()(const Arete<S, T> * arrete)const {
		if ((arrete->getDebut() == original) || (arrete->getFin() == original))
			return true;
		return false;
	}
};

