#include "Vecteur2D.h"




Vecteur2D::~Vecteur2D()
{
}
Vecteur2D::Vecteur2D(const Vecteur2D & v)
	:x(v.x),y(v.y)
{
}
Vecteur2D::Vecteur2D(const char * s)
{
}
 Vecteur2D::Vecteur2D(const double &_x, const double & _y)
	: x(_x), y(_y)
{
}



 const Vecteur2D Vecteur2D::operator-()const {
	return Vecteur2D(-x, -y);
}

 bool Vecteur2D::operator==(const Vecteur2D & v) const
 {
	 return (x == v.x && y == v.y);
 }
Vecteur2D::operator string() const
{
	ostringstream os;
	os << "(" << x << "," << y << ")";
	return os.str();

}

double Vecteur2D::det(const Vecteur2D & a, const Vecteur2D & b, const Vecteur2D & c)
{
	double xab = b.x - a.x;
	double yab = b.y - a.y;


	double xac = c.x - a.x;
	double yac = c.y - a.y;

	double det = xab * yac - xac * yab;


	return det;
}

ostream & operator<<(ostream & os, const Vecteur2D & u)
{
	return os << string(u);
}
