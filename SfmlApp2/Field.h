#pragma once
class Field : public sf::Drawable
{
private:
	enum ceilStates : int
	{
		CLOSED = 0,
		CLICKED_NOT_OPENED,
		OPENED,
	};
	int m_ceilSizeX = 20, m_ceilSizeY = 20;
	int m_numberOfCeilsX = 20, m_numberOfCeilsY = 20;
	int m_numberOfMines = 15;
	std::vector<std::vector<int> > m_ceilStates;
	std::vector<std::vector<sf::Sprite> > m_ceilSprites;
	sf::RectangleShape m_rectangle;
	sf::Texture m_blueBoardTexture;
	sf::Texture m_greenBoardTexture;
	sf::Texture m_blueSheet;
	void init(Settings&);
	Point2Di lastPos{-1, -1};
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void setSize(int x, int y);
	void setSize(Point2Di);
	void clickMouse(Point2Di);
	void clickNotRelease(Point2Di);
	bool clickBack(Point2Di);
	Field(Settings&);
	~Field();
};

