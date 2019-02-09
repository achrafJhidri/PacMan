#pragma once
#include "GElement.h"
#include "Sommet.h"
template <class S,class T>
class Arete :
	public GElement<S>
{
	Sommet<T> * debut;
	Sommet<T> * fin;

public:
	Arete(const int clef, const S & v, Sommet<T> * deb, Sommet<T> * f)
	:GElement<S>(clef, v)
	{
		debut = deb;
		debut->setDegre(debut->getDegre()+1);
		fin = f;
		fin->setDegre(fin->getDegre()+1);
	};


	~Arete() {
		fin->setDegre(fin->getDegre()-1);
		debut->setDegre(debut->getDegre()-1);
	};


	Sommet<T> * getDebut()const {
		return debut;
	}
	Sommet<T> * getFin()const {
		return fin;
	}
	operator string ()const {
		ostringstream os;
		os <<  "arete(" <<  debut->getClef() << "," << fin->getClef()<<")";
		return os.str();
	}

	friend ostream & operator << (ostream & f, const Arete<S, T> & arete) {
		return f << string(arete);
	}
	bool estEgal(const Sommet<T> *s1, const Sommet<T> * s2)const {
		if ((debut == s1 && fin == s2) || (fin == s1 && debut == s2))
			return true;
		else
			return false;
	}
};

