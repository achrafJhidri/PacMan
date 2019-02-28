#include "DynamicGameElement.hpp"

class Pacman : public DynamicGameElement
{
private:
    
public:
    Pacman(const Sommet<VSommet> &, const sf::Texture &, double = 4);
    virtual ~Pacman();
};
