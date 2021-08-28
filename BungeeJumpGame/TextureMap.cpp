#include "TextureMap.h"
#include <iostream>
#include <string>
#include "Collision.h"

TextureMap* TextureMap::instance = nullptr;

void TextureMap::initTextures()
{

    // player
    loadTextureBitmask("Player", "Player.png");

    // background
    loadTexture("Sky_Background", "Sky_Background.png");
    for (int i = 1; i <= 20; i++) {
        loadTexture("Cloud_"+std::to_string(i), "Cloud_"+ std::to_string(i)+".png");
    }

    // ui
    loadTexture("Heart", "Heart.png");

    // traps
    loadTextureBitmask("Base_trap", "Base_trap.png");
    loadTextureBitmask("Saw_trap", "Saw_trap.png");
    loadTextureBitmask("Axe_trap", "Axe_trap.png");
}

TextureMap& TextureMap::getInstance()
{
    if (instance == nullptr) {
        instance = new TextureMap();
    }
    return *instance;
}

TextureMap::TextureMap()
{
    initTextures();
}

TextureMap::~TextureMap()
{
    for (auto t : tMap) {
        delete t.second;
    }
}

sf::Texture& TextureMap::getTexture(std::string key)
{
    return *tMap[key];
}

//add texture to map from Textures folder
void TextureMap::loadTexture(std::string key, std::string path)
{
    tMap[key] = new sf::Texture();
    if (!tMap[key]->loadFromFile("Resources/Textures/" + path)) {
        std::cout << "ERROR::TEXTUREMAP::LOADTEXTURE::failed to load '" + key + "' texture\n";
    }
}

void TextureMap::loadTextureBitmask(std::string key, std::string path)
{
    tMap[key] = new sf::Texture();
    
    if (!Collision::CreateTextureAndBitmask(*tMap[key], "Resources/Textures/" + path)) {
        std::cout << "ERROR::TEXTUREMAP::LOADTEXTUREWITHBITMASK::failed to load '" + key + "' texture\n";
    }

}



