#include"TextureFactory.h"

TextureFactory::TextureFactory() {
    pacman.loadFromFile("assets/pacman.png");
    pomme.loadFromFile("assets/pomme.png");
    redFantome.loadFromFile("assets/redfantome.png");
    yellowFantome.loadFromFile("assets/yellowfantome.png");
    blueFantome.loadFromFile("assets/bluefantome.png");
    piece.loadFromFile("assets/coin.png");
}

TextureFactory const& TextureFactory::getInstance() {
    return *instance;
}

sf::Texture const& TextureFactory::getTexturePacman() const {
    return pacman;
}

sf::Texture const& TextureFactory::getTextureRedFantome() const {
    return redFantome;
}

sf::Texture const& TextureFactory::getTextureYellowFantome() const {
    return yellowFantome;
}

sf::Texture const& TextureFactory::getTextureBlueFantome() const {
    return blueFantome;
}

sf::Texture const& TextureFactory::getTexturePomme() const {
    return pomme;
}

sf::Texture const& TextureFactory::getTextureCoin() const {
    return piece;
}
