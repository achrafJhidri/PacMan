#include"TextureFactory.h"




//TextureFactory * TextureFactory::getInstance()
//{
//	if (textureFactory == NULL)
//		textureFactory =new TextureFactory();
//	
//		return textureFactory;
//}



Texture & TextureFactory::getTexturePacman() 
{
	
		return pacman;

}
Texture & TextureFactory::getTextureRedFantome()
{

	return redFantome;

}


Texture & TextureFactory::getTextureYellowFantome() 
{
	return yellowFantome;

}
Texture & TextureFactory::getTextureBlueFantome()
{
	return blueFantome;

}

Texture & TextureFactory::getTexturePomme() 
{
	return pomme;
}
Texture & TextureFactory::getTextureCoin()
{
	return piece;
}