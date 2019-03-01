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
		redFantome.loadFromFile("src/redfantome.jpg");
		yellowFantome.loadFromFile("src/yellowfantome.jpg");
		blueFantome.loadFromFile("src/bluefantome.jpg");
		//piece.loadFromFile("piece.jpg");
	}
public:

	//static TextureFactory * getInstance();
	Texture & getTexturePacman();
	Texture&  getTextureRedFantome();
	Texture &getTextureYellowFantome();
	Texture&  getTextureBlueFantome();
	Texture&  getTexturePomme();
	Texture& getTexturePiece();




};