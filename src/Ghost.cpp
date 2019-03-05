#include "Ghost.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>   



Ghost::Ghost( Sommet<VSommet> * s, const sf::Texture & t ,double speed ,bool offensif,int largeur,int hauteur,int nbTextures )
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


 void Ghost::move( Orientation orientation  ){
     
     
    PElement<Sommet<VSommet>> * copieListVoisin  = position->listVoisin;


    int taille =  PElement<Sommet<VSommet>>::taille(copieListVoisin);
    int i = rand() % taille ;
        //  i = 4 
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