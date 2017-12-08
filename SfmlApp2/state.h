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
	GameState state = InMenu;
	bool changedState = false;//shows if you changed state of game not just GameState
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
	void setState(GameState state)
	{
		if (state != this->state)
			changedState = false;
		this->state = state;
	}
	bool getChangedState()
	{
		return changedState;
	}
	void setChangedState(bool b)
	{
		changedState = b;
	}
};