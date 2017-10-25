#pragma once
#include "stdafx.h"

bool isNumber(std::string str);
int toInt(std::string str);
void loadTextureFromFile(sf::Texture& texture, const char* fileName);
void setSpriteScale(sf::Sprite& sprite, float newSizeX, float newSizeY);