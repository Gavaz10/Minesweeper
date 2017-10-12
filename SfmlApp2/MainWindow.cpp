#include "stdafx.h"
#include "MainWindow.h"


sf::RenderWindow& MainWindow::getRenderWindow()
{
	return (this->m_window);
}

void MainWindow::setResolution(int sizeX, int sizeY)
{
	m_window.create(sf::VideoMode(sizeX, sizeY), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
}

void MainWindow::setResolution(Point2Di size)
{
	this->setResolution(size.x, size.y);
}

MainWindow::MainWindow()
{
}


MainWindow::~MainWindow()
{
}
