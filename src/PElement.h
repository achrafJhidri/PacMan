#pragma once

/*
 * Pelement.h
 *
 * liste rÃ©cursive dont les valeurs sont des pointeurs
 *
 * Attention : les mÃ©thodes rÃ©cursives qui parcourent les listes doivent systÃ©matiquement Ãªtre statiques !!!
 *
 *  Created on: 2 aoÃ»t 2012
 *      Author: Dominique
 */



#include <iostream>
#include <sstream>
#include <string>
#include "Erreur.h"
 //#include <Reels.h>
 //#include <Entiers.h>

using namespace std;

template <class T>
class PElement
{
public:
	T * v;				// valeur
	PElement<T> * s;	// suivant

	/**
	 *
	 * Ne crÃ©e pas de copie de *v. Pointe donc sur la donnÃ©e originale *v
	 *
	 * */
	PElement(T * v, PElement<T> * s) :v(v), s(s) {}


	// static void ecrit(ostream & os, const PElement<T> * p); // obsolÃ¨te

	/**
	 * suppose que T est munie de la fct :   const String T::ecrit() const
	 * Cette mÃ©thode est appelÃ©e pour chaque Ã©lÃ©ment de p. Ainsi, si elle est virtuelle, p peut Ãªtre hÃ©tÃ©rogÃ¨ne
	 *
	 * */
	 //static const string ecrit(const PElement<T> * p, const char * debut = "(", const char * separateur = ", ", const char * fin = ")");

	 //static const string toString(const PElement<T> * p, const string (*f)(const T &), const char * debut, const char * separateur, const char * fin);

	static const string toString(const PElement<T> * p, const char * debut = "( ", const char * separateur = ", ", const char * fin = ")");

	static int taille(const PElement<T> * l);

	/**
	 *
	 * ne recopie pas les donnÃ©es *v. rÃ©alise donc une copie partageant les donnÃ©es v avec l
	 *
	 * */
	static  PElement<T> * copie1(PElement<T> * l);

	/**
	 *
	 * recopie  toutes les donnÃ©es *v. rÃ©alise donc une copie ne partageant aucune donnÃ©e  avec l
	 *
	 * */
	static  PElement<T> * copie2(const PElement<T> * l);

	/**
	 *
	 * recopie  toutes les donnÃ©es *v Ã  l'aide de la mÃ©thode v->copie(). rÃ©alise donc une copie ne partageant aucune donnÃ©e  avec l
	 *
	 * Alors si la classe T possÃ¨de la mÃ©thode virtuelle copie(), l peut Ãªtre hÃ©tÃ©rogÃ¨ne.
	 * Et la mÃ©thode copie3 produit une copie de cette liste hÃ©tÃ©rogÃ¨ne.
	 *
	 * */

	static PElement<T> * copie3(const PElement<T> * l);

	/**
	 * concatÃ¨ne l2 Ã  la fin de l1. Ne crÃ©e aucun maillon.
	 *
	 * En sortie l1 pointe sur le dÃ©but de la concatÃ©nation
	 *
	 * DONNEES : l1, l2 (peuvent Ãªtre vides toutes les deux)
	 *
	 * RESULTATS : l1 contenant la concatÃ©nation
	 *
	 * Exemple 1 : si en entrÃ©e l1 = (2,5,4) et l2 = (7,11) alors en sortie l1 = (2,5,4,7,11) et l2 = (7,11)
	 * Exemple 2 : si en entrÃ©e l1 = () et l2 = (7,11) alors en sortie l1 = (7,11) et  l2 = (7,11)
	 * Exemple 3 : si en entrÃ©e l1 = (9,5) et l2 = () alors en sortie l1 = (9,5) et l2 = ()
	 *
	 * */
	static void concat(PElement<T> * & l1, PElement<T> *  l2);

	/**
	 * efface toute la liste l
	 * mais n'efface pas les donnÃ©es *v
	 *
	 * */
	static void efface1(PElement<T>* & l);

	/**
	 * efface toute la liste l
	 * et efface toutes les donnÃ©es *v
	 *
	 * */
	static void efface2(PElement<T>* & l);

	/**
	 * recherche si a appartient Ã  l
	 *
	 * renvoie un pointeur sur le maillon de l contenant a
	 * renvoie NULL si a n'appartient pas Ã  l
	 *
	 * */
	static  PElement< T > * appartient(const T * a, PElement<T> * l);

	/**
	 * HYPOTHESES : l'Ã©valuation de condition() produit un boolÃ©en
	 * condition est supposÃ©e avoir la signature : bool condition( const T * a)
	 *
	 * renvoie un pointeur sur le 1er maillon de l vÃ©rifiant la condition "condition"
	 * renvoie NULL si aucun maillon ne vÃ©rifie la condition
	 *
	 * */
	template <class FONCTEUR>
	static PElement< T > * appartient(PElement<T> * l, const FONCTEUR & condition);
	/**
	 * InsÃ¨re * a dans l de telle sorte que l reste ordonnÃ©e par ordre croissant (l'Ã©lement en tÃªte est le plus petit).
	 * Ne rÃ©alise pas de copie de *a. En sortie l et a partagent donc physiquement des donnÃ©es.
	 *
	 * A l'instar de la mÃ©thode prÃ©cÃ©dente (appartient), cette fonction aurait aussi pu Ãªtre Ã©crite avec un argument foncteur
	 *
	 * DonnÃ©es : a (l'Ã©lÃ©ment Ã  insÃ©rer), l, estPlusPetitOuEgal(la fonction de comparaison))
	 * RÃ©sultats : l modifiÃ©e par l'insertion
	 * HypothÃ¨ses : on suppose l ordonnÃ©e par ordre croissant Ã  l'appel
	 *
	 * */
	static void insertionOrdonnee(T * a, PElement<T> * & l, bool(*estPlusPetitOuEgal)(const T * a1, const T * a2));

	/**
	 * retire la 1Ã¨re occurrence de a de l si a est prÃ©sent dans l, sinon ne fait rien
	 *
	 * L'Ã©lÃ©ment trouvÃ© n'est pas effacÃ©
	 *
	 * La comparaison est faite sur les pointeurs
	 *
	 * DonnÃ©es : a, l
	 * RÃ©sultats : l (Ã©ventuellement modifiÃ©e), par return : true si l'Ã©lÃ©ment a Ã©tÃ© trouvÃ©, false sinon
	 * */
	static bool retire(const T * a, PElement<T> * & l);


	/**
	 * retire l'Ã©lÃ©ment situÃ© en tÃªte de l et le renvoie. Le 1er maillon de l est effacÃ©.
	 *
	 * l est donc modifiÃ©e par l'appel. En sortie l compte un Ã©lÃ©ment de moins.
	 * lance une exception Erreur si l == NULL Ã  l'appel
	 *
	 * */
	static T * depiler(PElement<T> * & l);

	//-------------------------- PElement<T> ------------------------------
};

template<class T>
ostream& operator <<(ostream & os, const PElement<T> * p) { return os << PElement<T>::toString(p); }


/**
 * suppose que T est munie de la fct :   const String T::ecrit() const
 * Cette mÃ©thode est appelÃ©e pour chaque Ã©lÃ©ment de p. Ainsi, si elle est virtuelle, p peut Ãªtre hÃ©tÃ©rogÃ¨ne
 *
 * */
 //template <class T>
 ///*static*/ const string PElement<T>::ecrit( const PElement<T> * p, const char * debut, const char * separateur, const char * fin)
 //{
 //string s;
 //for ( s = debut; p ; p = p->s)
 //    s += p->v->ecrit()+separateur;
 //
 //return s+fin;
 //}



template <class T>
/*static*/ const string PElement<T>::toString(const PElement<T> * p, const char * debut, const char * separateur, const char * fin)
{
	PElement<T> * r;
	ostringstream oss;

	for (r = (PElement<T>*) p, oss << debut; r; r = r->s)
		oss << *(r->v) << separateur;

	oss << fin;
	return oss.str();
}

template <class T>
/* static */ void PElement<T>::concat(PElement<T> * & l1, PElement<T> * l2)
{
	if (!l1)        /* l1 == liste vide */
		l1 = l2;

	else
		concat(l1->s, l2);
}

template <class T>
/* static */ int PElement<T>::taille(const PElement<T> * l)
{
	if (!l) return 0;
	else
		return 1 + PElement<T>::taille(l->s);
}


/**
 *
 * ne recopie pas les donnÃ©es *v. rÃ©alise donc une copie partageant les donnÃ©es v avec l
 *
 * */
template <class T>
/* static */ PElement<T> * PElement<T>::copie1(PElement<T> * l)
{
	if (!l)
		return NULL;
	else
		return new PElement<T>(l->v, PElement<T>::copie1(l->s));
}

/**
 *
 * recopie  toutes les donnÃ©es *v. rÃ©alise donc une copie ne partageant aucune donnÃ©e  avec l
 *
 * */
template <class T>
/* static */ PElement<T> * PElement<T>::copie2(const PElement<T> * l)
{
	if (!l)
		return NULL;
	else
		return new PElement<T>(new T(*(l->v)), PElement<T>::copie2(l->s));
}

/**
 *
 * recopie  toutes les donnÃ©es *v Ã  l'aide de la mÃ©thode v->copie(). rÃ©alise donc une copie ne partageant aucune donnÃ©e  avec l
 *
 * Alors si la classe T possÃ¨de la mÃ©thode virtuelle copie(), l peut Ãªtre hÃ©tÃ©rogÃ¨ne. Et la mÃ©thode copie3 produit une copie de cette liste hÃ©tÃ©rogÃ¨ne.
 *
 * */
template <class T>
/* static */ PElement<T> * PElement<T>::copie3(const PElement<T> * l)
{
	if (!l)
		return NULL;
	else
		return new PElement<T>(l->v->copie(), PElement<T>::copie3(l->s));
}



/**
 * efface toute la liste l
 * mais n'efface pas les donnÃ©es *v
 *
 * */
template <class T>
/* static */ void PElement<T>::efface1(PElement<T>* & l)
{
	if (l)
	{
		PElement<T>::efface1(l->s);
		delete l; l = NULL;
	}
}
/**
 * efface toute la liste l
 * et efface toutes les donnÃ©es *v
 *
 * */
template <class T>
/* static */ void PElement<T>::efface2(PElement<T>* & l)
{
	if (l)
	{
		PElement<T>::efface2(l->s);
		delete l->v; delete l; l = NULL;
	}
}
/**
 * recherche si a appartient Ã  l
 *
 * renvoie un pointeur sur le maillon de l contenant a
 * renvoie NULL si a n'appartient pas Ã  l
 *
 * */
template <class T>
PElement< T > * PElement< T >::appartient(const T * a, PElement<T> * l)
{
	for (; l; l = l->s)
		if (a == l->v)
			return l;

	return l;
}

/**
 * HYPOTHESES : l'Ã©valuation de condition() produit un boolÃ©en
 * condition est supposÃ©e avoir la signature : bool condition( const T * a)
 *
 * renvoie un pointeur sur le 1er maillon de l vÃ©rifiant la condition "condition"
 * renvoie NULL si aucun maillon ne vÃ©rifie la condition
 *
 * */
template <class T>
template <class FONCTEUR>
/*static*/ PElement< T > * PElement< T >::appartient(PElement<T> * l, const FONCTEUR & condition)
{
	for (; l; l = l->s)
		if (condition(l->v))
			return l;

	return l;
}

/**
 * InsÃ¨re * a dans l de telle sorte que l reste ordonnÃ©e par ordre croissant (l'Ã©lement en tÃªte est le plus petit).
 * Ne rÃ©alise pas de copie de *a. En sortie l et a partagent donc physiquement des donnÃ©es.
 *
 * A l'instar de la mÃ©thode prÃ©cÃ©dente (appartient), cette fonction aurait aussi pu Ãªtre Ã©crite avec un argument foncteur
 *
 * DonnÃ©es : a (l'Ã©lÃ©ment Ã  insÃ©rer), l, estPlusPetitOuEgal(la fonction de comparaison))
 * RÃ©sultats : l modifiÃ©e par l'insertion
 * HypothÃ¨ses : on suppose l ordonnÃ©e par ordre croissant Ã  l'appel
 *
 * */
template<class T>
/*static*/ void PElement<T>::insertionOrdonnee(T * a, PElement<T> * & l, bool(*estPlusPetitOuEgal)(const T * a1, const T * a2))
{
	if (!l || estPlusPetitOuEgal(a, l->v))
		l = new PElement<T>(a, l);
	else
		PElement<T>::insertionOrdonnee(a, l->s, estPlusPetitOuEgal);
}

/**
 * retire la 1Ã¨re occurrence de a de l si a est prÃ©sent dans l, sinon ne fait rien
 *
 * L'Ã©lÃ©ment trouvÃ© n'est pas effacÃ©
 *
 * La comparaison est faite sur les pointeurs
 *
 * DonnÃ©es : a, l
 * RÃ©sultats : l (Ã©ventuellement modifiÃ©e), par return : true si l'Ã©lÃ©ment a Ã©tÃ© trouvÃ©, false sinon
 * */
template<class T>
/*static*/ bool PElement<T>::retire(const T * a, PElement<T> * & l)
{
	if (!l)
		return false;
	else
		if (a == l->v)
		{
			PElement<T> * r = l; l = l->s; delete r;
			return true;
		}
		else
			return PElement<T>::retire(a, l->s);
}

/**
 * retire l'Ã©lÃ©ment situÃ© en tÃªte de l et le renvoie. Le 1er maillon de l est effacÃ©.
 *
 * l est donc modifiÃ©e par l'appel. En sortie l compte un Ã©lÃ©ment de moins.
 * lance une exception Erreur si l == NULL Ã  l'appel
 *
 * */
template <class T>
/* static */ T * PElement<T>::depiler(PElement<T> * & l)
{
	if (!l) throw Erreur("impossible de dÃ©piler une pile vide");
	T * a = l->v;
	PElement<T> * tete = l;

	l = l->s; delete tete;
	return a;

}





/**
 *
 * ne recopie pas les donnÃ©es *v. rÃ©alise donc la rÃ©union au sens ensembliste de l1 et l2  partageant les donnÃ©es v avec l1 et l2.
 *
 * Suppose que l1 et l2 sont des ensembles. Elles ne contiennent donc aucun doublon.
 *
 * DONNEES : l1 et l2 (reprÃ©sentant des ensembles)
 * RESULTAT : l1 U l2 au sens ensembliste partageant les donnÃ©es v avec l1 er l2
 *
 * */
template <class T>
PElement<T> * reunion(PElement<T> * l1, PElement<T> * l2)
{
	PElement<T> * r = PElement<T>::copie1(l2);
	PElement<T> * pl1;

	for (pl1 = l1; pl1; pl1 = pl1->s)
		if (!PElement<T>::appartient(pl1->v, r))
			r = new PElement<T>(pl1->v, r);

	return r;
}



/**
 * partage p en deux listes p et p1 de taille Ã©gale : Laisse dans p les Ã©lÃ©ments de rang impair et place dans p1 les Ã©lÃ©ments de rang pair
 *
 * DONNEES : p
 * RESULTATS : p (modifiÃ©e) et p1
 *
 * */
template <class T>
void partage(PElement<T> * & p, PElement<T> * & p1)
{
	if (p == NULL || p->s == NULL)
		p1 = NULL;
	else
	{
		PElement<T> *  r1, *r2;

		r1 = p->s;
		r2 = r1->s;

		partage(r2, p1);

		r1->s = p1;
		p->s = r2;
		p1 = r1;
	}
}

/**
 * rÃ©alise la fusion ordonnÃ©e de p1 et p2 et place le rÃ©sultat dans p1. En sortie p2 est donc vide.
 * Ne crÃ©e aucun maillon.
 *
 * Suppose que p1 et p2 sont ordonnÃ©es par ordre croissant en entrÃ©e. La liste rÃ©sultante est aussi ordonnÃ©e par ordre croissant.
 *
 * Utilise la fct estPlusPetitOuEgal pour les comparaisons 1 Ã  1.
 *
 * On suppose que estPlusPetitOuEgal(a1,a2) renvoie true si a1 <= a2 oÃ¹ <= est une relation d'ordre sur T et renvoie false si a1 > a2
 *
 * DONNEES : p1 et p2
 * RESULTATS: P1 et p2
 *
 * */
template <class T>
void fusion(PElement<T> * & p1, PElement<T> * & p2, bool(*estPlusPetitOuEgal)(const T * a1, const T * a2))
{
	if (!p2) return; // p2 est vide, il n'y a rien Ã  faire

	if (!p1) // p1 est vide et p2 ne l'est pas
	{
		p1 = p2; p2 = NULL;
		return;
	}

	// Ã  prÃ©sent, p1 et p2 sont non vides

	if (estPlusPetitOuEgal(p1->v, p2->v)) // p1->v <= p2->v
	{
		PElement<T> * r;
		r = p1->s;
		fusion(r, p2, estPlusPetitOuEgal);
		p1->s = r;
	}
	else // p1->v > p2->v
	{
		PElement<T> * r;
		r = p2->s;
		fusion(p1, r, estPlusPetitOuEgal);
		p2->s = p1;
		p1 = p2;
		p2 = NULL;
	}
}


/**
 * trie p par tri rÃ©cursif dichotomique (trifusion)
 *
 * ne crÃ©e pas de nouveau maillon. La liste originale p est modifiÃ©e
 *
 * Utilise la fct estPlusPetitOuEgal pour les comparaisons 1 Ã  1.
 *
 * range les Ã©lÃ©ments par ordre croissant
 *
 * On suppose que estPlusPetitOuEgal(a1,a2) renvoie true si a1 <= a2 oÃ¹ <= est une relation d'ordre sur T et renvoie false si a1 > a2
 *
 * DONNEES : p
 * RESULTATS : p modifiÃ©e
 *
 * */
template <class T>
void tri(PElement<T>* & p, bool(*estPlusPetitOuEgal)(const T * a1, const T * a2))
{
	if (p != NULL && p->s != NULL)
	{
		PElement<T> * p1;

		partage(p, p1);

		tri(p, estPlusPetitOuEgal); tri(p1, estPlusPetitOuEgal);

		fusion(p, p1, estPlusPetitOuEgal);
	}
}




