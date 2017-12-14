#pragma once
#include "stdafx.h"

class Field : public sf::Drawable
{
private:
	bool gameOver = false;
	bool gameEnd = false;
	bool gameStarted = false;
	int m_ceilSizeX = 20, m_ceilSizeY = 20;
	int m_numberOfCeilsX = 20, m_numberOfCeilsY = 20;
	int m_numberOfMines = 15;
	std::vector<std::vector<FieldCeil> > m_ceils;
	void init(Settings&);
	sf::Vector2i lastPontedCeil{ -1, -1 };
	sf::Vector2i clickedPos{ -1, -1 };
	sf::Vector2i lastPontedCeil2{ -1, -1 };
	sf::Vector2i clickedPos2{ -1, -1 };
	bool firstClick = true;
	bool checkMousePosition(int, int);
	bool checkMousePosition(sf::Vector2i);
	bool checkCeilPosition(int, int);
	bool checkCeilPosition(sf::Vector2i);
	sf::Vector2i getCeilPos(sf::Vector2i);
	sf::RectangleShape m_rectangle;
	void openCeil(int x, int y);
	void flagCeil(int x, int y);
	int calcNumberOfMinesAround(int x, int y);
	void generateMines(int l_numberOfMines, sf::Vector2i l_firstClick);
	sf::Vector2i pointedCeil{ -1, -1 };
	sf::Vector2i pointedCeil2{ -1, -1 };
	void setUpWindow(sf::RenderWindow&);
	sf::Text gameOverText{"GAME OVER", arial, 50U};
	sf::Text gameOverText2{ "press any button to go to the menu", arial, 50U };
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	bool isGameOver() { return gameOver; }
	bool isGameEnd() { return gameEnd; }
	bool isGameStarted() { return gameStarted; }
	void setSize(int x, int y);
	void setSize(sf::Vector2i);
	void clickMouse(sf::Vector2i);
	void releaseMouse(sf::Vector2i);
	void rightClickMouse(sf::Vector2i);
	void rightReleaseMouse(sf::Vector2i);
	void sendMousePos(sf::Vector2i);
	void startGame(Settings&);
	void endGame();
	void setUpField(Settings&, sf::RenderWindow&);
	void anyButton();
	Field();
	~Field();
};

