#include "stdafx.h"

bool FieldCeil::ceilOpened()
{
	return m_ceilOpened;
}

void FieldCeil::openCeil()
{
	if (ceilOpened())
		return;
	m_hiddenMine ? setState(MINE) : setState(OPEN);
	m_ceilOpened = true;
	std::cout << "opened" << ' ' << m_x << " " << m_y << '\n';
}

void FieldCeil::pointToCeil()
{
	if (!m_ceilOpened) setState(POINTED);
}

void FieldCeil::unpointToCeil()
{
	if (!m_ceilOpened) setState(CLOSED);
}

bool FieldCeil::isMine()
{
	return m_hiddenMine;
}

void FieldCeil::loadTextures()
{
	if (texturesLoaded)
		return;

	loadTextureFromFile(m_closedCeilTexture, "images/blue_boardthumb.png");
	loadTextureFromFile(m_openCeilTexture, "images/bluesheet.png");
	loadTextureFromFile(m_mineCeilTexture, "images/minesweeper_gamethumb.png");
	loadTextureFromFile(m_flagCeilTexture, "images/blue_boardthumb.png");
	loadTextureFromFile(m_pointedCeilTexture, "images/blue_boardthumb.png");

	texturesLoaded = true;
}

void FieldCeil::loadSprites()
{
	m_closedCeilSprite.setTexture(m_closedCeilTexture);
	m_openCeilSprite.setTexture(m_openCeilTexture);
	m_mineCeilSprite.setTexture(m_mineCeilTexture);
	m_flagCeilSprite.setTexture(m_flagCeilTexture);
	m_pointedCeilSprite.setTexture(m_pointedCeilTexture);

	m_closedCeilSprite.setTextureRect({ 90, 90, 19, 19 });
	m_openCeilSprite.setTextureRect({ 600, 20, 19, 19 });
	m_mineCeilSprite.setTextureRect({ 0, 0, 190, 190 });
	m_flagCeilSprite.setTextureRect({ 19, 19, 19, 19 });
	m_pointedCeilSprite.setTextureRect({ 0, 0, 19, 19 });
}

void FieldCeil::init()
{
	loadTextures();
	loadSprites();
}

void FieldCeil::setState(int state)
{
	m_state = state;
}

void FieldCeil::setPosition(sf::Vector2i pos)
{
	setPosition(pos.x, pos.y);
}

void FieldCeil::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
	m_closedCeilSprite.setPosition(x, y);
	m_openCeilSprite.setPosition(x, y);
	m_mineCeilSprite.setPosition(x, y);
	m_flagCeilSprite.setPosition(x, y);
	m_pointedCeilSprite.setPosition(x, y);
}

void FieldCeil::setSize(int x, int y)
{
	m_sizeX = x;
	m_sizeY = y;
}

void FieldCeil::setSize(sf::Vector2i size)
{
	setSize(size.x, size.y);
}

void FieldCeil::draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const
{
	switch (m_state) {
	case CLOSED:
		renderTarget.draw(m_closedCeilSprite, states);
		break;
	case OPEN:
		renderTarget.draw(m_openCeilSprite, states);
		break;
	case MINE:
		renderTarget.draw(m_mineCeilSprite, states);
		break;
	case FLAG:
		renderTarget.draw(m_flagCeilSprite, states);
		break;
	case POINTED:
		renderTarget.draw(m_pointedCeilSprite, states);
		break;
	default:
		throw new std::exception("wrong ceil state");
		break;
	};
}

FieldCeil::FieldCeil()
{
	init();
}


FieldCeil::~FieldCeil()
{

}
