#pragma once
class Field : public sf::Drawable
{
private:
	int m_ceilSizeX = 15, m_ceilSizeY = 15;
	int m_numberOfCeilsX = 0, m_numberOfCeilsY = 0;
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void setSize(int x, int y);
	void setSize(Point2Di);
	Field();
	Field(int x, int y);
	Field(Point2Di);
	~Field();
};

