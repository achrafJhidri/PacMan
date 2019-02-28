#pragma once 
#include "DynamicGameElement.hpp"


 
class Ghost : public DynamicGameElement {

    private : 
    bool estOffensif  ;
    Ghost(const Sommet<VSommet> & s, const sf::Texture & t ,double speed = 3,bool offensif=true );

    ~Ghost();

    bool estOffensif() const ;
    void offensif(bool etat = true );

    
    




}