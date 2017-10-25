// SfmlApp2.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"

int main()
{
	Settings settings;
	settings.loadSettings(SETTINGS_FILE);

	MainWindow window(settings.getSettingInt("screen_size_x"), settings.getSettingInt("screen_size_y"));

	Field field(settings);

	while (window.isOpen())
	{
		window.parseEvents(field, settings);

		window.startFrame();

		window.getRenderWindow().draw(field);
		
		window.endFrame();
	}


    return 0;
}

