#pragma once

#include <SFML/Graphics.hpp>
#include <list>
using namespace std ;

// a faire
class AnimatedSprite : public sf::Sprite {

    list <sf::IntRect> cadres ;
    list <sf::IntRect>::iterator it ;
  
public:
  AnimatedSprite(const sf::Texture & textureSheet,int largeur,int hauteur,int nbTextures);

  ~AnimatedSprite();

   void update ();
 
};