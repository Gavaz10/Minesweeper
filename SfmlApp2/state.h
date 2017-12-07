#pragma once
enum GameState : int
{
	InMenu = 0,
	InSettings = 1,
	InGame = 2
};

class game
{
private:
	GameState state = InGame;
public:
	void openSettings()
	{
		if (state == InMenu)
			state = InSettings;
	}
	void closeSettings()
	{
		if (state == InSettings)
			state = InMenu;
	}
	void startGame()
	{
		if (state == InMenu)
			state = InGame;
	}
	void endGame()
	{
		if (state == InGame)
			state = InMenu;
	}
	int getState()
	{
		return state;
	}
};