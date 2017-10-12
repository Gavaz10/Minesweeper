// SfmlApp2.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"

int main()
{
	MainWindow window;

	std::pair<int, int> pair;

	while (window.getRenderWindow().isOpen())
	{
		sf::Event event;
		while (window.getRenderWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.getRenderWindow().close();
		}

		window.getRenderWindow().clear();
		
		window.getRenderWindow().display();
	}


    return 0;
}

