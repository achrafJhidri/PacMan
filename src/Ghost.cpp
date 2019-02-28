#include "Ghost.hpp"




Ghost::Ghost(const Sommet<VSommet> & s, const sf::Texture & t ,double speed ,bool offensif  )
:DynamicGameElement(s,t,speed),offensif(offensif)
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
