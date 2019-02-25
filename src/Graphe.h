#pragma once

/**
Motivations qui ont conduit � cette solution pour repr�senter un graphe :

hypoth�ses : Un graphe est non orient�. Dans le cas g�n�ral, une information est associ�e � chaque sommet, � chaque ar�te : un nom, un n�, une couleur, etc.

J'ignore totalement la nature de cette information, d'o� template <S,T>.
S : info associ�e � une ar�te
T : info associ�e � un sommet

chaque �l�ment du graphe est identifi� par une clef unique. Celle-ci est g�n�r�e automatiquement par l'attribut prochaineClef du graphe.
Celle-ci d�finit � tout instant la clef qui sera attribu�e au prochain �l�ment cr�� dans le graphe.

*/

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

	/** la  clef qui sera attribu�e au prochain �l�ment (sommet ou ar�te) cr�� dans le graphe par les m�thodes creeSommet(info)
	ou creeArete(info,debut,fin) fonctionne comme auto-increment d'une base de donn�es */

	int prochaineClef;

public:

	PElement< Sommet<T> > * lSommets; // liste de sommets
	PElement< Arete<S, T> > * lAretes; // liste d'ar�tes

	//------------------- op�rations de cr�ation ----------------------------------------------

private:

	/**
	 * cr�e un sommet isol�.
	 * Attention : on suppose que clef est valide (c'est-�-dire qu'elle
	 *											n'est pas d�j� utilis�e par un �l�ment (sommet ou ar�te) pr�sent dans le graphe)
	 *
	 * Ne met pas � jour prochaineClef
	 * */
	Sommet<T> * creeSommet1(const int clef, const T & info);

	/**
	 * utilis�e par les m�thodes qui cr�ent des �l�ments (Sommet ou Ar�te) en utilisant une clef impos�e � l'appel, c'est-�-dire les m�thodes
	 * creeSommet(clef,info) et creeArete(clef, info, debut, fin)
	 *
	 * met  � jour prochaineClef
	 * */

	void majProchaineClef(const int clef) {
		 prochaineClef = max(1 + clef, prochaineClef);
	 }

	/**
	 * cr�e un sommet isol�
	 *
	 * Attention : on suppose que clef est valide (c'est-�-dire qu'elle
	 *											n'est pas d�j� utilis�e par un �l�ment (sommet ou ar�te) pr�sent dans le graphe)
	 * Utilis�e dans la m�thode copie()
	 *
	 * met � jour prochaineClef
	 * */
	Sommet<T> * creeSommet(const int clef, const T & info) { majProchaineClef(clef); return creeSommet1(clef, info); }

public:
	/**
	 * cr�e un sommet isol�
	 * met � jour prochaineClef
	 * */
	Sommet<T> * creeSommet(const T & info) { return creeSommet1(prochaineClef++, info); }

private:

	/**
	 * cr�e une ar�te joignant les 2 sommets debut et fin
	 *
	 * met � jour les champs degre de debut et de fin
	 *
	 * Ne met pas � jour prochaineClef
	 *
	 * */

	Arete<S, T> * creeArete1(const int clef, const S & info, Sommet<T> * debut, Sommet<T> * fin);

	/**
	 * cr�e une ar�te joignant les 2 sommets debut et fin
	 *
	 * met � jour les champs degre de debut et de fin
	 *
	 * Attention : on suppose que clef est valide (c'est-�-dire qu'elle
	 *											n'est pas d�j� utilis�e par un �l�ment (sommet ou ar�te) pr�sent dans le graphe)
	 *
	 * met � jour prochaineClef
	 * */

	Arete<S, T> * creeArete(const int clef, const S & info, Sommet<T> * debut, Sommet<T> * fin)
	{
		majProchaineClef(clef);
		return creeArete1(clef, info, debut, fin);
	}

public:
	/**
	 * cr�e une ar�te joignant les 2 sommets debut et fin
	 *
	 * met � jour les champs degre de debut et de fin
	 *
	 * met � jour prochaineClef
	 *
	 * */

	Arete<S, T> * creeArete(const S & info, Sommet<T> * debut, Sommet<T> * fin) { return creeArete1(prochaineClef++, info, debut, fin); }

private:
	/*
	* Recopie graphe dans *this : utilis� par le constructeur de copie et par l'op�rateur =
	*
	* Attention : suppose que *this est VIDE avant l'appel, c'est-�-dire que lSommets == lAretes == NULL et que prochaineClef == 0
	*
	*/

	void copie(const Graphe<S, T> & graphe);

	/*
	* utilis� par l'op�rateur = et par le destructeur
	*/
	void effaceTout();

public:

	/**
	 * cr�e un graphe vide
	 *
	 * */
	Graphe() : prochaineClef(0), lSommets(NULL), lAretes(NULL) {}

	Graphe(const Graphe<S, T> & graphe) : Graphe() { this->copie(graphe); }

	const Graphe<S, T> & operator = (const Graphe<S, T> & graphe) { this->effaceTout(); this->copie(graphe); return *this; }


	//------------------- destructeur ----------------------------------------------

	~Graphe() { this->effaceTout(); }


	//------------------- op�rations de consultation ----------------------------------------------

	int nombreSommets() const { return PElement< Sommet<T> >::taille(lSommets); }
	int nombreAretes() const { return PElement< Arete<S, T> >::taille(lAretes); }


	/**

	recherche la liste des paires (voisin, ar�te) adjacentes de sommet dans le graphe

	*/
	PElement< pair< Sommet<T> *, Arete<S, T>* > >  *  adjacences(const Sommet<T> * sommet) const;
	PElement< Arete<S, T> > *  aretesAdjacentes(const Sommet<T> * sommet) const;
	PElement< Sommet<T> > *  voisins(const Sommet<T> * sommet) const;

	/**
	 * cherche l'ar�te s1 - s2 ou l'ar�te s2 - s1 si elle existe
	 *
	 * DONNEES : s1 et s2 deux sommets quelconques du graphe
	 * RESULTATS : l'ar�te s'appuyant sur s1 et s2 si elle existe, NULL sinon
	 *
	 * */
	Arete<S, T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const;

	operator string() const;

	/**
	dessine toutes les ar�tes du graphe de mani�re ind�pendante de la librairie graphique utilis�e

	Attention ! ici, FENETRE repr�sente n'importe quelle classe munie de la m�thode appel�e.
	On n'a pas forc�ment FENETRE == Fenetre<S,T> !
	Cette solution est plus g�n�rale
	renvoie true en cas de succ�s complet, false en cas d'�chec partiel
	*/
	template< class FENETRE>
	bool dessineToutesAretes(FENETRE & fenetre) const;

	/**
	dessine tous les sommets du graphe de mani�re ind�pendante de la librairie graphique utilis�e

	Attention ! ici, FENETRE repr�sente n'importe quelle classe munie de la m�thode appel�e.
	On n'a pas forc�ment FENETRE == Fenetre<S,T> !
	Cette solution est plus g�n�rale
	renvoie true en cas de succ�s complet, false en cas d'�chec partiel
	*/

	template< class FENETRE>
	bool dessineTousSommets(FENETRE & fenetre) const;

	/**
	dessine le graphe de mani�re ind�pendante de la librairie graphique utilis�e

	Attention ! ici, FENETRE repr�sente n'importe quelle classe munie des 2 m�thodes appel�es.
	On n'a pas forc�ment FENETRE == Fenetre<S,T> !
	Cette solution est plus g�n�rale
	renvoie true en cas de succ�s complet, false en cas d'�chec partiel
	*/
	template  <class FENETRE>
	bool dessine(FENETRE & fenetre) const;

	//---------------------- Graphe ----------------------------------
};

template <class S, class T>
ostream & operator << (ostream & os, const Graphe<S, T> & gr) { return os << (string)gr; }

/**
 * cr�e un sommet isol�.
 * Attention : on suppose que clef est valide (c'est-�-dire qu'elle
 *											n'est pas d�j� utilis�e par un �l�ment (sommet ou ar�te) pr�sent dans le graphe)
 *
 * Ne met pas � jour prochaineClef
 * */
template <class S, class T>
Sommet<T> * Graphe<S, T>::creeSommet1(const int clef, const T & info)
{
	Sommet<T> * sommetCree = new Sommet<T>(clef, info);
	lSommets = new PElement< Sommet<T> >(sommetCree, lSommets);

	return sommetCree;
}

/**
 * cr�e une ar�te joignant les 2 sommets debut et fin
 *
 * met � jour les champs degre de debut et de fin
 *
 * Ne g�re pas prochaineClef
 *
 * */
template <class S, class T>
Arete<S, T> * Graphe<S, T>::creeArete1(const int clef, const S & info, Sommet<T> * debut, Sommet<T> * fin)
{

	// ici tester que les 2 sommets sont bien existants dans le graphe
	if (!PElement< Sommet<T> >::appartient(debut, lSommets)) throw Erreur("d�but d'ar�te non d�fini");
	if (!PElement< Sommet<T> >::appartient(fin, lSommets)) throw Erreur("fin d'ar�te non d�finie");

	Arete<S, T> *  nouvelleArete = new Arete<S, T>(clef, info, debut, fin);

	lAretes = new PElement< Arete<S, T> >(nouvelleArete, lAretes);

	return nouvelleArete;
}

/**
 * cr�e une ar�te joignant les 2 sommets debut et fin
 *
 * met � jour les champs degre de debut et de fin
 *
 * Attention : on suppose que clef est valide (c'est-�-dire qu'elle
 *											n'est pas d�j� utilis�e par un �l�ment (sommet ou ar�te) pr�sent dans le graphe)
 *
 * met � jour prochaineClef
 *
 * */
 /*template <class S, class T>
 Arete<S,T> * Graphe<S,T>::creeArete( const int clef, const S & info, Sommet<T> * debut, Sommet<T> * fin)
 {
 majProchaineClef(clef);
 return creeArete1(clef,info,debut,fin);
 }
 */

 /**
 utile pour les op�rations de copie d'un graphe
 */
template <class T>
class SommetDejaPresentDansLaCopie
{
public:
	const Sommet<T> * s;
	SommetDejaPresentDansLaCopie(const Sommet<T> * s) :s(s) {}
	bool operator () (const Sommet<T> * sommet) const { return sommet->clef == s->clef; }
};

/*
* Recopie graphe dans *this : utilis� par le constructeur de copie et par l'op�rateur =
*
* Attention : suppose que *this est VIDE avant l'appel, c'est-�-dire que lSommets == lAretes == NULL et que prochaineClef == 0
*
*/
template <class S, class T>
void Graphe<S, T>::copie(const Graphe<S, T> & graphe)
{
	const PElement<Sommet<T>> * pS;

	// -------------- d'abord on recopie les sommets --------------------

	for (pS = graphe.lSommets; pS; pS = pS->s)
	{									// parcourt les sommets du graphe "graphe" et les cr�e un par un dans *this en tant que sommets isol�s
		const Sommet<T> * sommet = pS->v;				// sommet courant � recopier
		this->creeSommet(sommet->clef, sommet->v);		// on cr�e la copie du sommet courant avec la m�me clef
	}


	// -------------------- et maintenant on recopie les ar�tes --------------------

	// attention, la recopie des ar�tes est plus compliqu�e car il faut rebrancher les ar�tes sur les nouveaux sommets qui viennent d'�tre cr��s.
	// Pour retrouver les "bons sommets" on utilise les clefs qui ont �t� conserv�es

	const PElement<Arete<S, T>> * pA;
	for (pA = graphe.lAretes; pA; pA = pA->s)	// parcourt les ar�tes de l'ancien graphe et les recopie une par une
	{
		const Arete<S, T> * a = pA->v;			// ar�te courante � recopier
		Sommet<T> * d, *f;						// le d�but et la fin de la nouvelle ar�te qui va �tre cr��e
		PElement< Sommet<T> > * p;				// pour retrouver d et f dans la nouvelle liste de sommets gr�ce aux clefs qui ont �t� conserv�es

		// on recherche d dans la nouvelle liste de sommets gr�ce � sa clef
		SommetDejaPresentDansLaCopie<T> conditionDebut(a->debut);
		p = PElement< Sommet<T> >::appartient(lSommets, conditionDebut);
		d = p->v;

		// on recherche f dans la nouvelle liste de sommets gr�ce � sa clef
		SommetDejaPresentDansLaCopie<T> conditionFin(a->fin);
		p = PElement< Sommet<T> >::appartient(lSommets, conditionFin);
		f = p->v;

		this->creeArete(a->clef, a->v, d, f);
	}
}

/*
* utilis� par l'op�rateur = et par le destructeur
*/
template <class S, class T>
void Graphe<S, T>::effaceTout()
{
	PElement< Arete<S, T>>::efface2(this->lAretes);
	PElement<Sommet<T> >::efface2(this->lSommets);
	this->prochaineClef = 0;
}

/**
 * cr�e un sommet isol�.
 *
 * ancienne version qui ne prend pas en compte le ctor de copie ni l'op�rateur =
 * G�re prochaineClef
 *
 * */
 /*template <class S, class T>
 Sommet<T> * Graphe<S,T>::creeSommet( const T & info)
 {
 Sommet<T> * sommetCree = new Sommet<T>( prochaineClef++,info);
 lSommets = new PElement< Sommet<T> >( sommetCree, lSommets);

 return sommetCree;
 }
 */


 /**
  * cr�e une ar�te joignant les 2 sommets debut et fin
  *
  * met � jour les champs degre de debut et de fin
  *
  * ancienne version qui ne prend pas en compte le ctor de copie ni l'op�rateur =
  * */
  /*template <class S, class T>
  Arete<S,T> * Graphe<S,T>::creeArete( const S & info, Sommet<T> * debut, Sommet<T> * fin)
  {

  // ici tester que les 2 sommets sont bien existants dans le graphe
  if (! PElement< Sommet<T> >::appartient(debut,lSommets) ) throw Erreur("d�but d'ar�te non d�fini");
  if (! PElement< Sommet<T> >::appartient(fin,lSommets)) throw Erreur("fin d'ar�te non d�finie");

  Arete<S,T> * nouvelleArete = new Arete<S,T>( prochaineClef++, debut, fin,  info);

  lAretes = new PElement< Arete<S,T> >( nouvelleArete, lAretes);

  return nouvelleArete;
  }
  */

  /**

  recherche la liste des paires (voisin, ar�te) adjacentes de sommet dans le graphe

  */
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

/**
 * cherche l'ar�te s1 - s2 ou l'ar�te s2 - s1 si elle existe
 *
 * DONNEES : s1 et s2 deux sommets quelconques du graphe
 * RESULTATS : l'ar�te s'appuyant sur s1 et s2 si elle existe, NULL sinon
 *
 * */
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

	oss << "nombre d'ar�tes = " << this->nombreAretes() << "\n";

	oss << PElement<Arete<S, T> >::toString(lAretes, "", "\n", "\n");
	oss << ")";
	return oss.str();
}

/**
dessine toutes les ar�tes du graphe de mani�re ind�pendante de la librairie graphique utilis�e

Attention ! ici, FENETRE repr�sente n'importe quelle classe munie de la m�thode appel�e.
On n'a pas forc�ment FENETRE == Fenetre<S,T> !
Cette solution est plus g�n�rale
renvoie true en cas de succ�s complet, false en cas d'�chec partiel
*/
template <class S, class T>
template< class FENETRE>
bool Graphe<S, T>::dessineToutesAretes(FENETRE & fenetre) const
{

	// ------------------------ on dessine les ar�tes --------------------------

	PElement< Arete<S, T>> * pA;
	for (pA = this->lAretes; pA; pA = pA->s)
		if (!fenetre.dessine(pA->v)) return false; // tente de dessiner puis retourne false en cas d'�chec

	return true;
}

/**
dessine tous les sommets du graphe de mani�re ind�pendante de la librairie graphique utilis�e

Attention ! ici, FENETRE repr�sente n'importe quelle classe munie de la m�thode appel�e.
On n'a pas forc�ment FENETRE == Fenetre<S,T> !
Cette solution est plus g�n�rale
renvoie true en cas de succ�s complet, false en cas d'�chec partiel
*/
template <class S, class T>
template< class FENETRE>
bool Graphe<S, T>::dessineTousSommets(FENETRE & fenetre) const
{

	// ------------------------ on dessine les sommets --------------------------

	PElement< Sommet<T>> * pS;
	for (pS = this->lSommets; pS; pS = pS->s)
		if (!fenetre.dessine(pS->v)) return false;	// tente de dessiner puis retourne false en cas d'�chec

	return true;
}

/**
dessine le graphe de mani�re ind�pendante de la librairie graphique utilis�e

Attention ! ici, FENETRE repr�sente n'importe quelle classe munie des 2 m�thodes appel�es.
On n'a pas forc�ment FENETRE == Fenetre<S,T> !
Cette solution est plus g�n�rale
renvoie true en cas de succ�s complet, false en cas d'�chec partiel
*/
template <class S, class T>
template< class FENETRE>
bool Graphe<S, T>::dessine(FENETRE & fenetre) const
{

	// ------------------------ on dessine les ar�tes --------------------------

	if (!this->dessineToutesAretes(fenetre)) return false;

	// ------------------------ on dessine les sommets --------------------------

	return this->dessineTousSommets(fenetre);
}

/**
dessine le chemin "chemin" sur la fen�tre "fen�tre" en utilisant la couleur "couleur"
et de mani�re ind�pendante de la librairie graphique utilis�e.
Suppose que les coordonn�es des sommets sont d�finies par rapport au rep�re monde

Attention ! ici, FENETRE repr�sente n'importe quelle classe munie de la m�thode appel�e.
On n'a pas forc�ment FENETRE == Fenetre<S,T> !
Cette solution est plus g�n�rale
renvoie true en cas de succ�s complet, false en cas d'�chec partiel
*/
template <class T, class FENETRE>
bool dessine(const PElement<Sommet<T>> * chemin, FENETRE & fenetre, const unsigned int couleur)
{
	if (!(chemin && chemin->s)) // le chemin est vide ou ne contient qu'un sommet : il n'y  a rien � dessiner
		return true;

	else		// le chemin contient au moins une ar�te
	{
		// on dessine d'abord la 1�re ar�te

		fenetre.dessine(chemin->v, chemin->s->v, couleur);

		return dessine(chemin->s, fenetre, couleur);		// puis on dessine les ar�tes suivantes
	}
}


/**
dessine le graphe de mani�re ind�pendante de la librairie graphique utilis�e

Attention ! ici, FENETRE repr�sente n'importe quelle classe munie des 2 m�thodes appel�es.
On n'a pas forc�ment FENETRE == Fenetre<S,T> !
Cette solution est plus g�n�rale
renvoie true en cas de succ�s complet, false en cas d'�chec partiel
* /
template <class S, class T>
template< class FENETRE>
bool Graphe<S,T>::dessine( FENETRE & fenetre) const
{

// ------------------------ on dessine les ar�tes --------------------------

PElement< Arete<S,T>> * pA;
for ( pA = this->lAretes; pA; pA = pA->s)
	if (!fenetre.dessine(pA->v)) return false; // tente de dessiner puis retourne false en cas d'�chec

// ------------------------ on dessine les sommets --------------------------

PElement< Sommet<T>> * pS;
for ( pS = this->lSommets; pS; pS = pS->s)
	if (!fenetre.dessine(pS->v)) return false;	// tente de dessiner puis retourne false en cas d'�chec

return true;
}*/


/*template <class S, class T>
template< class FENETRE>
bool Graphe<S,T>::dessine( const FENETRE & fenetre) const
{
// ------------------- on initialise le dessin : axes du rep�re, l�gende, etc . -----------------

if (!fenetre.initDessin(*this, largeur, hauteur)) return false;	// tente de dessiner puis retourne false en cas d'�chec

// ------------------------ on dessine les ar�tes --------------------------

PElement< Arete<S,T>> * pA;
for ( pA = this->lAretes; pA; pA = pA->s)
	if (!fenetre.dessine(pA->v)) return false; // tente de dessiner puis retourne false en cas d'�chec

// ------------------------ on dessine les sommets --------------------------

PElement< Sommet<T>> * pS;
for ( pS = this->lSommets; pS; pS = pS->s)
	if (!fenetre.dessine(pS->v)) return false;	// tente de dessiner puis retourne false en cas d'�chec

// ---------------------------- on dessine la finition : un chemin, un circuit � surligner, etc. --------------------

return fenetre.finitDessin(*this);
}*/




