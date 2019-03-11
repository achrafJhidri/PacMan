#include "DynamicGameElement.hpp"
#include "Pacman.hpp"

DynamicGameElement::DynamicGameElement( Sommet<InfoSommet> *sommet, const sf::Texture &texture, double speed,int largeur,int hauteur,int nbTextures)
    : GameElement(sommet, texture,largeur,hauteur,nbTextures), speed(speed)
{}

DynamicGameElement::~DynamicGameElement() {}

double DynamicGameElement::getSpeed() const {
    return speed;
}

void DynamicGameElement::setSpeed(double s) {
    speed = s;
}

bool DynamicGameElement::move(Orientation orientation) {
    // Determine how to rotate the sprite
    int angle;
#define CASE(o, a) case Orientation::o: angle = a; break;
    switch (orientation) {
	CASE(SOUTH,        90);
	CASE(NORTH,       -90);
	CASE(EAST,          0);
	CASE(WEST,        180);
	CASE(NORTH_EAST,  -45);
	CASE(NORTH_WEST, -135);
	CASE(SOUTH_EAST,   45);
	CASE(SOUTH_WEST,  135);
    }
#undef CASE
    this->sprite.setRotation(angle);

    // Iterate through neighbours
    PElement<Sommet<InfoSommet> > *ns;
    Sommet<InfoSommet> *neighbour;
    for (ns = this->position->listVoisin; ns != nullptr; ns = ns->s) {
	neighbour = ns->v;
	// Move if neighbour is in the right orientation
        if (checkAlignement(orientation, *neighbour)) {
	        position = neighbour;
            return true ;
        }
    }
    return false ;
}

/*static*/ bool DynamicGameElement::estAuNord(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si le voisin est au nord de a cad  y du voisin < au y de a 
{    return ( voisin.v.vSommet.p.y  < a.v.vSommet.p.y ) &&  memeX(voisin,a) ;}

/*static*/ bool DynamicGameElement::memeX(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si ils ont le meme x
{    return ( voisin.v.vSommet.p.x == a.v.vSommet.p.x ) ;}
/*static*/ bool DynamicGameElement::memeY(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si ils ont le meme x
{    return ( voisin.v.vSommet.p.y == a.v.vSommet.p.y ) ;}

/*static*/ bool DynamicGameElement::estAuSud(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si le voisin est au sud de a cad  y du voisin au > y de a 
{   return ( voisin.v.vSommet.p.y  > a.v.vSommet.p.y ) &&  memeX(voisin,a) ;}

/*static*/ bool DynamicGameElement::estAuEst(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si le voisin est au nord de a cad  x du voisin > au x de a 
{   return ( voisin.v.vSommet.p.x  > a.v.vSommet.p.x ) &&  memeY(voisin,a) ;}

/*static*/ bool DynamicGameElement::estAuOuest(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si le voisin est au nord de a cad  x du voisin < au x de a 
{    return ( voisin.v.vSommet.p.x  < a.v.vSommet.p.x ) &&  memeY(voisin,a) ;}


/*static*/ bool DynamicGameElement::estAuNordEst(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si le voisin est au nord est
{    return ( voisin.v.vSommet.p.y  < a.v.vSommet.p.y ) &&  ( voisin.v.vSommet.p.x  > a.v.vSommet.p.x) ;}

/*static*/ bool DynamicGameElement::estAuNordOuest(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si le voisin est au nord ouest
{    return ( voisin.v.vSommet.p.y  < a.v.vSommet.p.y ) &&  ( voisin.v.vSommet.p.x  < a.v.vSommet.p.x) ;}

/*static*/ bool DynamicGameElement::estAuSudEst(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si le voisin est au sud Est
{    return ( voisin.v.vSommet.p.y  > a.v.vSommet.p.y ) &&  ( voisin.v.vSommet.p.x  > a.v.vSommet.p.x) ;}
/*static*/ bool DynamicGameElement::estAuSudOuest(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a) // renvoi true si le voisin est au sud Ouest
{    return ( voisin.v.vSommet.p.y  > a.v.vSommet.p.y ) &&  ( voisin.v.vSommet.p.x  < a.v.vSommet.p.x) ;}


/*static */   Orientation  DynamicGameElement::vaVersOrientation(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a){
    
    if (estAuNordEst(voisin,a))
            return Orientation::NORTH_EAST;

    if (estAuNordOuest(voisin,a))
            return Orientation::NORTH_WEST;

    if(estAuSudEst(voisin,a))
            return Orientation::SOUTH_EAST;
    if(estAuSudOuest(voisin,a))
            return Orientation::SOUTH_WEST;
    
    if(estAuNord(voisin,a))
            return Orientation::NORTH;
    
    if(estAuEst(voisin,a))
            return Orientation::EAST;
    if(estAuOuest(voisin,a))
            return Orientation::WEST;
    
    if (estAuSud(voisin,a))
            return Orientation::SOUTH;
    
   

}