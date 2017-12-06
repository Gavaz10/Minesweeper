#include "stdafx.h"
#include "Menu.h"


void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

Menu::Menu(Settings& l_settings, sf::RenderWindow& l_renderWindow)
{
	int screenSizeX = 640, screenSizeY = 480;
	l_renderWindow.create(sf::VideoMode(screenSizeX, screenSizeY), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
}

Menu::~Menu()
{

}
