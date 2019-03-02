#include "DynamicGameElement.hpp"

DynamicGameElement::DynamicGameElement(const Sommet<VSommet> &sommet, const sf::Texture &texture, double speed,int largeur,int hauteur,int nbTextures)
    : GameElement(sommet, texture,largeur,hauteur,nbTextures), speed(speed)
{}

DynamicGameElement::~DynamicGameElement() {}

double DynamicGameElement::getSpeed() const {
    return speed;
}

void DynamicGameElement::setSpeed(double s) {
    speed = s;
}


void DynamicGameElement::move( Orientation orientation ){
        if ( orientation == Orientation::SOUTH){
               positionRelative(*this,90,estAuSud);
            }
        if ( orientation == Orientation::NORTH){
               positionRelative(*this,-90,estAuNord);
            }
        if ( orientation == Orientation::EAST){
            positionRelative(*this,0,estAuEst);
            }
        if ( orientation == Orientation::WEST){
             positionRelative(*this,180,estAuOuest);
            }
        if ( orientation == Orientation::NORTH_EAST){
             positionRelative(*this,-45,estAuNordEst);
          }
        if ( orientation == Orientation::NORTH_WEST){
            positionRelative(*this,-135,estAuNordOuest);}
        if ( orientation == Orientation::SOUTH_EAST){
             positionRelative(*this,45,estAuSudEst);}
        if ( orientation == Orientation::SOUTH_WEST){
             positionRelative(*this,135,estAuSudOuest);}
}



void DynamicGameElement::positionRelative( DynamicGameElement & element,const double deg,bool (*checkOrientationFunction)(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a)){
    PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
            while(copieListVoisin ){    
                if ( checkOrientationFunction(*(copieListVoisin->v),position) ){
                    position=*(copieListVoisin->v);
                    sprite.setRotation(deg);
                    copieListVoisin = NULL;
                }else 
                    copieListVoisin=copieListVoisin->s;
            }
         PElement<Sommet<VSommet>>::efface1(copieListVoisin);
}

/*static*/ bool DynamicGameElement::estAuNord(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si le voisin est au nord de a cad  y du voisin < au y de a 
{    return ( voisin.v.p.y  < a.v.p.y ) &&  memeX(voisin,a) ;}

/*static*/ bool DynamicGameElement::memeX(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si ils ont le meme x
{    return ( voisin.v.p.x == a.v.p.x ) ;}
/*static*/ bool DynamicGameElement::memeY(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si ils ont le meme x
{    return ( voisin.v.p.y == a.v.p.y ) ;}

/*static*/ bool DynamicGameElement::estAuSud(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si le voisin est au sud de a cad  y du voisin au > y de a 
{   return ( voisin.v.p.y  > a.v.p.y ) &&  memeX(voisin,a) ;}

/*static*/ bool DynamicGameElement::estAuEst(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si le voisin est au nord de a cad  x du voisin > au x de a 
{   return ( voisin.v.p.x  > a.v.p.x ) &&  memeY(voisin,a) ;}

/*static*/ bool DynamicGameElement::estAuOuest(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si le voisin est au nord de a cad  x du voisin < au x de a 
{    return ( voisin.v.p.x  < a.v.p.x ) &&  memeY(voisin,a) ;}


/*static*/ bool DynamicGameElement::estAuNordEst(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si le voisin est au nord est
{    return ( voisin.v.p.y  < a.v.p.y ) &&  ( voisin.v.p.x  > a.v.p.x) ;}

/*static*/ bool DynamicGameElement::estAuNordOuest(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si le voisin est au nord ouest
{    return ( voisin.v.p.y  < a.v.p.y ) &&  ( voisin.v.p.x  < a.v.p.x) ;}

/*static*/ bool DynamicGameElement::estAuSudEst(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si le voisin est au sud Est
{    return ( voisin.v.p.y  > a.v.p.y ) &&  ( voisin.v.p.x  > a.v.p.x) ;}
/*static*/ bool DynamicGameElement::estAuSudOuest(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a) // renvoi true si le voisin est au sud Ouest
{    return ( voisin.v.p.y  > a.v.p.y ) &&  ( voisin.v.p.x  < a.v.p.x) ;}
