#include "AnimatedSprite.hpp"
#include "iostream"
using namespace std ;

AnimatedSprite::AnimatedSprite(const sf::Texture & textureSheet,int largeur,int hauteur,int nbTextures)
   :Sprite()
 {
    cadres= list<sf::IntRect>();
    for (int i = 0 ; i < nbTextures;i++)
      { 
           cadres.push_back(sf::IntRect(i*largeur,0,largeur,hauteur));
         
      }
    it =cadres.begin();
    setTexture(textureSheet);
    setTextureRect(*it);
 }
AnimatedSprite::~AnimatedSprite(){};
// faut petre rajouter un parametre en entré Orientaion (l'enum LEFT.....)
// comme ça on sais si on doit faire une rotation de la texture
void AnimatedSprite::update(){
    
    sf::Clock clock;
    if ( clock.getElapsedTime().asMilliseconds() < 0.05f )
        {
            if (it == cadres.end() )
                it=cadres.begin();
            else 
                it++;

           setTextureRect(*it);
        }
        
}