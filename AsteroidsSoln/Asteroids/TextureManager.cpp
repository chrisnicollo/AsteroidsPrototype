#include "TextureManager.h"

// "redeclare" variable so this file knows abt it & can use it
unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string fileName) {
	string path = "images/";
	path += fileName + ".png";

	textures[fileName].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName) {
	// if texture doesn't exist, load it first & then return it
	if (textures.find(textureName) == textures.end()) {
		LoadTexture(textureName);
	}

	return textures[textureName];
}

void TextureManager::Clear() {
	textures.clear();
}