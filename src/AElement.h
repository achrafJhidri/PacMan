#pragma once
#include <string>
#include <sstream>
using namespace std;
class AElement
{
	unsigned int clef;
public:
	AElement(const unsigned int a)  {
		setClef(a);
	}



	void setClef(const unsigned int a) {
		
		clef = a;
	}

	unsigned int getClef()const {
		return clef;
	}
	operator string()const {
		ostringstream os;
		os <<  "numero# " <<  clef;
		return os.str();

	}
	friend ostream & operator << (ostream & f, const AElement & element);
};

