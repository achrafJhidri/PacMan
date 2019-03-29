#pragma once


#include <utility>
#include "PElement.h"
#include "Erreur.h"
#include "Sommet.h"
#include "Arete.h"


/*
classe sachant dessiner un graphe

template <class S, class T> class Dessinateur; */

template <class S, class T>
class Graphe
{
protected:

	
	int prochaineClef;

public:

	PElement< Sommet<T> > * lSommets; // liste de sommets
	PElement< Arete<S, T> > * lAretes; // liste d'arï¿½tes

	//------------------- opï¿½rations de crï¿½ation ----------------------------------------------

private:


	Sommet<T> * creeSommet1(const int clef, const T & info);


	void majProchaineClef(const int clef) {
		 prochaineClef = max(1 + clef, prochaineClef);
	 }

	
	Sommet<T> * creeSommet(const int clef, const T & info) { majProchaineClef(clef); return creeSommet1(clef, info); }

public:
	
	Sommet<T> * creeSommet(const T & info) { return creeSommet1(prochaineClef++, info); }

	
	void stockVoisinageSommet( Sommet<T> * sommet);
	
	void majSommets(){
		PElement<Sommet<T>> * copieListeSommets = PElement<Sommet<T>>::copie1(lSommets);
		while(copieListeSommets){
			
			stockVoisinageSommet(copieListeSommets->v);

			copieListeSommets=copieListeSommets->s;
		}
	}
	

private:

	Arete<S, T> * creeArete1(const int clef, const S & info, Sommet<T> * debut, Sommet<T> * fin);

	

	Arete<S, T> * creeArete(const int clef, const S & info, Sommet<T> * debut, Sommet<T> * fin)
	{
		majProchaineClef(clef);
		return creeArete1(clef, info, debut, fin);
	}

public:

	Arete<S, T> * creeArete(const S & info, Sommet<T> * debut, Sommet<T> * fin) { return creeArete1(prochaineClef++, info, debut, fin); }

private:

	void copie(const Graphe<S, T> & graphe);


	void effaceTout();

public:


	Graphe() : prochaineClef(0), lSommets(NULL), lAretes(NULL) {}

	Graphe(const Graphe<S, T> & graphe) : Graphe() { this->copie(graphe); }

	const Graphe<S, T> & operator = (const Graphe<S, T> & graphe) { this->effaceTout(); this->copie(graphe); return *this; }


	//------------------- destructeur ----------------------------------------------

	~Graphe() { this->effaceTout(); }


	//------------------- opï¿½rations de consultation ----------------------------------------------

	int nombreSommets() const { return PElement< Sommet<T> >::taille(lSommets); }
	int nombreAretes() const { return PElement< Arete<S, T> >::taille(lAretes); }



	PElement< pair< Sommet<T> *, Arete<S, T>* > >  *  adjacences(const Sommet<T> * sommet) const;
	PElement< Arete<S, T> > *  aretesAdjacentes(const Sommet<T> * sommet) const;
	PElement< Sommet<T> > *  voisins(const Sommet<T> * sommet) const;

	
	Arete<S, T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const;

	operator string() const;

	
	template< class FENETRE>
	bool dessineToutesAretes(FENETRE & fenetre) const;


	template< class FENETRE>
	bool dessineTousSommets(FENETRE & fenetre) const;

	template  <class FENETRE>
	bool dessine(FENETRE & fenetre) const;

	//---------------------- Graphe ----------------------------------
};

template <class S, class T>
ostream & operator << (ostream & os, const Graphe<S, T> & gr) { return os << (string)gr; }


template <class S, class T>
Sommet<T> * Graphe<S, T>::creeSommet1(const int clef, const T & info)
{
	Sommet<T> * sommetCree = new Sommet<T>(clef, info);
	lSommets = new PElement< Sommet<T> >(sommetCree, lSommets);

	return sommetCree;
}


template <class S, class T>
Arete<S, T> * Graphe<S, T>::creeArete1(const int clef, const S & info, Sommet<T> * debut, Sommet<T> * fin)
{

	// ici tester que les 2 sommets sont bien existants dans le graphe
	if (!PElement< Sommet<T> >::appartient(debut, lSommets)) throw Erreur("dï¿½but d'arï¿½te non dï¿½fini");
	if (!PElement< Sommet<T> >::appartient(fin, lSommets)) throw Erreur("fin d'arï¿½te non dï¿½finie");

	Arete<S, T> *  nouvelleArete = new Arete<S, T>(clef, info, debut, fin);

	

	lAretes = new PElement< Arete<S, T> >(nouvelleArete, lAretes);

	return nouvelleArete;
}


template <class T>
class SommetDejaPresentDansLaCopie
{
public:
	const Sommet<T> * s;
	SommetDejaPresentDansLaCopie(const Sommet<T> * s) :s(s) {}
	bool operator () (const Sommet<T> * sommet) const { return sommet->clef == s->clef; }
};


template <class S, class T>
void Graphe<S, T>::copie(const Graphe<S, T> & graphe)
{
	const PElement<Sommet<T>> * pS;

	// -------------- d'abord on recopie les sommets --------------------

	for (pS = graphe.lSommets; pS; pS = pS->s)
	{									// parcourt les sommets du graphe "graphe" et les crï¿½e un par un dans *this en tant que sommets isolï¿½s
		const Sommet<T> * sommet = pS->v;				// sommet courant ï¿½ recopier
		this->creeSommet(sommet->clef, sommet->v);		// on crï¿½e la copie du sommet courant avec la mï¿½me clef
	}


	// -------------------- et maintenant on recopie les arï¿½tes --------------------

	// attention, la recopie des arï¿½tes est plus compliquï¿½e car il faut rebrancher les arï¿½tes sur les nouveaux sommets qui viennent d'ï¿½tre crï¿½ï¿½s.
	// Pour retrouver les "bons sommets" on utilise les clefs qui ont ï¿½tï¿½ conservï¿½es

	const PElement<Arete<S, T>> * pA;
	for (pA = graphe.lAretes; pA; pA = pA->s)	// parcourt les arï¿½tes de l'ancien graphe et les recopie une par une
	{
		const Arete<S, T> * a = pA->v;			// arï¿½te courante ï¿½ recopier
		Sommet<T> * d, *f;						// le dï¿½but et la fin de la nouvelle arï¿½te qui va ï¿½tre crï¿½ï¿½e
		PElement< Sommet<T> > * p;				// pour retrouver d et f dans la nouvelle liste de sommets grï¿½ce aux clefs qui ont ï¿½tï¿½ conservï¿½es

		// on recherche d dans la nouvelle liste de sommets grï¿½ce ï¿½ sa clef
		SommetDejaPresentDansLaCopie<T> conditionDebut(a->debut);
		p = PElement< Sommet<T> >::appartient(lSommets, conditionDebut);
		d = p->v;

		// on recherche f dans la nouvelle liste de sommets grï¿½ce ï¿½ sa clef
		SommetDejaPresentDansLaCopie<T> conditionFin(a->fin);
		p = PElement< Sommet<T> >::appartient(lSommets, conditionFin);
		f = p->v;

		this->creeArete(a->clef, a->v, d, f);
	}
}

/*
* utilisï¿½ par l'opï¿½rateur = et par le destructeur
*/
template <class S, class T>
void Graphe<S, T>::effaceTout()
{
	PElement< Arete<S, T>>::efface2(this->lAretes);
	PElement<Sommet<T> >::efface2(this->lSommets);
	this->prochaineClef = 0;
}


template <class S, class T>
PElement< pair< Sommet<T> *, Arete<S, T>* > >  *  Graphe<S, T>::adjacences(const Sommet<T> * sommet) const
{
	const PElement< Arete<S, T> > * l;

	PElement< pair< Sommet<T> *, Arete<S, T>* > > * r;				// pair< Sommet<T> *, Arete<S,T>* >

	for (l = lAretes, r = NULL; l; l = l->s)

		if (sommet == l->v->debut)
			r = new PElement< pair< Sommet<T> *, Arete<S, T>* > >(new pair< Sommet<T> *, Arete<S, T>* >(l->v->fin, l->v), r);
		else
			if (sommet == l->v->fin)
				r = new PElement< pair< Sommet<T> *, Arete<S, T>* > >(new pair< Sommet<T> *, Arete<S, T>* >(l->v->debut, l->v), r);

	return r;
}


template <class S, class T>
PElement< Arete<S, T> > *  Graphe<S, T>::aretesAdjacentes(const Sommet<T> * sommet) const
{
	PElement< pair< Sommet<T> *, Arete<S, T>* > > * ladj = this->adjacences(sommet);
	PElement< pair< Sommet<T> *, Arete<S, T>* > > * l;

	PElement< Arete<S, T> > * r;

	for (l = ladj, r = NULL; l; l = l->s)
		r = new PElement< Arete<S, T> >(l->v->second, r);

	PElement< pair< Sommet<T> *, Arete<S, T>* > >::efface2(ladj);

	return r;
}

template <class S, class T>
PElement< Sommet<T> > *  Graphe<S, T>::voisins(const Sommet<T> * sommet) const
{
	PElement< pair< Sommet<T> *, Arete<S, T>* > > * ladj = this->adjacences(sommet);
	PElement< pair< Sommet<T> *, Arete<S, T>* > > * l;

	PElement< Sommet<T> > * r;

	for (l = ladj, r = NULL; l; l = l->s)
		r = new PElement< Sommet<T> >(l->v->first, r);

	PElement< pair< Sommet<T> *, Arete<S, T>* > >::efface2(ladj);

	return r;
}

template <class S, class T>
Arete<S, T> * Graphe<S, T>::getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const
{
	PElement<Arete<S, T> > * l;

	for (l = this->lAretes; l; l = l->s)
		if (l->v->estEgal(s1, s2))
			return l->v;

	return NULL;
}


template <class S, class T>
Graphe<S, T>::operator string() const
{
	ostringstream oss;
	oss << "Graphe( \n";
	oss << "prochaine clef = " << this->prochaineClef << endl;
	oss << "nombre de sommets = " << this->nombreSommets() << "\n";

	oss << PElement<Sommet<T> >::toString(lSommets, "", "\n", "\n");

	oss << "nombre d'arï¿½tes = " << this->nombreAretes() << "\n";

	oss << PElement<Arete<S, T> >::toString(lAretes, "", "\n", "\n");
	oss << ")";
	return oss.str();
}

template <class S, class T>
template< class FENETRE>
bool Graphe<S, T>::dessineToutesAretes(FENETRE & fenetre) const
{

	// ------------------------ on dessine les arï¿½tes --------------------------

	PElement< Arete<S, T>> * pA;
	for (pA = this->lAretes; pA; pA = pA->s)
		if (!fenetre.dessine(pA->v)) return false; // tente de dessiner puis retourne false en cas d'ï¿½chec

	return true;
}


template <class S, class T>
template< class FENETRE>
bool Graphe<S, T>::dessineTousSommets(FENETRE & fenetre) const
{

	// ------------------------ on dessine les sommets --------------------------

	PElement< Sommet<T>> * pS;
	for (pS = this->lSommets; pS; pS = pS->s)
		if (!fenetre.dessine(pS->v)) return false;	// tente de dessiner puis retourne false en cas d'ï¿½chec

	return true;
}


template <class S, class T>
template< class FENETRE>
bool Graphe<S, T>::dessine(FENETRE & fenetre) const
{

	// ------------------------ on dessine les arï¿½tes --------------------------

	if (!this->dessineToutesAretes(fenetre)) return false;

	// ------------------------ on dessine les sommets --------------------------

	return this->dessineTousSommets(fenetre);
}

template <class T, class FENETRE>
bool dessine(const PElement<Sommet<T>> * chemin, FENETRE & fenetre, const unsigned int couleur)
{
	if (!(chemin && chemin->s)) // le chemin est vide ou ne contient qu'un sommet : il n'y  a rien ï¿½ dessiner
		return true;

	else		// le chemin contient au moins une arï¿½te
	{
		// on dessine d'abord la 1ï¿½re arï¿½te

		fenetre.dessine(chemin->v, chemin->s->v, couleur);

		return dessine(chemin->s, fenetre, couleur);		// puis on dessine les arï¿½tes suivantes
	}
}



template <class S,class T>
void Graphe<S, T>::stockVoisinageSommet( Sommet<T> * sommet) {
	PElement< Sommet<T> > * voisinsDuSommet = voisins(sommet);
	sommet->listVoisin=voisinsDuSommet;
}

