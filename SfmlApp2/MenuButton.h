#pragma once
#include "stdafx.h"
class MenuButton : public sf::Drawable
{
private:
	int posX, posY, sizeX, sizeY;
	bool clicked = false;
	bool inArea(sf::Vector2i pos);
	bool clickedInArea = false;
	bool mouseInArea = false;

	sf::RectangleShape m_rectangle;
	sf::RectangleShape m_pointRect;
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void sendMousePos(sf::Vector2i);
	void sendMousePress(sf::Vector2i);
	void sendMouseRelease(sf::Vector2i);
	bool checkClick();
	void setRect(int posX, int posY, int sizeX, int sizeY);
	MenuButton(int posX, int posY, int sizeX, int sizeY);
	MenuButton();
	~MenuButton();
};

