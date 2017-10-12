#pragma once
class MainWindow
{
private:
	sf::RenderWindow window{ sf::VideoMode(640, 480), "SFML works!", sf::Style::Titlebar | sf::Style::Close };
public:
	sf::RenderWindow& getRenderWindow();
	MainWindow();
	~MainWindow();
};

