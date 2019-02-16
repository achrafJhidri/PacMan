
#include <iostream>
#include "PileTemplate.h"
#include "PElement.h"
#include "AElement.h"
#include "GElement.h"
#include "Sommet.h"
#include "Arete.h"
#include "Graphe.h"
#include "SommetPartieArete.h"
using namespace std;
// test
//hello everyody	

template <class T>
bool estPlusPetitOuEgal(const T * a1, const T * a2) {
	return (*a1) <= (*a2);
}
const string boolToString(const bool b) {
	return b ? "vrai" : "faux";
}
ostream & operator << (ostream & o, const bool b) { 
	return o << boolToString(b); 
}
template<class T>
ostream & operator <<(ostream & os, const PElement<T> * p) {
	os << PElement<T>::toString(p);
	return os;
}
template < class S, class T >
string toString(const pair <S, T> & p) {
	ostringstream os;
	os << "paire  [" << *p.first << "," << *p.second << "]";
	return os.str();
}
template <class S, class T>
ostream & operator <<(ostream & os, const pair<S, T> & p) {

	return os << toString(p);
}



int main()
{
#pragma region testGraphe
	Graphe<int, string> g;
	Sommet <string> * s1 = g.creeSommet("Achraf");
	Sommet <string> * s2 = g.creeSommet("Soufiane");
	Sommet <string> * s3 = g.creeSommet("Rania");
	Sommet <string> * s4 = g.creeSommet("Fatima");
	Sommet <string> * s5 = g.creeSommet("Brahim");

	Arete <int, string> *a = g.creeArete(33, s1, s2);
	Arete <int, string> *c = g.creeArete(33, s5, s2);
	Arete <int, string> *b = g.creeArete(33, s2, s3);

	//
	cout << g.getListeSommets() << endl; 
	cout <<"nombre de sommet " << g.nombreSommets()<< endl;
	//cout << g.getListeAretes() << endl;
	//cout << "nombre d'aretes " << g.nombreAretes()<< endl;


	//
	/*PElement < pair < Sommet<string> *, Arete<int, string> *> >  * listePairs = g.adjacences(s2);

		cout << listePairs << endl;*/


		/*PElement< Arete<int, string> > * listeArreteAdjacentes = g.aretesAdjacentes(s2);
		cout << listeArreteAdjacentes << endl;*/

		//PElement< Sommet<string> > * listeVoisins = g.voisins(s2);
		//cout << listeVoisins << endl;

		//Arete < int, string  > * arete = g.getAreteParSommets(s5, s2);
		//if ( arete != NULL )
		//	cout << *arete << endl;


#pragma endregion testGraphe

#pragma region testArete
	/*Sommet<string> * s1 = new  Sommet<string>(23, "Achraf");
	cout << *s1 << endl;

	Sommet<string> * s2 = new  Sommet<string>(11, "Soufiane");

	Sommet<string> * s3 = new  Sommet<string>(11, "Soufiane");

	cout << *s2 << endl;


	Arete<char, string> a(1,'m', s1,s2);

	cout << a << endl;
	cout << *s1 << endl;
	cout << *s2 << endl;


	cout << boolToString(a.estEgal(s2, s1)) << endl;
	cout << boolToString(a.estEgal(s2, s3)) << endl;*/
#pragma endregion testArete
#pragma region testSommet

	//cout << s << endl;
	//cout << "degre du sommet est :" <<s.getDegre() << endl;
	//s.setDegre(14);
	//cout << s << endl;

#pragma endregion testSommet
#pragma region testAElement
	/*AElement a(14);
	GElement<int> g(23231, 321);
	cout << g << endl;
	g.setClef(1111);
	g.setV(1111);
	cout << g << endl;*/
#pragma endregion testAElement
#pragma region testPElementList

	/*string m1 = "aaa";
	string m2 = "bbb";*/
	/*PElement<int> * l1 = new PElement<int>(NULL, new int(21));
	 l1 = new PElement<int>(l1, new int(19));
	 l1 = new PElement<int>(l1, new int(1));


	int taille = PElement<int>::taille(l1);
	cout << "taille :" <<taille << endl;

	cout << l1<< endl ;
	int * e = new int(5);
	PElement<int>::insertionOrdonnee(e, l1,PElement<int>::estPlusPetitOuEgal );
	PElement<int>::insertionOrdonnee(new int(143), l1, PElement<int>::estPlusPetitOuEgal);


	cout << l1 << endl;*/

	//int * x = PElement<int>::depiler(l1);
	//// x = PElement<int>::depiler(l1);

	//cout << *x << endl;
	//cout << l1 << endl;

	//bool x = PElement<int>::retire(new int (95),l1);
	//cout << boolToString(x) << endl;
	//cout << l1 << endl;


	/*PElement<int>::efface1( l1);
	cout << l1 << endl;
*/

/*PElement<int> * copie = PElement<int>::copie2(l1);

cout << copie << endl;*/


//PElement<int> * found = PElement<int>::appartient(e,l1);

//cout << found << endl;

#pragma endregion testPElementList


	system("pause");
	return 0;

}
