#pragma once
class MainWindow
{
private:
	sf::RenderWindow m_window{ sf::VideoMode(640, 480), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close };
	void onClose(Settings&);
public:
	sf::RenderWindow& getRenderWindow();
	void setResolution(int sizeX, int sizeY);
	void setResolution(Point2Di size);
	bool isOpen();

	void parseEvents(Field& field, Settings& settings);
	void startFrame();
	void endFrame();
	MainWindow(Point2Di size);
	MainWindow(int l_screenSizeX, int l_screenSizeY);
	MainWindow();
	~MainWindow();
};

