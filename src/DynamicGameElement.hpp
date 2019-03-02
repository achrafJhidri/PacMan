#include "GameElement.hpp"
#include "PElement.h"

using namespace sf ;
class DynamicGameElement : public GameElement
{
private:
    double speed;
public:
    DynamicGameElement(const Sommet<VSommet> &, const sf::Texture &, double speed,int largeur,int hauteur,int nbTextures);
    virtual ~DynamicGameElement();

    double getSpeed() const;
    void setSpeed(double);

    void move( Orientation orientation );

    void positionRelative( DynamicGameElement & element,const double deg,bool (*checkOrientationFunction)(const Sommet<VSommet> & a,const Sommet<VSommet> & voisin));

    static bool estAuNord(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);
    static bool estAuSud(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);
    static bool estAuEst(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);
    static bool estAuOuest(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);
    static bool memeX(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);
    static bool memeY(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);
    static bool estAuNordEst(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);
    static bool estAuNordOuest(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);

    static bool estAuSudEst(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);
    static bool estAuSudOuest(const Sommet<VSommet> & voisin,const Sommet<VSommet> & a);

};
