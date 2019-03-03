#include "Pacman.hpp"




Pacman::Pacman(const Sommet<VSommet> &s, const sf::Texture &t, double speed,int largeur,int hauteur,int nbTextures)
    : DynamicGameElement(s, t, speed,largeur,hauteur,nbTextures)
{}

Pacman::~Pacman() {}
