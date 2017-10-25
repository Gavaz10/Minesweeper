#include "stdafx.h"
#include "Field.h"


void Field::init(Settings& l_settings)
{
	m_numberOfCeilsX = l_settings.getSettingInt("field_ceil_count_x");
	m_numberOfCeilsY = l_settings.getSettingInt("field_ceil_count_y");
	m_ceilSizeX = l_settings.getSettingInt("field_ceil_size_x");
	m_ceilSizeY = l_settings.getSettingInt("field_ceil_size_y");
	m_numberOfMines = l_settings.getSettingInt("number_of_mines");

	m_rectangle.setSize({ m_ceilSizeX * m_numberOfCeilsX * 1.f, m_ceilSizeY * m_numberOfCeilsY * 1.f });
	loadTextureFromFile(m_blueBoardTexture, "images/blue_boardthumb.png");
	loadTextureFromFile(m_greenBoardTexture, "images/green_boardthumb.png");
	loadTextureFromFile(m_blueSheet, "images/bluesheet.png");

	m_ceilStates.resize(m_numberOfCeilsY, std::vector<int>(m_numberOfCeilsX, CLOSED));
	m_ceilSprites.resize(m_numberOfCeilsY, std::vector<sf::Sprite>(m_numberOfCeilsX, sf::Sprite(m_blueBoardTexture, sf::IntRect(90, 90, 19, 19))));
	for (int i = 0; i < m_numberOfCeilsY; i++)
	{
		for (int j = 0; j < m_numberOfCeilsX; j++)
		{
			m_ceilSprites[i][j].setPosition(j * m_ceilSizeX * 1.f, i * m_ceilSizeY * 1.f);
			setSpriteScale(m_ceilSprites[i][j], m_ceilSizeX * 1.f, m_ceilSizeY * 1.f);
		}
	}
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);
	for (auto vec : m_ceilSprites)
	{
		for (auto ceil : vec)
		{
			target.draw(ceil, states);
		}
	}
}

void Field::setSize(int x, int y)
{
	m_numberOfCeilsX = x;
	m_numberOfCeilsY = y;
}

void Field::setSize(Point2Di size)
{
	setSize(size.x, size.y);
}

void Field::clickMouse(Point2Di pos)
{
	int x = pos.x / m_ceilSizeX, y = pos.y / m_ceilSizeY;
	if (x < 0 || y < 0 || x >= m_numberOfCeilsX || y >= m_numberOfCeilsY)
		return;
	if (m_ceilStates[y][x] == OPENED)
		return;
	m_ceilStates[y][x] = OPENED;
	m_ceilSprites[y][x].setTexture(m_blueSheet);
	m_ceilSprites[y][x].setTextureRect({505, 2, 15, 15});
	setSpriteScale(m_ceilSprites[y][x], m_ceilSizeX * 1.f, m_ceilSizeY * 1.f);
}

void Field::clickNotRelease(Point2Di pos)
{
	int x = pos.x / m_ceilSizeX, y = pos.y / m_ceilSizeY;
	if (x < 0 || y < 0 || x >= m_numberOfCeilsX || y >= m_numberOfCeilsY)
		return;
	if (m_ceilStates[y][x] == OPENED)
		return;
	m_ceilSprites[y][x].setTextureRect({0, 0, 19, 19});
	lastPos = { x, y };
}

bool Field::clickBack(Point2Di pos)
{
	int x = pos.x / m_ceilSizeX, y = pos.y / m_ceilSizeY;
	if (x < 0 || y < 0 || x >= m_numberOfCeilsX || y >= m_numberOfCeilsY)
		return false;
	if (m_ceilStates[y][x] == OPENED)
		return false;
	if (x != lastPos.x || y != lastPos.y)
	{
		m_ceilSprites[y][x].setTextureRect({ 90, 90, 19, 19 });
		return false;
	}
	return true;
}

Field::Field(Settings& l_settings)
{
	init(l_settings);
}


Field::~Field()
{
}
