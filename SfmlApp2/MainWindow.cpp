#include "stdafx.h"
#include "MainWindow.h"


void MainWindow::onClose(Settings& settings)
{
	this->m_window.close();
	settings.saveSettings(SETTINGS_FILE);
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

void MainWindow::parseEvents(Field& field, Settings& settings)
{
	sf::Event event;
	while (this->m_window.pollEvent(event))
	{
		static bool mousePressed = false;
		static Point2Di prevPos(-1, -1);
		if (event.type == sf::Event::Closed)
			onClose(settings);
		if (event.type == sf::Event::MouseButtonPressed)
		{
			field.clickNotRelease(prevPos);
			mousePressed = true;
		}
		if (event.type == sf::Event::MouseMoved)
		{
			mousePressed = field.clickBack(prevPos);
		}
			
		if (event.type == sf::Event::MouseButtonReleased && mousePressed)
		{
			field.clickMouse(prevPos);
			mousePressed = false;
		}
		
		prevPos = { sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y };
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

MainWindow::MainWindow(Point2Di l_screenSize)
{
	setResolution(l_screenSize.x, l_screenSize.y);
}

MainWindow::MainWindow(int l_screenSizeX, int l_screenSizeY)
{
	setResolution(l_screenSizeX, l_screenSizeY);
}

MainWindow::MainWindow()
{
}


MainWindow::~MainWindow()
{
}
