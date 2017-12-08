#pragma once
class MainWindow
{
private:
	sf::RenderWindow m_window{ sf::VideoMode(640, 480), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close };
	void onClose(Settings&);
	void fixStates(game& state, Field& field, Menu& menu, Settings& settings);
public:
	sf::RenderWindow& getRenderWindow();
	void setResolution(int sizeX, int sizeY);
	void setResolution(sf::Vector2i size);
	bool isOpen();

	void parseEvents(game& state, Field& field, Menu& menu, Settings& settings);
	void startFrame();
	void endFrame();
	MainWindow(sf::Vector2i size);
	MainWindow(int l_screenSizeX, int l_screenSizeY);
	MainWindow();
	~MainWindow();
};

