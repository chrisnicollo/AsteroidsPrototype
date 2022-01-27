#include "SoundManager.h"

unordered_map<string, sf::SoundBuffer> SoundManager::buffers;

void SoundManager::LoadSoundBuffer(string fileName) {
	string path = "sounds/";
	path += fileName + ".wav";

	buffers[fileName].loadFromFile(path);
}

sf::SoundBuffer& SoundManager::GetSoundBuffer(string bufferName) {
	if (buffers.find(bufferName) == buffers.end()) {
		LoadSoundBuffer(bufferName);
	}

	return buffers[bufferName];
}

void SoundManager::Clear() {
	buffers.clear();
}