#pragma once 
#include "DynamicGameElement.hpp"


 
class Ghost : public DynamicGameElement {

    private : 
    bool offensif  ;
    Ghost(const Sommet<VSommet> & s, const sf::Texture & t ,double speed ,bool offensif,int largeur,int hauteur,int nbTextures);

    ~Ghost();

    bool estOffensif() const ;
    void aPeur(bool etat = false  );


    




};