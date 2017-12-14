// SfmlApp2.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"

int main()
{
	

#if SWEEPER_DEBUG == 0
	FreeConsole();
#endif // SWEEPER_DEBUG == 0

	srand(time(0));

	loadFonts();//load all fonts

	loadTextures();//load all textures

	Settings settings;
	settings.loadSettings(SETTINGS_FILE);//load all settings

	MainWindow window;

	Menu menu;

	Field field;

	game Game;
	 
	while (window.isOpen())
	{
		window.parseEvents(Game, field, menu, settings);

		window.startFrame();

		switch (Game.getState())//what to draw depending on state
		{
		case InMenu:
			window.getRenderWindow().draw(menu);
			break;
		case InSettings:
			window.getRenderWindow().draw(settings);
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

