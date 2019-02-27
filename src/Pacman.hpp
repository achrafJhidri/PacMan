#include "GameElement.hpp"

class Pacman  : public DynamicGameElement
{

public:
    Pacman(const Sommet<VSommet> & s, const sf::Texture & t ,double speed = 4)
    :DynamicGameElement(s,t,speed){

    };
    virtual ~Pacman();


};
