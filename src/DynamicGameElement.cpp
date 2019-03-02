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
            while(copieListVoisin ){    
                if (( copieListVoisin->v->v.p.y > position.v.p.y  ) && (copieListVoisin->v->v.p.x == position.v.p.x) ){
                    position=*(copieListVoisin->v);
                    sprite.setRotation(90);
                    copieListVoisin = NULL;
                }else 
                    copieListVoisin=copieListVoisin->s;
            }}
        if ( orientation == Orientation::NORTH){
            PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
   
            while(copieListVoisin  ){
            
                if ( (copieListVoisin->v->v.p.y  < position.v.p.y )  && (copieListVoisin->v->v.p.x == position.v.p.x) ){
                        
                    position=*(copieListVoisin->v);
                    sprite.setRotation(-90);
                    copieListVoisin = NULL;
                }else 
                    copieListVoisin=copieListVoisin->s;
            }}
        if ( orientation == Orientation::EAST){
            PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
            
            while(copieListVoisin ){
            
                    if ( (copieListVoisin->v->v.p.x  > position.v.p.x ) && (copieListVoisin->v->v.p.y == position.v.p.y) ){
                       
                        position=*(copieListVoisin->v);
                        sprite.setRotation(0);
                        copieListVoisin = NULL;
                    }else 
                        copieListVoisin=copieListVoisin->s;
            }}
        if ( orientation == Orientation::WEST){
            PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
           
            while(copieListVoisin ){
                if ( (copieListVoisin->v->v.p.x < position.v.p.x) &&  (copieListVoisin->v->v.p.y == position.v.p.y) ){
                    
                    position=*(copieListVoisin->v);
                    sprite.setRotation(-180);
                     copieListVoisin = NULL;
                }else 
                    copieListVoisin=copieListVoisin->s;
            }}
        if ( orientation == Orientation::NORTH_EAST){
            PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
           
            while(copieListVoisin ){
                if ( (copieListVoisin->v->v.p.x > position.v.p.x) &&  (copieListVoisin->v->v.p.y < position.v.p.y) ){
                    
                    position=*(copieListVoisin->v);
                    sprite.setRotation(-45);
                     copieListVoisin = NULL;
                }else 
                    copieListVoisin=copieListVoisin->s;
            }}
        if ( orientation == Orientation::NORTH_WEST){
            PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
           
            while(copieListVoisin ){
                if ( (copieListVoisin->v->v.p.x < position.v.p.x) &&  (copieListVoisin->v->v.p.y < position.v.p.y) ){
                    
                    position=*(copieListVoisin->v);
                    sprite.setRotation(-135);
                     copieListVoisin = NULL;
                }else 
                    copieListVoisin=copieListVoisin->s;
            }}
        if ( orientation == Orientation::SOUTH_EAST){
            PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
           
            while(copieListVoisin ){
                if ( (copieListVoisin->v->v.p.x > position.v.p.x) &&  (copieListVoisin->v->v.p.y > position.v.p.y) ){
                    
                    position=*(copieListVoisin->v);
                    sprite.setRotation(45);
                     copieListVoisin = NULL;
                }else 
                    copieListVoisin=copieListVoisin->s;
            }}
        if ( orientation == Orientation::SOUTH_WEST){
            PElement<Sommet<VSommet>> * copieListVoisin =  PElement<Sommet<VSommet>>::copie1(position.listVoisin);
           
            while(copieListVoisin ){
                if ( (copieListVoisin->v->v.p.x < position.v.p.x) &&  (copieListVoisin->v->v.p.y > position.v.p.y) ){
                    
                    position=*(copieListVoisin->v);
                    sprite.setRotation(135);
                     copieListVoisin = NULL;
                }else 
                    copieListVoisin=copieListVoisin->s;
            }}
}

