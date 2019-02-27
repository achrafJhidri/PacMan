#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class TextureFactory 
{
private:
	Texture pacman;
	Texture fantome;
	Texture pomme;
	Texture piece;
	//static TextureFactory * textureFactory;
public:
	TextureFactory()
	{
		if (!pacman.loadFromFile("src/pacman.jpg"))
			cout << "pas reussi a charger pacman" << endl;
		if (!pomme.loadFromFile("src/pacman.jpg"))
			cout << "pas reussi a charger la pomme" << endl;
		if (!fantome.loadFromFile("src/pacman.jpg"))
			cout << "pas reussi a charger le fantome" << endl;
		if (!piece.loadFromFile("src/pacman.jpg"))
			cout << "pas reussi a charger la piece" << endl;
	}
public:

	//static TextureFactory * getInstance();
	
	Texture & getTexturePacman(){return pacman;};
	Texture&  getTextureFantome(){return fantome;};
	Texture&  getTexturePomme(){return pomme;};
	Texture& getTexturePiece(){return piece;};




};