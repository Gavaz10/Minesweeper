#include "stdafx.h"
#include "Field.h"


void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void Field::setSize(int x, int y)
{
	this->m_numberOfCeilsX = x;
	this->m_numberOfCeilsY = y;
}

void Field::setSize(Point2Di size)
{
	this->setSize(size.x, size.y);
}

Field::Field()
{
}

Field::Field(int x, int y)
{
	setSize(x, y);
}

Field::Field(Point2Di size)
{
	this->setSize(size.x, size.y);
}


Field::~Field()
{
}
