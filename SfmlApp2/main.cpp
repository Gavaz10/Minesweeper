// SfmlApp2.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"

int main()
{
	

#if SWEEPER_DEBUG == 0
	FreeConsole();
#endif // SWEEPER_DEBUG == 0

	srand(time(0));

	Settings settings;
	settings.loadSettings(SETTINGS_FILE);

	MainWindow window;

	Menu menu;

	Field field;

	game Game;
	 
	while (window.isOpen())
	{
		window.parseEvents(Game, field, menu, settings);

		window.startFrame();

		switch (Game.getState())
		{
		case InMenu:
			window.getRenderWindow().draw(menu);
			break;
		case InSettings:
			break;
		case InGame:
			window.getRenderWindow().draw(field);
			break;
		default:
			throw new std::exception("wrong state of game");
		}

		window.endFrame();
	}

    return 0;
}

