#include "TextureMap.h"
#include <iostream>

void TextureMap::initTextures()
{

    // player
    loadTextureBitmask("Player", "Player.png");

    // background
    loadTexture("Sky_Background", "Sky_Background.png");
    for (int i = 1; i <= 20; i++) {
        loadTexture("Cloud_"+to_string(i), "Cloud_"+to_string(i)+".png");
    }

    // ui
    loadTexture("Heart", "Heart.png");

    // traps
    loadTextureBitmask("Base_trap", "Base_trap.png");
    loadTextureBitmask("Saw_trap", "Saw_trap.png");
    loadTextureBitmask("Axe_trap", "Axe_trap.png");
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

Texture& TextureMap::getTexture(string key)
{
    return *tMap[key];
}

//add texture to map from Textures folder
void TextureMap::loadTexture(string key, string path)
{
    tMap[key] = new Texture();
    if (!tMap[key]->loadFromFile("Resourses/Textures/" + path)) {
        std::cout << "ERROR::TEXTUREMAP::LOADTEXTURE::failed to load '" + key + "' texture\n";
    }
}

void TextureMap::loadTextureBitmask(string key, string path)
{
    tMap[key] = new Texture();
    
    if (!Collision::CreateTextureAndBitmask(*tMap[key], "Resourses/Textures/" + path)) {
        std::cout << "ERROR::TEXTUREMAP::LOADTEXTUREWITHBITMASK::failed to load '" + key + "' texture\n";
    }

}



