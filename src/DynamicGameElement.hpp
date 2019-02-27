#include "GameElement.hpp"

class DynamicGameElement : public GameElement
{
private:
    double speed;
public:
    DynamicGameElement(const Sommet<VSommet> &, const sf::Texture &);
    virtual ~DynamicGameElement();

    double getSpeed() const;
    void setSpeed(double);
};
