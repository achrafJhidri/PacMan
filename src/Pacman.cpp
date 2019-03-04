#include "Pacman.hpp"




Pacman::Pacman(const Sommet<VSommet> &s, const sf::Texture &t, double speed,int largeur,int hauteur,int nbTextures)
    : DynamicGameElement(s, t, speed,largeur,hauteur,nbTextures),nbPieceGagnee(0)
{}

Pacman::~Pacman() {}


void Pacman::move(Orientation orientation){
    DynamicGameElement::move(orientation);
    if( position.pacGomme != 0 ){
        nbPieceGagnee++;
        cout << nbPieceGagnee << endl ;
        position.pacGomme=false ;
    }
}