#pragma once

#include <SFML/Graphics.hpp>
#include <list>
using namespace std ;

// a faire
class AnimatedSprite : public Sprite {

    list <sf::IntRect> cadres ;
    list <sf::IntRect>::iterator it ;
  
public:
  AnimatedSprite(const sf::Texture & textureSheet,int largeur,int hauteur,int nbTextures)
  :Sprite()
{
    cadres= list<sf::IntRect>();
    for (int i = 0 ; i < nbTextures;i++)
        cadres.push_back(sf::IntRect(i*largeur,0,largeur,hauteur));

   it =cadres.begin();
   setTexture(textureSheet);
   setTextureRect(*it);

};
  ~AnimatedSprite(){};

  void update (){
    sf::Clock clock;
    if ( clock.getElapsedTime().asSeconds() > 0.5f )
        {
            if (it == cadres.end() )
                it=cadres.begin();
            else 
                it++;

            setTextureRect(*it);
        }
};
 
};