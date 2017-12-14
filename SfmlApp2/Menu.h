#pragma once
#include "stdafx.h"
class Menu : public sf::Drawable
{
private:
	bool gameStarted = false;
	sf::RectangleShape m_rectangle;
	int screenSizeY, screenSizeX;
	MenuButton m_playButton, m_settingsButton, m_quitButton;
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void sendMousePos(sf::Vector2i);
	void sendMousePress(sf::Vector2i);
	void sendMouseRelease(sf::Vector2i);
	bool isGameStarted() { return m_playButton.checkClick(); }
	bool isSettingsOpened() { return m_settingsButton.checkClick(); }
	bool isGameEnd() { return m_quitButton.checkClick(); }
	void setUpWindow(sf::RenderWindow&);
	Menu();
	~Menu();
};

