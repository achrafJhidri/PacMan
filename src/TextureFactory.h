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
		if (!pacman.loadFromFile("pacman.jpg"))
			cout << "pas reussi a charger correcteoemnt" << endl;
		pomme.loadFromFile("pomme.png");
		redFantome.loadFromFile("redfantome.jpg");
		yellowFantome.loadFromFile("yellowfantome.jpg");
		blueFantome.loadFromFile("bluefantome.jpg");
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