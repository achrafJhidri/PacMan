#pragma once

#include <SFML/Graphics.hpp>
#include <list>
using namespace std ;


class AnimatedSprite : public sf::Sprite {
    sf::Clock clock;
    list<sf::IntRect> cadres;
    list<sf::IntRect>::iterator it;
public:
    AnimatedSprite(const sf::Texture & textureSheet,int largeur,int hauteur,int nbTextures);
    ~AnimatedSprite();

    void update();
};
