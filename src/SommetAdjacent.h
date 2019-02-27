#pragma once
#include "Sommet.h"
#include "Arete.h"
template <class S, class T>
class SommetAdjacent
{
    Sommet<T> * original;
public:
    SommetAdjacent(const Sommet<T> * o) :original(const_cast<Sommet <T> *> (o)) {};

    bool operator()(const Arete<S, T> * arrete)const {
        if ((arrete->getDebut() == original))
            return arrete->getFin();
        else if (arrete->getFin() == original)
            return arrete->getDebut();

        return false;
    }
};

