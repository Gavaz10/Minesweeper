// SfmlApp2.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"

int main()
{
	Settings settings;
	MainWindow window;
	Field field(5, 5);
	

	while (window.isOpen())
	{
		window.parseEvents();

		window.startFrame();
		
		window.endFrame();
	}


    return 0;
}

