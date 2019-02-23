#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
class InfoArete
{
public:
	unsigned int couleur; // forma RGBA 
	double cout1; 

	InfoArete( const double & cout, const unsigned int & couleur= 0x0000FFFF): couleur(couleur),cout1(cout){
	};

	operator string() const;
	friend ostream & operator << (ostream & os, const InfoArete & infoArete) { return os << (string)infoArete; }
	
};

inline InfoArete::operator string() const
{
	ostringstream oss;

	oss << "coût = " << cout1 << ", " << couleur;

	return oss.str();
}
