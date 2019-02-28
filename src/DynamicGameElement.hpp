#include "GameElement.hpp"
using namespace sf ;
class DynamicGameElement : public GameElement
{
private:
    double speed;
public:
    DynamicGameElement(const Sommet<VSommet> &, const sf::Texture &, double);
    virtual ~DynamicGameElement();

    double getSpeed() const;
    void setSpeed(double);
    void move(const  sf::Vector2f  & );
};
