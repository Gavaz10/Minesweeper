#include "stdafx.h"
#include "MainWindow.h"


void MainWindow::onClose()
{
	this->m_window.close();
}

sf::RenderWindow& MainWindow::getRenderWindow()
{
	return (this->m_window);
}

void MainWindow::setResolution(int sizeX, int sizeY)
{
	m_window.create(sf::VideoMode(sizeX, sizeY), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
}

void MainWindow::setResolution(Point2Di size)
{
	this->setResolution(size.x, size.y);
}

bool MainWindow::isOpen()
{
	return this->m_window.isOpen();
}

void MainWindow::parseEvents()
{
	sf::Event event;
	while (this->m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			onClose();
	}
}

void MainWindow::startFrame()
{
	this->m_window.clear();
}

void MainWindow::endFrame()
{
	this->m_window.display();
}

MainWindow::MainWindow()
{
}


MainWindow::~MainWindow()
{
}
