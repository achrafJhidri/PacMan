#pragma once

/*
 * Pelement.h
 *
 * liste r�cursive dont les valeurs sont des pointeurs
 *
 * Attention : les m�thodes r�cursives qui parcourent les listes doivent syst�matiquement �tre statiques !!!
 *
 *  Created on: 2 ao�t 2012
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
	 * Ne cr�e pas de copie de *v. Pointe donc sur la donn�e originale *v
	 *
	 * */
	PElement(T * v, PElement<T> * s) :v(v), s(s) {}


	// static void ecrit(ostream & os, const PElement<T> * p); // obsol�te

	/**
	 * suppose que T est munie de la fct :   const String T::ecrit() const
	 * Cette m�thode est appel�e pour chaque �l�ment de p. Ainsi, si elle est virtuelle, p peut �tre h�t�rog�ne
	 *
	 * */
	 //static const string ecrit(const PElement<T> * p, const char * debut = "(", const char * separateur = ", ", const char * fin = ")");

	 //static const string toString(const PElement<T> * p, const string (*f)(const T &), const char * debut, const char * separateur, const char * fin);

	static const string toString(const PElement<T> * p, const char * debut = "( ", const char * separateur = ", ", const char * fin = ")");

	static int taille(const PElement<T> * l);

	/**
	 *
	 * ne recopie pas les donn�es *v. r�alise donc une copie partageant les donn�es v avec l
	 *
	 * */
	static  PElement<T> * copie1(PElement<T> * l);

	/**
	 *
	 * recopie  toutes les donn�es *v. r�alise donc une copie ne partageant aucune donn�e  avec l
	 *
	 * */
	static  PElement<T> * copie2(const PElement<T> * l);

	/**
	 *
	 * recopie  toutes les donn�es *v � l'aide de la m�thode v->copie(). r�alise donc une copie ne partageant aucune donn�e  avec l
	 *
	 * Alors si la classe T poss�de la m�thode virtuelle copie(), l peut �tre h�t�rog�ne.
	 * Et la m�thode copie3 produit une copie de cette liste h�t�rog�ne.
	 *
	 * */

	static PElement<T> * copie3(const PElement<T> * l);

	/**
	 * concat�ne l2 � la fin de l1. Ne cr�e aucun maillon.
	 *
	 * En sortie l1 pointe sur le d�but de la concat�nation
	 *
	 * DONNEES : l1, l2 (peuvent �tre vides toutes les deux)
	 *
	 * RESULTATS : l1 contenant la concat�nation
	 *
	 * Exemple 1 : si en entr�e l1 = (2,5,4) et l2 = (7,11) alors en sortie l1 = (2,5,4,7,11) et l2 = (7,11)
	 * Exemple 2 : si en entr�e l1 = () et l2 = (7,11) alors en sortie l1 = (7,11) et  l2 = (7,11)
	 * Exemple 3 : si en entr�e l1 = (9,5) et l2 = () alors en sortie l1 = (9,5) et l2 = ()
	 *
	 * */
	static void concat(PElement<T> * & l1, PElement<T> *  l2);

	/**
	 * efface toute la liste l
	 * mais n'efface pas les donn�es *v
	 *
	 * */
	static void efface1(PElement<T>* & l);

	/**
	 * efface toute la liste l
	 * et efface toutes les donn�es *v
	 *
	 * */
	static void efface2(PElement<T>* & l);

	/**
	 * recherche si a appartient � l
	 *
	 * renvoie un pointeur sur le maillon de l contenant a
	 * renvoie NULL si a n'appartient pas � l
	 *
	 * */
	static  PElement< T > * appartient(const T * a, PElement<T> * l);

	/**
	 * HYPOTHESES : l'�valuation de condition() produit un bool�en
	 * condition est suppos�e avoir la signature : bool condition( const T * a)
	 *
	 * renvoie un pointeur sur le 1er maillon de l v�rifiant la condition "condition"
	 * renvoie NULL si aucun maillon ne v�rifie la condition
	 *
	 * */
	template <class FONCTEUR>
	static PElement< T > * appartient(PElement<T> * l, const FONCTEUR & condition);
	/**
	 * Ins�re * a dans l de telle sorte que l reste ordonn�e par ordre croissant (l'�lement en t�te est le plus petit).
	 * Ne r�alise pas de copie de *a. En sortie l et a partagent donc physiquement des donn�es.
	 *
	 * A l'instar de la m�thode pr�c�dente (appartient), cette fonction aurait aussi pu �tre �crite avec un argument foncteur
	 *
	 * Donn�es : a (l'�l�ment � ins�rer), l, estPlusPetitOuEgal(la fonction de comparaison))
	 * R�sultats : l modifi�e par l'insertion
	 * Hypoth�ses : on suppose l ordonn�e par ordre croissant � l'appel
	 *
	 * */
	static void insertionOrdonnee(T * a, PElement<T> * & l, bool(*estPlusPetitOuEgal)(const T * a1, const T * a2));

	/**
	 * retire la 1�re occurrence de a de l si a est pr�sent dans l, sinon ne fait rien
	 *
	 * L'�l�ment trouv� n'est pas effac�
	 *
	 * La comparaison est faite sur les pointeurs
	 *
	 * Donn�es : a, l
	 * R�sultats : l (�ventuellement modifi�e), par return : true si l'�l�ment a �t� trouv�, false sinon
	 * */
	static bool retire(const T * a, PElement<T> * & l);


	/**
	 * retire l'�l�ment situ� en t�te de l et le renvoie. Le 1er maillon de l est effac�.
	 *
	 * l est donc modifi�e par l'appel. En sortie l compte un �l�ment de moins.
	 * lance une exception Erreur si l == NULL � l'appel
	 *
	 * */
	static T * depiler(PElement<T> * & l);

	//-------------------------- PElement<T> ------------------------------
};

template<class T>
ostream& operator <<(ostream & os, const PElement<T> * p) { return os << PElement<T>::toString(p); }


/**
 * suppose que T est munie de la fct :   const String T::ecrit() const
 * Cette m�thode est appel�e pour chaque �l�ment de p. Ainsi, si elle est virtuelle, p peut �tre h�t�rog�ne
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
 * ne recopie pas les donn�es *v. r�alise donc une copie partageant les donn�es v avec l
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
 * recopie  toutes les donn�es *v. r�alise donc une copie ne partageant aucune donn�e  avec l
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
 * recopie  toutes les donn�es *v � l'aide de la m�thode v->copie(). r�alise donc une copie ne partageant aucune donn�e  avec l
 *
 * Alors si la classe T poss�de la m�thode virtuelle copie(), l peut �tre h�t�rog�ne. Et la m�thode copie3 produit une copie de cette liste h�t�rog�ne.
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
 * mais n'efface pas les donn�es *v
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
 * et efface toutes les donn�es *v
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
 * recherche si a appartient � l
 *
 * renvoie un pointeur sur le maillon de l contenant a
 * renvoie NULL si a n'appartient pas � l
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
 * HYPOTHESES : l'�valuation de condition() produit un bool�en
 * condition est suppos�e avoir la signature : bool condition( const T * a)
 *
 * renvoie un pointeur sur le 1er maillon de l v�rifiant la condition "condition"
 * renvoie NULL si aucun maillon ne v�rifie la condition
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
 * Ins�re * a dans l de telle sorte que l reste ordonn�e par ordre croissant (l'�lement en t�te est le plus petit).
 * Ne r�alise pas de copie de *a. En sortie l et a partagent donc physiquement des donn�es.
 *
 * A l'instar de la m�thode pr�c�dente (appartient), cette fonction aurait aussi pu �tre �crite avec un argument foncteur
 *
 * Donn�es : a (l'�l�ment � ins�rer), l, estPlusPetitOuEgal(la fonction de comparaison))
 * R�sultats : l modifi�e par l'insertion
 * Hypoth�ses : on suppose l ordonn�e par ordre croissant � l'appel
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
 * retire la 1�re occurrence de a de l si a est pr�sent dans l, sinon ne fait rien
 *
 * L'�l�ment trouv� n'est pas effac�
 *
 * La comparaison est faite sur les pointeurs
 *
 * Donn�es : a, l
 * R�sultats : l (�ventuellement modifi�e), par return : true si l'�l�ment a �t� trouv�, false sinon
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
 * retire l'�l�ment situ� en t�te de l et le renvoie. Le 1er maillon de l est effac�.
 *
 * l est donc modifi�e par l'appel. En sortie l compte un �l�ment de moins.
 * lance une exception Erreur si l == NULL � l'appel
 *
 * */
template <class T>
/* static */ T * PElement<T>::depiler(PElement<T> * & l)
{
	if (!l) throw Erreur("impossible de d�piler une pile vide");
	T * a = l->v;
	PElement<T> * tete = l;

	l = l->s; delete tete;
	return a;

}





/**
 *
 * ne recopie pas les donn�es *v. r�alise donc la r�union au sens ensembliste de l1 et l2  partageant les donn�es v avec l1 et l2.
 *
 * Suppose que l1 et l2 sont des ensembles. Elles ne contiennent donc aucun doublon.
 *
 * DONNEES : l1 et l2 (repr�sentant des ensembles)
 * RESULTAT : l1 U l2 au sens ensembliste partageant les donn�es v avec l1 er l2
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
 * partage p en deux listes p et p1 de taille �gale : Laisse dans p les �l�ments de rang impair et place dans p1 les �l�ments de rang pair
 *
 * DONNEES : p
 * RESULTATS : p (modifi�e) et p1
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
 * r�alise la fusion ordonn�e de p1 et p2 et place le r�sultat dans p1. En sortie p2 est donc vide.
 * Ne cr�e aucun maillon.
 *
 * Suppose que p1 et p2 sont ordonn�es par ordre croissant en entr�e. La liste r�sultante est aussi ordonn�e par ordre croissant.
 *
 * Utilise la fct estPlusPetitOuEgal pour les comparaisons 1 � 1.
 *
 * On suppose que estPlusPetitOuEgal(a1,a2) renvoie true si a1 <= a2 o� <= est une relation d'ordre sur T et renvoie false si a1 > a2
 *
 * DONNEES : p1 et p2
 * RESULTATS: P1 et p2
 *
 * */
template <class T>
void fusion(PElement<T> * & p1, PElement<T> * & p2, bool(*estPlusPetitOuEgal)(const T * a1, const T * a2))
{
	if (!p2) return; // p2 est vide, il n'y a rien � faire

	if (!p1) // p1 est vide et p2 ne l'est pas
	{
		p1 = p2; p2 = NULL;
		return;
	}

	// � pr�sent, p1 et p2 sont non vides

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
 * trie p par tri r�cursif dichotomique (trifusion)
 *
 * ne cr�e pas de nouveau maillon. La liste originale p est modifi�e
 *
 * Utilise la fct estPlusPetitOuEgal pour les comparaisons 1 � 1.
 *
 * range les �l�ments par ordre croissant
 *
 * On suppose que estPlusPetitOuEgal(a1,a2) renvoie true si a1 <= a2 o� <= est une relation d'ordre sur T et renvoie false si a1 > a2
 *
 * DONNEES : p
 * RESULTATS : p modifi�e
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




