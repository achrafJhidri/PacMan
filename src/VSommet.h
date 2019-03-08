#pragma once
#include <string>
#include "Vecteur2D.h"
#include <sstream>
#include <SFML/Graphics.hpp>


/**

Classes VSommet et Peinture : elles sont utilisées dans TestDessinGraphe pour dessiner un graphe.


informations associée à un sommet : nom, position, couleur
sert à tester l'opération "dessiner un graphe"

VSommet comme "valeur associée à un sommet"

*/
class VSommet
{
public:
    constexpr static int rayonDisquePixels = 30;
    constexpr static unsigned int couleurBord = 0xA10684FF; // couleur violine opaque
    std::string nom;
    sf::Vector2f p; // position
    unsigned int couleur; // couleur au format rgba
	
    /**
    par défaut, la couleur d'un sommet est rouge opaque
    */
    VSommet(const std::string & nom, const sf::Vector2f & p, const unsigned int couleur = 0xFF0000FF) : nom(nom), p(p), couleur(couleur) {}
};
