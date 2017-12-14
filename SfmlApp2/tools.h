#pragma once
#include "stdafx.h"

void print(const char*);//python lelellelelel
void println(const char*);
bool isNumber(std::string str);
int toInt(std::string str);

void setSpriteScale(sf::Sprite& sprite, float newSizeX, float newSizeY);

void loadFont(sf::Font&);
void loadFonts();

void loadTextureFromFile(sf::Texture& texture, const char* fileName);
void loadTextures();

void endGame();