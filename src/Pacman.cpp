#include "Pacman.hpp"

Pacman::Pacman(const Sommet<VSommet> &s, const sf::Texture &t, double speed)
    : DynamicGameElement(s, t, speed)
{}

Pacman::~Pacman() {}
