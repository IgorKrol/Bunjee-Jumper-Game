#pragma once
#include <string>
#include <SFML/Graphics.hpp>

/// <summary>
/// singleton class for managing all textures for the game as a map.
/// </summary>
class TextureMap
{
	static TextureMap* instance;
	std::map<std::string, sf::Texture*> tMap;
		
	void initTextures();

public:
	// get the instance for this class as singleton
	static TextureMap& getInstance();

	// constructor, destructor and singleton protection against copy.
	TextureMap();
	TextureMap(TextureMap const&) = delete;
	void operator=(TextureMap const&) = delete;
	virtual ~TextureMap();

	// get the texture using string key
	sf::Texture& getTexture(std::string key);

	// load textures when created
	void loadTexture(std::string key, std::string path);

	void loadTextureBitmask(std::string key, std::string path);
};

