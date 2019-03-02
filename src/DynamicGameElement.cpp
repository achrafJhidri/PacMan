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

    PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
    bool trouve = false ;
     while(copieListVoisin && !trouve){
            
           if (( copieListVoisin->v->v.p.y +248 > position.v.p.y +248 ) && (copieListVoisin->v->v.p.x == position.v.p.x) ){
                 sprite.move(0,60);
                 position=*(copieListVoisin->v);
                sprite.setRotation(90);
                trouve = true ;
           }else 
            copieListVoisin=copieListVoisin->s;
        }
        
    }
      if ( orientation == Orientation::NORTH){
             PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
    bool trouve = false ;
     while(copieListVoisin && !trouve){
            
           if ( (copieListVoisin->v->v.p.y +248 < position.v.p.y +248)  && (copieListVoisin->v->v.p.x == position.v.p.x) ){
                 sprite.move(0,-60);
                 position=*(copieListVoisin->v);
                sprite.setRotation(-90);
                trouve = true ;
           }else 
            copieListVoisin=copieListVoisin->s;
        }
       
    }
      if ( orientation == Orientation::EAST){
            PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
            bool trouve = false ;
            while(copieListVoisin && !trouve){
            
                    if ( (copieListVoisin->v->v.p.x +10 > position.v.p.x+10 ) && (copieListVoisin->v->v.p.y == position.v.p.y) ){
                        sprite.move(60,0);
                        position=*(copieListVoisin->v);
                        sprite.setRotation(0);
                        trouve = true ;
                    }else 
                        copieListVoisin=copieListVoisin->s;
            }
        }
      if ( orientation == Orientation::WEST){
            PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
            bool trouve = false ;
            while(copieListVoisin && !trouve){
                if ( (copieListVoisin->v->v.p.x+10 < position.v.p.x+10) &&  (copieListVoisin->v->v.p.y == position.v.p.y) ){
                    sprite.move(-60,0);
                    position=*(copieListVoisin->v);
                    sprite.setRotation(-180);
                    trouve = true ;
                }else 
                    copieListVoisin=copieListVoisin->s;
            }
        }
    if ( orientation == Orientation::NORTH_EAST){
        sprite.move(62,-62);
        sprite.setRotation(-180);
    }
}
