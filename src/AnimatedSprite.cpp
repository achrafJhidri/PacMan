#include "AnimatedSprite.hpp"


/*
AnimatedSprite::AnimatedSprite(const sf::Texture & textureSheet,int largeur,int hauteur,int nbTextures)
    :Sprite(),it(cadres.begin())
{
    for (int i = 0 ; i < nbTextures;i++)
        cadres.push_back(sf::IntRect(i*largeur,0,i*largeur+largeur,hauteur));
    setSprite(textureSheet,sf::IntRect(*it));

}*/

//AnimatedSprite::~AnimatedSprite(){};
// faut petre rajouter un parametre en entré Orientaion (l'enum LEFT.....)
// comme ça on sais si on doit faire une rotation de la texture
/*void AnimatedSprite::update(){
    sf::Clock clock;
    if ( clock.getElapsedTime().asSeconds() > 0.5f )
        {
            if (it == cadres.end() )
                it=cadres.begin();
            else 
                it++;

            setSprite.setTextureRect(*it);
        }
}*/
