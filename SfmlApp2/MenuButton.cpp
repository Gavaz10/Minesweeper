#include "stdafx.h"
#include "MenuButton.h"

void MenuButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);
	if (mouseInArea)
		target.draw(m_pointRect, states);
}

bool MenuButton::inArea(sf::Vector2i pos)
{
	return pos.x >= posX && pos.x <= posX + sizeX && pos.y >= posY && pos.y <= posY + sizeY;
}

void MenuButton::sendMousePos(sf::Vector2i pos)
{
	if (inArea(pos))
		mouseInArea = true;
	else
		mouseInArea = false;
}

void MenuButton::sendMousePress(sf::Vector2i pos)
{
	if (inArea(pos))
		clickedInArea = true;
	else
		clickedInArea = false;
}

void MenuButton::sendMouseRelease(sf::Vector2i pos)
{
	if (inArea(pos) && clickedInArea)
		clicked = true;
	else
		clicked = false;
}

bool MenuButton::checkClick()
{
	if (clicked == true)
	{
		clicked = false;
		return true;
	}
	return false;
}

void MenuButton::setRect(int posX, int posY, int sizeX, int sizeY)
{
	this->posX = posX;
	this->posY = posY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	m_rectangle.setPosition(posX, posY);
	m_rectangle.setSize({ (float)sizeX, (float)sizeY });
	m_rectangle.setFillColor(sf::Color::White);
	m_rectangle.setOutlineColor(sf::Color::Black);
	m_rectangle.setOutlineThickness(1.f);//to test

	m_pointRect.setPosition(posX + 1, posY + 1);
	m_pointRect.setSize({ (float)sizeX - 2.f, (float)sizeY - 2.f });
	m_pointRect.setFillColor(sf::Color::Red);

}

MenuButton::MenuButton(int posX, int posY, int sizeX, int sizeY)
{
	setRect(posX, posY, sizeX, sizeY);
}

MenuButton::MenuButton()
{
}


MenuButton::~MenuButton()
{
}
