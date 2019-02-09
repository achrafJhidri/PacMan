#pragma once
#include "PElement.h"
#include "Sommet.h"
#include "Arete.h"
#include <utility> 
#include "SommetPartieArete.h"
//template <class S, class T>
//using Paire = std::pair<Sommet<T> *, Arete<S, T> *>;


template<class S ,class T>
class Graphe
{
	PElement<Sommet<T>> * lSommets;
	PElement<Arete<S, T>> * lAretes;
	unsigned int prochaineClef;

public:

	
	Graphe() {
		lSommets = NULL;
		lAretes = NULL;
		prochaineClef = 0;
	};
	~Graphe() {};
	Sommet<T> * creeSommet(const T & info) {
		lSommets = new PElement<Sommet<T>>(lSommets, new Sommet<T>(++prochaineClef, info));

		return lSommets->v;
	}

	Arete<S, T> * creeArete(const S & info, Sommet<T> * debut, Sommet<T> * fin) {
		lAretes = new PElement<Arete<S, T>>(lAretes, new Arete<S, T>(++prochaineClef, info, debut, fin));
		return lAretes->v;
		
	}

	/*const*/ PElement <Sommet<T>> * getListeSommets()const {
		return lSommets;
	}
	/*const*/ PElement <Arete<S,T>> * getListeAretes()const {
		return lAretes;
	}

	int nombreSommets()const {
		return PElement<Sommet<T>>::taille(lSommets);
	}
	int nombreAretes()const {
		return PElement<Arete<S,T>>::taille(lAretes);
	}

	operator string() const {
		ostringstream os;
		os << "Graphe [ " << endl <<"liste des Sommets "<< lSommets << endl << "liste des Aretes" << lAretes << endl <<"]" ;
		return os.str();
	}
	friend ostream& operator <<(ostream & f, const Graphe<S, T> & g) {
		return f << string(g);
	}

	PElement< pair< Sommet<T> *, Arete<S, T> *> > * adjacences(const Sommet<T> * sommet)const {
		// on verifie si le sommet fait partie des sommets du graphe
		if (PElement<Sommet<T>>::appartient(sommet, lSommets) == NULL)
				return NULL;


	
		// on déclare une liste de pair vide
		PElement< pair < Sommet<T> *, Arete<S, T> *>  > * listePair = NULL;

			// on fait une copie avec partage de valeur 
			 PElement<Arete<S, T>> * copie = this->getListeAretes();
			
			  
			while (copie != NULL) {
						if (copie->v->getDebut() == sommet) {
							
							pair< Sommet<T> *, Arete<S, T> *> * paire=new pair< Sommet<T> *, Arete<S, T> *>(copie->v->getFin(), copie->v);
				
							listePair = new PElement< pair < Sommet<T>*, Arete<S,T>*  >>(listePair, paire);
						}
						else if (copie->v->getFin() == sommet) {
							
							pair< Sommet<T> *, Arete<S, T> *>* paire= new pair< Sommet<T> *, Arete<S, T> *>(copie->v->getDebut(), copie->v);
					
							listePair = new PElement< pair < Sommet<T> *, Arete<S, T> *>  >(listePair,paire);
						}

						copie = copie->s;
			}
			return listePair;
	}


PElement< Arete<S, T> > * aretesAdjacentes(const Sommet<T> * sommet)const {
	
	PElement < Arete<S, T> > * listeAretes = NULL;
	PElement< pair< Sommet<T> *, Arete<S, T> *> > * ListePairAdjcentes = adjacences(sommet);

	while (ListePairAdjcentes != NULL) {

		listeAretes = new PElement < Arete<S, T> >(listeAretes, ListePairAdjcentes->v->second);


		ListePairAdjcentes = ListePairAdjcentes->s;



	}
	return listeAretes;

}

PElement< Sommet< T> > * voisins(const Sommet<T> * sommet)const {

	PElement < Sommet< T> > * listeSommets = NULL;
	PElement< pair< Sommet<T> *, Arete<S, T> *> > * ListePairAdjcentes = adjacences(sommet);

	while (ListePairAdjcentes != NULL) {

		listeSommets = new PElement < Sommet< T> >(listeSommets, ListePairAdjcentes->v->first);


		ListePairAdjcentes = ListePairAdjcentes->s;



	}
	return listeSommets;

}




Arete < S, T > * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2)const {
	PElement<Arete<S, T>> * copie = this->getListeAretes();

	while (copie != NULL) {
		if (copie->v->estEgal(s1, s2))
			return copie->v;


		copie = copie->s;
	}
	return NULL;
}

};
