#pragma once



class FieldCeil : public sf::Drawable
{
private:
	sf::Sprite m_closedCeilSprite;
	sf::Sprite m_openCeilSprite;
	sf::Sprite m_mineCeilSprite;
	sf::Sprite m_flagCeilSprite;
	sf::Sprite m_pointedCeilSprite;

	sf::Sprite m_numberOneSprite;//1
	sf::Sprite m_numberTwoSprite;//2
	sf::Sprite m_numberThreeSprite;//3
	sf::Sprite m_numberFourSprite;//4
	sf::Sprite m_numberFiveSprite;//5
	sf::Sprite m_numberSixSprite;//6
	sf::Sprite m_numberSevenSprite;//7
	sf::Sprite m_numberEightSprite;//8
	sf::Sprite m_numberNineSprite;//9

	void loadTextures();
	void loadSprites();

	int m_x, m_y;
	int m_sizeX, m_sizeY;	
	bool m_ceilOpened = false;
	int numberOfMinesAround = 0;

	void init();

	int m_state = CLOSED;
	bool m_hiddenMine = false;

public:
	void setNumberOfMinesAround(int cnt);
	void updateSprites();
	void setHiddenMine();
	bool ceilOpened();
	void openCeil();
	void pointToCeil();
	void unpointToCeil();
	bool isMine();
	void setState(int state);
	void setPosition(sf::Vector2i pos);
	void setPosition(int x, int y);
	void setSize(int x, int y);
	void setSize(sf::Vector2i);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	FieldCeil();
	virtual ~FieldCeil();
};

