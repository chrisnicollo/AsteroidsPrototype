#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>
using std::string;
using std::unordered_map;

class SoundManager
{
	static unordered_map<string, sf::SoundBuffer> buffers;
	static void LoadSoundBuffer(string fileName);
public:
	static sf::SoundBuffer& GetSoundBuffer(string bufferName);
	static void Clear();
};
