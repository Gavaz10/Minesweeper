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

void MainWindow::setResolution(sf::Vector2i size)
{
	this->setResolution(size.x, size.y);
}

bool MainWindow::isOpen()
{
	return this->m_window.isOpen();
}

void MainWindow::parseEvents(Field& field, Settings& settings)
{
	static bool clicked = false;
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
	field.sendMousePos(mousePos);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked)
	{
		field.clickMouse(mousePos);
		clicked = true;
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && clicked)
	{
		field.releaseMouse(mousePos);
		clicked = false;
	}

	sf::Event event;
	while (this->m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			onClose(settings);
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

MainWindow::MainWindow(sf::Vector2i l_screenSize)
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
