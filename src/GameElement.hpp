#pragma once 
#include "Vecteur2D.h"
#include <SFML/graphics.hpp>


class GameElement {
    public :
     Vecteur2D position ;
    sf::Texture texture ;

    GameElement(const Vecteur2D  & position , const Texture  & texture){

    };
    ~GameElement();


    Vecteur2D getX()const {
        return position;
    }




    

}