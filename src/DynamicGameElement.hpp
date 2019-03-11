#pragma once
#include "GameElement.hpp"
#include "PElement.h"

#include <functional>

using namespace sf ;
class DynamicGameElement : public GameElement
{
private:
    double speed;
public:

    DynamicGameElement( Sommet<InfoSommet> *, const sf::Texture &, double speed,int largeur,int hauteur,int nbTextures);
    virtual ~DynamicGameElement();

    double getSpeed() const;
    void setSpeed(double);

    virtual bool move( Orientation orientation );

    static bool estAuNord(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);
    static bool estAuSud(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);
    static bool estAuEst(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);
    static bool estAuOuest(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);
    static bool memeX(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);
    static bool memeY(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);
    static bool estAuNordEst(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);
    static bool estAuNordOuest(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);

    static bool estAuSudEst(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);
    static bool estAuSudOuest(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);


    static Orientation vaVersOrientation(const Sommet<InfoSommet> & voisin,const Sommet<InfoSommet> & a);
};
