#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

class TextureFactory 
{
private:
    static TextureFactory const* instance;
    TextureFactory();

    sf::Texture pacman;
    sf::Texture redFantome;
    sf::Texture yellowFantome;
    sf::Texture blueFantome;
    sf::Texture pomme;
    sf::Texture piece;
public:
    static TextureFactory const& getInstance();
    sf::Texture const& getTexturePacman() const;
    sf::Texture const& getTextureRedFantome() const;
    sf::Texture const& getTextureYellowFantome() const;
    sf::Texture const& getTextureBlueFantome() const;
    sf::Texture const& getTexturePomme() const;
    sf::Texture const& getTextureCoin() const;
};
