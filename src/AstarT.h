#pragma once
#include <utility>
#include "Graphe.h"
#include "InfoArete.h"
#include "InfoSommet.h"

using namespace std;

template <class Graphe,class Sommet>
class AstarT : 
{
	
	void libereToutSommet(Graphe & graphe);

	double hh(const Sommet * s);

	PElement< pair<Sommet*, double> > * listeVoisins(const Sommet * s, const Graphe & graphe);

	Sommet * & pere(Sommet * sommet);

	int & etat(Sommet * sommet);


	double & c(Sommet * sommet);

	double & h(Sommet * sommet);

	double & g(Sommet * sommet);

	bool estFinal(const Sommet * sommet);

	static Sommet * aStar(Graphe & graphe, Sommet * depart, double(*hh)(const Sommet * s));




};
template <>
void AstarT <Graphe<InfoArete, InfoSommet>,Sommet<InfoSommet>>::libereToutSommet(Graphe<InfoArete, InfoSommet> & graphe) {

	PElement< Sommet<InfoSommet> > * lS = graphe.lSommets;
	while (lS) {
		lS->v->v.infoAStar.etat=LIBRE;
		lS = lS->s;
	}
}


template <>
PElement< pair<Sommet<InfoSommet>*, double> > * AstarT <Graphe<InfoArete, InfoSommet>, Sommet<InfoSommet>>::listeVoisins(const Sommet<InfoSommet> * s, const Graphe<InfoArete, InfoSommet> & graphe) {


}




Sommet<InfoSommet>* & pere(Sommet<InfoSommet> * sommet) {

	
//

}