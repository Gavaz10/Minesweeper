#include "stdafx.h"

void FieldCeil::setNumberOfMinesAround(int cnt)
{
	numberOfMinesAround = cnt;
}

void FieldCeil::updateSprites()
{
	loadSprites();
}

void FieldCeil::setHiddenMine()
{
	m_hiddenMine = true;
}

bool FieldCeil::ceilOpened()
{
	return m_ceilOpened;
}

bool FieldCeil::isFlagged()
{
	return m_isFlagged;
}

void FieldCeil::openCeil()
{
	if (ceilOpened())
		return;
	if (m_isFlagged)
		return;
	m_hiddenMine ? setState(MINE) : setState(OPEN);
	m_ceilOpened = true;
	std::cout << "opened" << ' ' << m_x << " " << m_y << '\n';
}

void FieldCeil::flagCeil()
{
	if (ceilOpened())
		return;
	setState(m_isFlagged ? CLOSED : FLAG);
	m_isFlagged = !m_isFlagged;
}

void FieldCeil::unFlagCeil()
{
	if (ceilOpened())
		return;
	setState(CLOSED);
	m_isFlagged = false;
}

void FieldCeil::pointToCeil()
{
	if (m_isFlagged) return;
	if (!m_ceilOpened) setState(POINTED);
}

void FieldCeil::unpointToCeil()
{
	if (!m_ceilOpened) setState(m_isFlagged ? FLAG : CLOSED);
}

bool FieldCeil::isMine()
{
	return m_hiddenMine;
}

void FieldCeil::loadSprites()
{
	m_closedCeilSprite.setTexture(gameObjectsTexture);
	m_openCeilSprite.setTexture(gameObjectsTexture);
	m_mineCeilSprite.setTexture(gameObjectsTexture);
	m_flagCeilSprite.setTexture(gameObjectsTexture);
	m_pointedCeilSprite.setTexture(gameObjectsTexture);

	m_numberOneSprite.setTexture(gameObjectsTexture);
	m_numberTwoSprite.setTexture(gameObjectsTexture);
	m_numberThreeSprite.setTexture(gameObjectsTexture);
	m_numberFourSprite.setTexture(gameObjectsTexture);
	m_numberFiveSprite.setTexture(gameObjectsTexture);
	m_numberSixSprite.setTexture(gameObjectsTexture);
	m_numberSevenSprite.setTexture(gameObjectsTexture);
	m_numberEightSprite.setTexture(gameObjectsTexture);

	m_closedCeilSprite.setTextureRect({ 320, 0, 32, 32 });
	m_openCeilSprite.setTextureRect({ 0, 0, 32, 32 });
	m_mineCeilSprite.setTextureRect({ 288, 0, 32, 32 });
	m_flagCeilSprite.setTextureRect({ 352, 0, 32, 32 });
	m_pointedCeilSprite.setTextureRect({ 384, 0, 32, 32 });

	m_numberOneSprite.setTextureRect({ 32, 0, 32, 32 });
	m_numberTwoSprite.setTextureRect({ 64, 0, 32, 32 });
	m_numberThreeSprite.setTextureRect({ 96, 0, 32, 32 });
	m_numberFourSprite.setTextureRect({ 128, 0, 32, 32 });
	m_numberFiveSprite.setTextureRect({ 160, 0, 32, 32 });
	m_numberSixSprite.setTextureRect({ 192, 0, 32, 32 });
	m_numberSevenSprite.setTextureRect({ 224, 0, 32, 32 });
	m_numberEightSprite.setTextureRect({ 256, 0, 32, 32 });

	setSpriteScale(m_closedCeilSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_openCeilSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_mineCeilSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_flagCeilSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_pointedCeilSprite, m_sizeX, m_sizeY);

	setSpriteScale(m_numberOneSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_numberTwoSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_numberThreeSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_numberFourSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_numberFiveSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_numberSixSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_numberSevenSprite, m_sizeX, m_sizeY);
	setSpriteScale(m_numberEightSprite, m_sizeX, m_sizeY);
}

void FieldCeil::init()
{
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

	m_numberOneSprite.setPosition(x, y);
	m_numberTwoSprite.setPosition(x, y);
	m_numberThreeSprite.setPosition(x, y);
	m_numberFourSprite.setPosition(x, y);
	m_numberFiveSprite.setPosition(x, y);
	m_numberSixSprite.setPosition(x, y);
	m_numberSevenSprite.setPosition(x, y);
	m_numberEightSprite.setPosition(x, y);
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
		switch (numberOfMinesAround)
		{
		case 1:
			renderTarget.draw(m_numberOneSprite, states);
			break;
		case 2:
			renderTarget.draw(m_numberTwoSprite, states);
			break;
		case 3:
			renderTarget.draw(m_numberThreeSprite, states);
			break;
		case 4:
			renderTarget.draw(m_numberFourSprite, states);
			break;
		case 5:
			renderTarget.draw(m_numberFiveSprite, states);
			break;
		case 6:
			renderTarget.draw(m_numberSixSprite, states);
			break;
		case 7:
			renderTarget.draw(m_numberSevenSprite, states);
			break;
		case 8:
			renderTarget.draw(m_numberEightSprite, states);
			break;
		default:
			break;
		}
		
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
