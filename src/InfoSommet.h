#pragma once
#include "VSommet.h"
#include "InfoAStar.h"

class InfoSommet
{
public:

	VSommet vSommet;
	InfoAStar infoAStar; 

	InfoSommet(const VSommet & v, const InfoAStar & i):vSommet(v),infoAStar(i) {
		
	};

	operator string() const {
		ostringstream oss;
		oss << vSommet << endl;
		oss << infoAStar; 
		return oss.str();
	}
};

