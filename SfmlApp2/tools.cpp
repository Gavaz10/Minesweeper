#include "stdafx.h"
#include "tools.h"

void print(const char* msg)
{
	std::cout << msg;
}

void println(const char* msg)
{
	print(msg);
	std::cout << '\n';
}

bool isNumber(std::string str)
{
	for (uint32_t i = 0; i < str.size(); i++)
	{
		if (i == 0 && str[i] == '-' && str.size() != 1)
			continue;
		if (str[i] > '9' || str[i] < '0')
			return false;
	}
	return true;
}

int toInt(std::string str)
{
	if (!isNumber(str))
		throw new std::exception();
	return std::stoi(str);
}



void setSpriteScale(sf::Sprite& sprite, float newSizeX, float newSizeY)
{
	float oldRectX = (float)sprite.getTextureRect().width;
	float oldRectY = (float)sprite.getTextureRect().height;

	sprite.setScale({newSizeX / oldRectX, newSizeY / oldRectY});
}

void loadFont(sf::Font& font, const char* name)
{
	if (!font.loadFromFile(name))
		throw new std::exception(((std::string)(name) + " not found").c_str());
}

void loadFonts()
{
	loadFont(arial, "arial.ttf");
}

void loadTextureFromFile(sf::Texture& texture, const char* fileName)
{
	if (!texture.loadFromFile(fileName))
		throw std::exception(("failed to load texture from file: " + (std::string)(fileName)).c_str());
}

void loadTextures()
{
	loadTextureFromFile(gameObjectsTexture, "images/tiles.jpg");
}

void endGame()
{
	exit(0);
}