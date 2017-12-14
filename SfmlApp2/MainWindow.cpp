#include "stdafx.h"
#include "MainWindow.h"


void MainWindow::onClose(Settings& settings)
{
	this->m_window.close();
	settings.saveSettings(SETTINGS_FILE);
}

void MainWindow::fixStates(game& state, Field& field, Menu& menu, Settings& settings)
{
	if (state.getChangedState() == false)
	{
		switch (state.getState())
		{
		default:
			break;
		case InMenu:
			menu.setUpWindow(m_window);
			break;
		case InGame:
			field.setUpField(settings, m_window);
			break;
		case InSettings:
			break;
		}
		state.setChangedState(true);
	}
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

void MainWindow::parseEvents(game& state, Field& field, Menu& menu, Settings& settings)
{
	fixStates(state, field, menu, settings);

	if (menu.isGameEnd())
		endGame();

	static bool clicked = false;
	static bool clicked2 = false;
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
	switch (state.getState())
	{
	default:
		break;
	case InGame:
		field.sendMousePos(mousePos);
		break;
	case InMenu:
		menu.sendMousePos(mousePos);
		break;
	case InSettings:
		settings.sendMousePos(mousePos);
		settings.reactToButtons();
		break;
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked)
	{
		switch (state.getState())
		{
		default:
			break;
		case InGame:
			field.clickMouse(mousePos);
			break;
		case InMenu:
			menu.sendMousePress(mousePos);
			break;
		case InSettings:
			settings.sendMousePress(mousePos);
		}
		
		clicked = true;
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && clicked)
	{
		switch (state.getState())
		{
		default:
			break;
		case InGame:
			field.releaseMouse(mousePos);
			break;
		case InMenu:
			menu.sendMouseRelease(mousePos);
			break;
		case InSettings:
			settings.sendMouseRelease(mousePos);
		}
		clicked = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && !clicked2)
	{
		switch (state.getState())
		{
		default:
			break;
		case InGame:
			field.rightClickMouse(mousePos);
			break;
		/*case InMenu:
			menu.sendMousePress(mousePos);
			break;*/
		}

		clicked2 = true;
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && clicked2)
	{
		switch (state.getState())
		{
		default:
			break;
		case InGame:
			field.rightReleaseMouse(mousePos);
			break;
		/*case InMenu:
			menu.sendMouseRelease(mousePos);
			break;*/
		}
		clicked2 = false;
	}

	switch (state.getState())
	{
	default:
		break;
	case InMenu:
		if (menu.isGameStarted()) 
		{
			state.setState(InGame);
			fixStates(state, field, menu, settings);
		}
		if (menu.isSettingsOpened())
		{
			state.openSettings();
		}
		break;
	case InGame:
		if (field.isGameEnd())
		{
			state.setState(InMenu);
			fixStates(state, field, menu, settings);
		}
		break;
	case InSettings:
		if (settings.isBack())
		{
			state.closeSettings();
		}
		break;
	}

	sf::Event event;
	while (this->m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			onClose(settings);
		if (event.type == sf::Event::KeyPressed && state.getState() == InGame)
			field.anyButton();
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
