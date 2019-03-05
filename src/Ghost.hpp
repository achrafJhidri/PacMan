#pragma once 
#include "DynamicGameElement.hpp"


 
class Ghost : public DynamicGameElement {

    private: 
    bool offensif  ;
    public:
    Ghost( Sommet<VSommet> * s, const sf::Texture & t ,double speed ,bool offensif,int largeur,int hauteur,int nbTextures);

    virtual ~Ghost();

    bool estOffensif() const ;
    void aPeur(bool etat = false  );


     void move( Orientation orientation = Orientation::NORTH );


    




};