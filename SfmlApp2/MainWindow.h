#pragma once
class MainWindow
{
private:
	sf::RenderWindow m_window{ sf::VideoMode(640, 480), "SFML works!", sf::Style::Titlebar | sf::Style::Close };
public:
	sf::RenderWindow& getRenderWindow();
	void setResolution(int sizeX, int sizeY);
	void setResolution(Point2Di size);
	MainWindow();
	~MainWindow();
};

