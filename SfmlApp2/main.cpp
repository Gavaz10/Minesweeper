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

	while (window.isOpen())
	{
		window.parseEvents(field, settings);

		window.startFrame();

		switch (currentState)
		{
		default:
			break;
		InMenu:
			break;
		InSettings:
			break;
		InGame:
			window.getRenderWindow().draw(field);
			break;
		}

		
		
		window.endFrame();
	}

    return 0;
}

