#include "Ghost.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>   



Ghost::Ghost( Sommet<InfoSommet> * s, const sf::Texture & t ,double speed ,bool offensif,int largeur,int hauteur,int nbTextures )
:DynamicGameElement(s,t,speed,largeur,hauteur,nbTextures),offensif(offensif)
{

}
Ghost::~Ghost(){

}

bool  Ghost::estOffensif()const {
    return offensif;
}
void Ghost::aPeur(bool etat ){
    offensif=etat;
}


 void Ghost::moveRandom( ){
     
     
    PElement<Sommet<InfoSommet>> * copieListVoisin  = position->listVoisin;
    int taille =  PElement<Sommet<InfoSommet>>::taille(copieListVoisin);
    int i = rand() % taille ;

    while (copieListVoisin  ){
            if (i != 0){
                i--;
                copieListVoisin = copieListVoisin->s;
            }
            else {
                position=copieListVoisin->v;
                copieListVoisin=NULL;
            }
    }

 }

  void Ghost::moveNiveau2(Orientation orientation){
      

      if (orientation == Orientation::EAST){
           DynamicGameElement::move(Orientation::EAST);
            return ;
       }
        if (orientation == Orientation::WEST){
           DynamicGameElement::move(Orientation::WEST);
            return ;
       }
        if (orientation == Orientation::NORTH){
           DynamicGameElement::move(Orientation::NORTH);
            return ;
       }
        if (orientation == Orientation::SOUTH){
           DynamicGameElement::move(Orientation::SOUTH);
            return ;
       }
      if(orientation == Orientation::NORTH_EAST || orientation == Orientation::NORTH_WEST)
       {
            DynamicGameElement::move(orientation);
    
              return ;
       }
       if(orientation == Orientation::SOUTH_EAST || orientation == Orientation::SOUTH_WEST){
              DynamicGameElement::move(orientation);
              
              return ;
       }

  }
