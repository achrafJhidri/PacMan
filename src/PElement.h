#pragma once
#include <iostream>
#include <sstream>
#include <string>


using namespace std;
template <class T> 
class PElement
{
public:
	PElement<T> * s;
	T * v;


	PElement(PElement<T> * next, T * value):s(next),v(value) {
	
	};

	

	static const string toString(const PElement<T> * p, const char * debut = "( ", const char * separateur = ", ", const char * fin = ")")
	{
		ostringstream os;
		os << *debut;
		while (p != NULL) {
			os << *p->v << *separateur;
			p = p->s;
		}
		os << *fin;
		return os.str();
	};

	static int taille(const PElement<T> * l) {
		if (l == NULL) 
			return 0;
		else
			return 1 + taille(l->s);
	}
	


	static void insertionOrdonnee(T * a, PElement<T> * & l, bool(*estPlusPetitOuEgal)(const T * a1, const T * a2)) {
		
		if (l == NULL || estPlusPetitOuEgal(a, l->v)) {
			l = new PElement<T>(l, a);
		}
		else 
		{
			insertionOrdonnee(a, l->s, estPlusPetitOuEgal);
		}
	};

	

	static T * depiler(PElement<T> * & l) {
		if (l == NULL) {
			throw "dépiler une liste vide";
		}

			// recuperation de la valeur de la tête de la liste
			T * a = l->v;
			PElement *tmp = l;
			// l pointe sur le maillon suivant 
			l = l->s;

			//suppression du premier maillon

			delete tmp;

			return a;
		

	};

	static bool retire(const T * a, PElement<T> * & l) {
		if (l == NULL)
				return false;
		else {
				if (*l->v == *a){
						depiler(l);
						return true;
				}
				else {
					return retire(a, l->s);
				}
		}
	}

	static void efface1(PElement<T>* & l) {
		if (l != NULL) {
			
			efface1(l->s);
			delete l;
			l = NULL;
		}
	}
	
	static void efface2(PElement<T>* & l) {
		if (l != NULL) {
			efface2(l->s);
			delete l->v;
			delete l;
			l = NULL;
		}
	}

	static PElement<T> * copie1(PElement<T> * l) {	
		if (l == NULL)
			return NULL;
		else
			return new PElement<T>( copie1(l->s), l->v);
	}

	static PElement<T> * copie2(PElement<T> * l) {
		if (l == NULL)
			return NULL;
		else 
			return new PElement<T>(copie2(l->s), new T(*l->v));
	}

	static PElement<T> * copie3(PElement<T> * l) {
		if (l == NULL)
			return NULL;
		else
			return new PElement<T>(copie3(l->s),l->v->Clone());
	}

	static PElement< T > * appartient(const T * a, PElement<T> * l) {
		if (l == NULL)
			return NULL;
		else
		{
			if (l->v == a)
				return l;
			else
				return appartient(a, l->s);
		}
	}

	template < class FONCTEUR>
	static PElement< T > * appartient(PElement<T> * l, const FONCTEUR & condition) {
		if (l == NULL)
			return NULL;
		else
		{
			if (condition(l->v))
				return l;
			else
				return appartient( l->s,condition);
		}
	}

};
