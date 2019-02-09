#include <string>
#include <sstream>

using namespace std;
/**
Liste g�n�rique de type LIFO
La capacit� max de la pile est de L �l�ments
*/
template <class T, int L>
class Pile
{

	int d;
	// -1 <= d <= L-1. d == -1 <===> la pile est vide. 
	// d == L-1 <===> la pile est pleine

	T p[L]; // Les �l�ments utilis�s sont p[0], p[1], ..., p[d]

public:

	/**
	cr�e une pile vide par d�faut
	*/
	Pile() : d(-1) {}

	/**
	cr�e une pile contenant un unique �l�ment
	*/
	Pile(const T & v);

	bool estVide() const { return d == -1; }

	/**
	retire l'�l�ment de t�te. Erreur si la pile est vide.
	*/
	const T depiler() { return p[d--]; }

	/**
	ins�re v en t�te de l. Erreur si la pile est pleine
	*/
	void empiler(const T & v) { p[++d] = v; }

	operator string () const;

	/**
	Exemple de m�thode membre template dans une classe
	Ici elle sert � assurer la compatibilit� avec une pile de taille diff�rente
	*/
	template <int L1>
	static const Pile<T, L> copie(const Pile<T, L1> & pile);

};

template <class T, int L>
Pile<T, L> ::Pile(const T & v) : Pile() { this->empiler(v); }

template <class T, int L>
Pile<T, L> :: operator string () const
{
	ostringstream o;

	int i;
	for (i = 0, o << "( "; i <= d; ++i)
			o << p[i] << ", ";

	o << ")";

	return o.str();

}


template <class T, int L>
ostream & operator << (ostream & o, const Pile<T, L> & pile)
{
	return o << (string)pile;
}


/**
Exemple de m�thode membre template dans une classe
Ici elle sert � asurer la compatibilit� avec une pile de taille diff�rente
*/
template <class T, int L>
template <int L1>
/*static*/
const Pile<T, L> Pile<T, L> ::copie(const Pile<T, L1> & pile)
{
	T t[L1];

	Pile<T, L> r;
	int m;
	for (m = 0; !pile.estVide(); ++m) t[m] = (const_cast<Pile<T, L1>&>(pile)).depiler();

	int i;
	for (i = m - 1; i >= 0; --i) { r.empiler(t[i]); (const_cast<Pile<T, L1>&>(pile)).empiler(t[i]); }

	return r;
}
