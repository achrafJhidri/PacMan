#pragma once
#include "GElement.h"
template < class T> 
class Sommet :
	public GElement<T>
{
	unsigned int degre;
public:
	Sommet(const unsigned int clef, const T & v, const unsigned int d = 0) :GElement<T>(clef,v){
		setDegre(d);
	};
	

	unsigned int getDegre()const {
		return degre; 
	}
	void setDegre(const unsigned int d) {
		degre = d;
	}
	operator string()const {
		ostringstream os;
		os <<"Sommet "<<GElement<T>::operator string () << " de degre " << degre;
		return os.str();
	}

	friend ostream & operator << (ostream & f, const Sommet<T> & element)
	{
		return f << string(element);
	}
	
};

