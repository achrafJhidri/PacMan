#pragma once
#include "AElement.h"
#include <iostream>

constexpr int LIBRE = 0;
constexpr int OUVERT = 1;
constexpr int FERME = 2;
class InfoAStar
{
public:
	const static char *ETATS[];
	AElement * pere;
	int etat;
	double c;
	double h;
	double g;


	InfoAStar(AElement * p = nullptr, int e = LIBRE, const double & c   = 0 ,const double & h = 0 ,const double &  g = 0) 
		: pere(p),etat(e),c(c),h(h),g(g)
	{
	};
	
    operator std::string()  const {
		 ostringstream oss;

		 oss << "clef pere = ";

		 if (pere)
			 oss << pere->clef;
		 else
			 oss << "non définie";

		 oss << ", état = " << ETATS[etat] << ", coût = " << c << ", h = " << h << ", g = " << g;

		 return oss.str();
			 
	}

	 friend ostream& operator <<(ostream & f, const InfoAStar & info) {
		 return f << string(info);
	 }


};

