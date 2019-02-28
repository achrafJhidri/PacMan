#include "Ghost.hpp"




Ghost::Ghost(const Sommet<VSommet> & s, const sf::Texture & t ,double speed = 3,bool offensif=true )
:DynamicGameElement(s,t,speed),estOffensif(offensif)
{

}
Ghost::~Ghost(){

}

bool  Ghost::estOffensif()const {
    return estOffensif;
}
void offensif(bool etat ){
    estOffensif=etat;
}
