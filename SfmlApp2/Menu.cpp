#include "stdafx.h"
#include "Menu.h"


void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);
	target.draw(m_playButton, states);
	target.draw(m_settingsButton, states);
	target.draw(m_quitButton, states);
}

void Menu::sendMousePos(sf::Vector2i pos)
{
	m_playButton.sendMousePos(pos);
	m_settingsButton.sendMousePos(pos);
	m_quitButton.sendMousePos(pos);
}

void Menu::sendMousePress(sf::Vector2i pos)
{
	m_playButton.sendMousePress(pos);
	m_settingsButton.sendMousePress(pos);
	m_quitButton.sendMousePress(pos);
}

void Menu::sendMouseRelease(sf::Vector2i pos)
{
	m_playButton.sendMouseRelease(pos);
	m_settingsButton.sendMouseRelease(pos);
	m_quitButton.sendMouseRelease(pos);
}

Menu::Menu()
{
	
}

void Menu::setUpWindow(sf::RenderWindow& l_renderWindow)
{
	screenSizeX = 640, screenSizeY = 480;

	m_rectangle.setSize({ (float)screenSizeX, (float)screenSizeY });
	m_rectangle.setFillColor(sf::Color::White);

	int buttonSizeX = 300, buttonSizeY = 40;

	m_playButton.setRect(screenSizeX / 2 - buttonSizeX / 2, 100, buttonSizeX, buttonSizeY);
	m_settingsButton.setRect(screenSizeX / 2 - buttonSizeX / 2, 200, buttonSizeX, buttonSizeY);
	m_quitButton.setRect(screenSizeX / 2 - buttonSizeX / 2, 300, buttonSizeX, buttonSizeY);

	l_renderWindow.create(sf::VideoMode(screenSizeX, screenSizeY), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
}

Menu::~Menu()
{

}
