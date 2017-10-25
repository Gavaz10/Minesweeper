#include "stdafx.h"
#include "tools.h"

bool isNumber(std::string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (str[i] > '9' || str[i] < '0')
			return false;
	}
	return true;
}

int toInt(std::string str)
{
	return std::stoi(str);
}

void loadTextureFromFile(sf::Texture& texture, const char * fileName)
{
	if (!texture.loadFromFile(fileName))
		throw std::bad_exception();
}

void setSpriteScale(sf::Sprite& sprite, float newSizeX, float newSizeY)
{
	float oldRectX = sprite.getTextureRect().width;
	float oldRectY = sprite.getTextureRect().height;

	sprite.setScale({newSizeX / oldRectX, newSizeY / oldRectY});
}
