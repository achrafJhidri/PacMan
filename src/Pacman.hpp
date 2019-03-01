#include "DynamicGameElement.hpp"

class Pacman : public DynamicGameElement
{
private:
    
public:
    Pacman(const Sommet<VSommet> &, const sf::Texture &, double ,int largeur,int hauteur,int nbTextures);
    virtual ~Pacman();
};
