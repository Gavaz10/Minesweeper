#pragma once

#define SWEEPER_DEBUG 1

#define WINDOW_TITLE "MineSweeper"
#define SETTINGS_FILE "settings.ini"

enum ceilState : int
{
	CLOSED = 0,
	OPEN,
	MINE,
	FLAG,
	POINTED
};