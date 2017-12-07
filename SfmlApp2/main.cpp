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

	MainWindow window(settings.getSettingInt("screen_size_x"), settings.getSettingInt("screen_size_y"));

	Field field(settings);

	game Game;

	while (window.isOpen())
	{
		window.parseEvents(field, settings);

		window.startFrame();

		switch (Game.getState())
		{
		case InMenu:
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

