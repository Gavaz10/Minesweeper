#pragma once
enum GameState : int
{
	InMenu = 0,
	InSettings,
	InGame
};

GameState currentState = InMenu;