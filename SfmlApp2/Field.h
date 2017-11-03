#pragma once
#include "stdafx.h"

class Field : public sf::Drawable
{
private:


	int m_ceilSizeX = 20, m_ceilSizeY = 20;
	int m_numberOfCeilsX = 20, m_numberOfCeilsY = 20;
	int m_numberOfMines = 15;
	std::vector<std::vector<FieldCeil> > m_ceils;
	void init(Settings&);
	sf::Vector2i lastPontedCeil{-1, -1};
	bool checkMousePosition(int, int);
	bool checkMousePosition(sf::Vector2i);
	bool checkCeilPosition(int, int);
	bool checkCeilPosition(sf::Vector2i);
	sf::Vector2i getCeilPos(sf::Vector2i);
	sf::RectangleShape m_rectangle;
	void openCeil(int x, int y);
	int calcNumberOfMinesAround(int x, int y);
	void generateMines(int l_numberOfMines, sf::Vector2i l_firstClick);
	sf::Vector2i pointedCeil{-1, -1};
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void setSize(int x, int y);
	void setSize(sf::Vector2i);
	void clickMouse(sf::Vector2i);
	void releaseMouse(sf::Vector2i);
	void sendMousePos(sf::Vector2i);
	void startGame(Settings&);
	void endGame();
	Field(Settings&);
	~Field();
};

