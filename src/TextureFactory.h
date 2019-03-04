#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class TextureFactory 
{
private:
	Texture pacman;
	Texture redFantome;
	Texture yellowFantome;
	Texture blueFantome;
	Texture pomme;
	Texture piece;
	//static TextureFactory * textureFactory;
public:
	TextureFactory()
	{
		pacman.loadFromFile("src/pacman.png");
			
		pomme.loadFromFile("src/pomme.png");
		redFantome.loadFromFile("src/redfantome.png");
		yellowFantome.loadFromFile("src/yellowfantome.png");
		blueFantome.loadFromFile("src/bluefantome.png");
		piece.loadFromFile("src/coin.png");
	}
public:

	//static TextureFactory * getInstance();
	Texture & getTexturePacman();
	Texture & getTextureRedFantome();
	Texture & getTextureYellowFantome();
	Texture & getTextureBlueFantome();
	Texture & getTexturePomme();
	Texture & getTextureCoin();




};