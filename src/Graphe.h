#pragma once

/**
Motivations qui ont conduit ï¿½ cette solution pour reprï¿½senter un graphe :

hypothï¿½ses : Un graphe est non orientï¿½. Dans le cas gï¿½nï¿½ral, une information est associï¿½e ï¿½ chaque sommet, ï¿½ chaque arï¿½te : un nom, un nï¿½, une couleur, etc.

J'ignore totalement la nature de cette information, d'oï¿½ template <S,T>.
S : info associï¿½e ï¿½ une arï¿½te
T : info associï¿½e ï¿½ un sommet

chaque ï¿½lï¿½ment du graphe est identifiï¿½ par une clef unique. Celle-ci est gï¿½nï¿½rï¿½e automatiquement par l'attribut prochaineClef du graphe.
Celle-ci dï¿½finit ï¿½ tout instant la clef qui sera attribuï¿½e au prochain ï¿½lï¿½ment crï¿½ï¿½ dans le graphe.

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

	/** la  clef qui sera attribuï¿½e au prochain ï¿½lï¿½ment (sommet ou arï¿½te) crï¿½ï¿½ dans le graphe par les mï¿½thodes creeSommet(info)
	ou creeArete(info,debut,fin) fonctionne comme auto-increment d'une base de donnï¿½es */

	int prochaineClef;

public:

	PElement< Sommet<T> > * lSommets; // liste de sommets
	PElement< Arete<S, T> > * lAretes; // liste d'arï¿½tes

	//------------------- opï¿½rations de crï¿½ation ----------------------------------------------

private:

	/**
	 * crï¿½e un sommet isolï¿½.
	 * Attention : on suppose que clef est valide (c'est-ï¿½-dire qu'elle
	 *											n'est pas dï¿½jï¿½ utilisï¿½e par un ï¿½lï¿½ment (sommet ou arï¿½te) prï¿½sent dans le graphe)
	 *
	 * Ne met pas ï¿½ jour prochaineClef
	 * */
	Sommet<T> * creeSommet1(const int clef, const T & info);

	/**
	 * utilisï¿½e par les mï¿½thodes qui crï¿½ent des ï¿½lï¿½ments (Sommet ou Arï¿½te) en utilisant une clef imposï¿½e ï¿½ l'appel, c'est-ï¿½-dire les mï¿½thodes
	 * creeSommet(clef,info) et creeArete(clef, info, debut, fin)
	 *
	 * met  ï¿½ jour prochaineClef
	 * */

	void majProchaineClef(const int clef) {
		 prochaineClef = max(1 + clef, prochaineClef);
	 }

	/**
	 * crï¿½e un sommet isolï¿½
	 *
	 * Attention : on suppose que clef est valide (c'est-ï¿½-dire qu'elle
	 *											n'est pas dï¿½jï¿½ utilisï¿½e par un ï¿½lï¿½ment (sommet ou arï¿½te) prï¿½sent dans le graphe)
	 * Utilisï¿½e dans la mï¿½thode copie()
	 *
	 * met ï¿½ jour prochaineClef
	 * */
	Sommet<T> * creeSommet(const int clef, const T & info) { majProchaineClef(clef); return creeSommet1(clef, info); }

public:
	/**
	 * crï¿½e un sommet isolï¿½
	 * met ï¿½ jour prochaineClef
	 * */
	Sommet<T> * creeSommet(const T & info) { return creeSommet1(prochaineClef++, info); }

private:

	/**
	 * crï¿½e une arï¿½te joignant les 2 sommets debut et fin
	 *
	 * met ï¿½ jour les champs degre de debut et de fin
	 *
	 * Ne met pas ï¿½ jour prochaineClef
	 *
	 * */

	Arete<S, T> * creeArete1(const int clef, const S & info, Sommet<T> * debut, Sommet<T> * fin);

	/**
	 * crï¿½e une arï¿½te joignant les 2 sommets debut et fin
	 *
	 * met ï¿½ jour les champs degre de debut et de fin
	 *
	 * Attention : on suppose que clef est valide (c'est-ï¿½-dire qu'elle
	 *											n'est pas dï¿½jï¿½ utilisï¿½e par un ï¿½lï¿½ment (sommet ou arï¿½te) prï¿½sent dans le graphe)
	 *
	 * met ï¿½ jour prochaineClef
	 * */

	Arete<S, T> * creeArete(const int clef, const S & info, Sommet<T> * debut, Sommet<T> * fin)
	{
		majProchaineClef(clef);
		return creeArete1(clef, info, debut, fin);
	}

public:
	/**
	 * crï¿½e une arï¿½te joignant les 2 sommets debut et fin
	 *
	 * met ï¿½ jour les champs degre de debut et de fin
	 *
	 * met ï¿½ jour prochaineClef
	 *
	 * */

	Arete<S, T> * creeArete(const S & info, Sommet<T> * debut, Sommet<T> * fin) { return creeArete1(prochaineClef++, info, debut, fin); }

private:
	/*
	* Recopie graphe dans *this : utilisï¿½ par le constructeur de copie et par l'opï¿½rateur =
	*
	* Attention : suppose que *this est VIDE avant l'appel, c'est-ï¿½-dire que lSommets == lAretes == NULL et que prochaineClef == 0
	*
	*/

	void copie(const Graphe<S, T> & graphe);

	/*
	* utilisï¿½ par l'opï¿½rateur = et par le destructeur
	*/
	void effaceTout();

public:

	/**
	 * crï¿½e un graphe vide
	 *
	 * */
	Graphe() : prochaineClef(0), lSommets(NULL), lAretes(NULL) {}

	Graphe(const Graphe<S, T> & graphe) : Graphe() { this->copie(graphe); }

	const Graphe<S, T> & operator = (const Graphe<S, T> & graphe) { this->effaceTout(); this->copie(graphe); return *this; }


	//------------------- destructeur ----------------------------------------------

	~Graphe() { this->effaceTout(); }


	//------------------- opï¿½rations de consultation ----------------------------------------------

	int nombreSommets() const { return PElement< Sommet<T> >::taille(lSommets); }
	int nombreAretes() const { return PElement< Arete<S, T> >::taille(lAretes); }


	/**

	recherche la liste des paires (voisin, arï¿½te) adjacentes de sommet dans le graphe

	*/
	PElement< pair< Sommet<T> *, Arete<S, T>* > >  *  adjacences(const Sommet<T> * sommet) const;
	PElement< Arete<S, T> > *  aretesAdjacentes(const Sommet<T> * sommet) const;
	PElement< Sommet<T> > *  voisins(const Sommet<T> * sommet) const;

	/**
	 * cherche l'arï¿½te s1 - s2 ou l'arï¿½te s2 - s1 si elle existe
	 *
	 * DONNEES : s1 et s2 deux sommets quelconques du graphe
	 * RESULTATS : l'arï¿½te s'appuyant sur s1 et s2 si elle existe, NULL sinon
	 *
	 * */
	Arete<S, T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const;

	operator string() const;

	/**
	dessine toutes les arï¿½tes du graphe de maniï¿½re indï¿½pendante de la librairie graphique utilisï¿½e

	Attention ! ici, FENETRE reprï¿½sente n'importe quelle classe munie de la mï¿½thode appelï¿½e.
	On n'a pas forcï¿½ment FENETRE == Fenetre<S,T> !
	Cette solution est plus gï¿½nï¿½rale
	renvoie true en cas de succï¿½s complet, false en cas d'ï¿½chec partiel
	*/
	template< class FENETRE>
	bool dessineToutesAretes(FENETRE & fenetre) const;

	/**
	dessine tous les sommets du graphe de maniï¿½re indï¿½pendante de la librairie graphique utilisï¿½e

	Attention ! ici, FENETRE reprï¿½sente n'importe quelle classe munie de la mï¿½thode appelï¿½e.
	On n'a pas forcï¿½ment FENETRE == Fenetre<S,T> !
	Cette solution est plus gï¿½nï¿½rale
	renvoie true en cas de succï¿½s complet, false en cas d'ï¿½chec partiel
	*/

	template< class FENETRE>
	bool dessineTousSommets(FENETRE & fenetre) const;

	/**
	dessine le graphe de maniï¿½re indï¿½pendante de la librairie graphique utilisï¿½e

	Attention ! ici, FENETRE reprï¿½sente n'importe quelle classe munie des 2 mï¿½thodes appelï¿½es.
	On n'a pas forcï¿½ment FENETRE == Fenetre<S,T> !
	Cette solution est plus gï¿½nï¿½rale
	renvoie true en cas de succï¿½s complet, false en cas d'ï¿½chec partiel
	*/
	template  <class FENETRE>
	bool dessine(FENETRE & fenetre) const;

	//---------------------- Graphe ----------------------------------
};

template <class S, class T>
ostream & operator << (ostream & os, const Graphe<S, T> & gr) { return os << (string)gr; }

/**
 * crï¿½e un sommet isolï¿½.
 * Attention : on suppose que clef est valide (c'est-ï¿½-dire qu'elle
 *											n'est pas dï¿½jï¿½ utilisï¿½e par un ï¿½lï¿½ment (sommet ou arï¿½te) prï¿½sent dans le graphe)
 *
 * Ne met pas ï¿½ jour prochaineClef
 * */
template <class S, class T>
Sommet<T> * Graphe<S, T>::creeSommet1(const int clef, const T & info)
{
	Sommet<T> * sommetCree = new Sommet<T>(clef, info);
	lSommets = new PElement< Sommet<T> >(sommetCree, lSommets);

	return sommetCree;
}

/**
 * crï¿½e une arï¿½te joignant les 2 sommets debut et fin
 *
 * met ï¿½ jour les champs degre de debut et de fin
 *
 * Ne gï¿½re pas prochaineClef
 *
 * */
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

/**
 * crï¿½e une arï¿½te joignant les 2 sommets debut et fin
 *
 * met ï¿½ jour les champs degre de debut et de fin
 *
 * Attention : on suppose que clef est valide (c'est-ï¿½-dire qu'elle
 *											n'est pas dï¿½jï¿½ utilisï¿½e par un ï¿½lï¿½ment (sommet ou arï¿½te) prï¿½sent dans le graphe)
 *
 * met ï¿½ jour prochaineClef
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
 utile pour les opï¿½rations de copie d'un graphe
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
* Recopie graphe dans *this : utilisï¿½ par le constructeur de copie et par l'opï¿½rateur =
*
* Attention : suppose que *this est VIDE avant l'appel, c'est-ï¿½-dire que lSommets == lAretes == NULL et que prochaineClef == 0
*
*/
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

/**
 * crï¿½e un sommet isolï¿½.
 *
 * ancienne version qui ne prend pas en compte le ctor de copie ni l'opï¿½rateur =
 * Gï¿½re prochaineClef
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
  * crï¿½e une arï¿½te joignant les 2 sommets debut et fin
  *
  * met ï¿½ jour les champs degre de debut et de fin
  *
  * ancienne version qui ne prend pas en compte le ctor de copie ni l'opï¿½rateur =
  * */
  /*template <class S, class T>
  Arete<S,T> * Graphe<S,T>::creeArete( const S & info, Sommet<T> * debut, Sommet<T> * fin)
  {

  // ici tester que les 2 sommets sont bien existants dans le graphe
  if (! PElement< Sommet<T> >::appartient(debut,lSommets) ) throw Erreur("dï¿½but d'arï¿½te non dï¿½fini");
  if (! PElement< Sommet<T> >::appartient(fin,lSommets)) throw Erreur("fin d'arï¿½te non dï¿½finie");

  Arete<S,T> * nouvelleArete = new Arete<S,T>( prochaineClef++, debut, fin,  info);

  lAretes = new PElement< Arete<S,T> >( nouvelleArete, lAretes);

  return nouvelleArete;
  }
  */

  /**

  recherche la liste des paires (voisin, arï¿½te) adjacentes de sommet dans le graphe

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
 * cherche l'arï¿½te s1 - s2 ou l'arï¿½te s2 - s1 si elle existe
 *
 * DONNEES : s1 et s2 deux sommets quelconques du graphe
 * RESULTATS : l'arï¿½te s'appuyant sur s1 et s2 si elle existe, NULL sinon
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

	oss << "nombre d'arï¿½tes = " << this->nombreAretes() << "\n";

	oss << PElement<Arete<S, T> >::toString(lAretes, "", "\n", "\n");
	oss << ")";
	return oss.str();
}

/**
dessine toutes les arï¿½tes du graphe de maniï¿½re indï¿½pendante de la librairie graphique utilisï¿½e

Attention ! ici, FENETRE reprï¿½sente n'importe quelle classe munie de la mï¿½thode appelï¿½e.
On n'a pas forcï¿½ment FENETRE == Fenetre<S,T> !
Cette solution est plus gï¿½nï¿½rale
renvoie true en cas de succï¿½s complet, false en cas d'ï¿½chec partiel
*/
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

/**
dessine tous les sommets du graphe de maniï¿½re indï¿½pendante de la librairie graphique utilisï¿½e

Attention ! ici, FENETRE reprï¿½sente n'importe quelle classe munie de la mï¿½thode appelï¿½e.
On n'a pas forcï¿½ment FENETRE == Fenetre<S,T> !
Cette solution est plus gï¿½nï¿½rale
renvoie true en cas de succï¿½s complet, false en cas d'ï¿½chec partiel
*/
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

/**
dessine le graphe de maniï¿½re indï¿½pendante de la librairie graphique utilisï¿½e

Attention ! ici, FENETRE reprï¿½sente n'importe quelle classe munie des 2 mï¿½thodes appelï¿½es.
On n'a pas forcï¿½ment FENETRE == Fenetre<S,T> !
Cette solution est plus gï¿½nï¿½rale
renvoie true en cas de succï¿½s complet, false en cas d'ï¿½chec partiel
*/
template <class S, class T>
template< class FENETRE>
bool Graphe<S, T>::dessine(FENETRE & fenetre) const
{

	// ------------------------ on dessine les arï¿½tes --------------------------

	if (!this->dessineToutesAretes(fenetre)) return false;

	// ------------------------ on dessine les sommets --------------------------

	return this->dessineTousSommets(fenetre);
}

/**
dessine le chemin "chemin" sur la fenï¿½tre "fenï¿½tre" en utilisant la couleur "couleur"
et de maniï¿½re indï¿½pendante de la librairie graphique utilisï¿½e.
Suppose que les coordonnï¿½es des sommets sont dï¿½finies par rapport au repï¿½re monde

Attention ! ici, FENETRE reprï¿½sente n'importe quelle classe munie de la mï¿½thode appelï¿½e.
On n'a pas forcï¿½ment FENETRE == Fenetre<S,T> !
Cette solution est plus gï¿½nï¿½rale
renvoie true en cas de succï¿½s complet, false en cas d'ï¿½chec partiel
*/
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


/**
dessine le graphe de maniï¿½re indï¿½pendante de la librairie graphique utilisï¿½e

Attention ! ici, FENETRE reprï¿½sente n'importe quelle classe munie des 2 mï¿½thodes appelï¿½es.
On n'a pas forcï¿½ment FENETRE == Fenetre<S,T> !
Cette solution est plus gï¿½nï¿½rale
renvoie true en cas de succï¿½s complet, false en cas d'ï¿½chec partiel
* /
template <class S, class T>
template< class FENETRE>
bool Graphe<S,T>::dessine( FENETRE & fenetre) const
{

// ------------------------ on dessine les arï¿½tes --------------------------

PElement< Arete<S,T>> * pA;
for ( pA = this->lAretes; pA; pA = pA->s)
	if (!fenetre.dessine(pA->v)) return false; // tente de dessiner puis retourne false en cas d'ï¿½chec

// ------------------------ on dessine les sommets --------------------------

PElement< Sommet<T>> * pS;
for ( pS = this->lSommets; pS; pS = pS->s)
	if (!fenetre.dessine(pS->v)) return false;	// tente de dessiner puis retourne false en cas d'ï¿½chec

return true;
}*/


/*template <class S, class T>
template< class FENETRE>
bool Graphe<S,T>::dessine( const FENETRE & fenetre) const
{
// ------------------- on initialise le dessin : axes du repï¿½re, lï¿½gende, etc . -----------------

if (!fenetre.initDessin(*this, largeur, hauteur)) return false;	// tente de dessiner puis retourne false en cas d'ï¿½chec

// ------------------------ on dessine les arï¿½tes --------------------------

PElement< Arete<S,T>> * pA;
for ( pA = this->lAretes; pA; pA = pA->s)
	if (!fenetre.dessine(pA->v)) return false; // tente de dessiner puis retourne false en cas d'ï¿½chec

// ------------------------ on dessine les sommets --------------------------

PElement< Sommet<T>> * pS;
for ( pS = this->lSommets; pS; pS = pS->s)
	if (!fenetre.dessine(pS->v)) return false;	// tente de dessiner puis retourne false en cas d'ï¿½chec

// ---------------------------- on dessine la finition : un chemin, un circuit ï¿½ surligner, etc. --------------------

return fenetre.finitDessin(*this);
}*/




