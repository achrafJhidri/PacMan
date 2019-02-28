#pragma once 
#include "DynamicGameElement.hpp"


 
class Ghost : public DynamicGameElement {

    private : 
    bool offensif  ;
    Ghost(const Sommet<VSommet> & s, const sf::Texture & t ,double speed = 3,bool offensif=true );

    ~Ghost();

    bool estOffensif() const ;
    void aPeur(bool etat = false  );


    




};