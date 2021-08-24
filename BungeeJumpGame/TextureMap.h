#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Collision.h"

using namespace std;
using namespace sf;

/// <summary>
/// singleton class for managing all textures for the game as a map.
/// </summary>
class TextureMap
{
	static TextureMap* instance;
	map<string, Texture*> tMap;
		
	void initTextures();

public:
	// get the instance for this class as singleton
	static TextureMap& getInstance() {
		static TextureMap instance;
		return instance;
	}

	// constructors, destructors and singleton protection against copy.
	TextureMap();
	TextureMap(TextureMap const&) = delete;
	void operator=(TextureMap const&) = delete;
	virtual ~TextureMap();

	// get the texture using string key
	Texture& getTexture(string key);

	// load textures when created
	void loadTexture(string key, string path);

	void loadTextureBitmask(string key, string path);
};

