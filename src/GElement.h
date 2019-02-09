#pragma once
#include "AElement.h"

template <class T>
class GElement :
	public AElement
{
	T  v;
public:
	GElement(const unsigned int c, const T & o) :AElement(c) {
		setV(o);
	};



	const T & getV()const {
		return v;
	}

	void setV(const T & t) {
		v = t;
	}

	operator string()const {
		ostringstream os;
		os << AElement::operator string () << " T[ " << v<< "]";
		return os.str();
	}

	friend ostream & operator << (ostream & f, const GElement<T> & element)
	{
		return f << string(element);
	}


	
	
};
