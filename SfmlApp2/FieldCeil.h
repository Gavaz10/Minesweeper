#pragma once



class FieldCeil : public sf::Drawable
{
private:
	sf::Sprite m_closedCeilSprite;
	sf::Sprite m_openCeilSprite;
	sf::Sprite m_mineCeilSprite;
	sf::Sprite m_flagCeilSprite;
	sf::Sprite m_pointedCeilSprite;

	void loadTextures();
	void loadSprites();

	int m_x, m_y;

	int m_sizeX, m_sizeY;

	bool m_hiddenMine = false;
	bool m_ceilOpened = false;

	void init();

	int m_state = CLOSED;

public:
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

