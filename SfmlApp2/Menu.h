#pragma once
#include "stdafx.h"
class Menu : public sf::Drawable
{
private:
	bool gameStarted = false;
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	bool isGameStarted() { return gameStarted; }
	Menu(Settings&, sf::RenderWindow&);
	~Menu();
};

