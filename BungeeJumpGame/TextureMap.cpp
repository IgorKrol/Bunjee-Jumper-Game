#include "TextureMap.h"
#include <iostream>

void TextureMap::initTextures()
{
    loadTexture("Player", "Player.png");
    loadTexture("Sky_Background", "Sky_Background.png");
    loadTexture("Cloud_1", "Cloud_1.png");
    loadTexture("Cloud_2", "Cloud_2.png");
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
    if (!tMap[key]->loadFromFile("Textures/" + path)) {
        std::cout << "ERROR::TEXTUREMAP::LOADTEXTURE::failed to load '" + key + "' texture\n";
    }
}
