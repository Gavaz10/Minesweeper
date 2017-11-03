#pragma once
#include "stdafx.h"

void print(const char*);//python lelellelelel
void println(const char*);
bool isNumber(std::string str);
int toInt(std::string str);
void loadTextureFromFile(sf::Texture& texture, const char* fileName);
void setSpriteScale(sf::Sprite& sprite, float newSizeX, float newSizeY);

class Tools {
public:
	static sf::Texture m_closedCeilTexture;
	static sf::Texture m_openCeilTexture;
	static sf::Texture m_mineCeilTexture;
	static sf::Texture m_flagCeilTexture;
	static sf::Texture m_pointedCeilTexture;
	Tools()
	{

	}
	~Tools() {}
};