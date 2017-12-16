#pragma once
class Settings : public sf::Drawable
{
private:
	std::map<std::string, int> m_settingsMapInt;
	std::map<std::string, std::string> m_settingsMapString;
	std::set<std::string> m_setOfAvailableSettings;

	void addDefaultSettingString(std::string l_settingName, std::string defaultValue);
	void addDefaultSettingInt(std::string l_settingName, int defaultValue);
	
	sf::RectangleShape m_rectangle;
	int screenSizeY, screenSizeX;

	sf::Text fieldSizeX{    "Game field vertical size"  , arial, 20U };
	sf::Text fieldSizeY{    "Game field horizontal size", arial, 20U };
	sf::Text ceilY{         "Game ceil vertical size"   , arial, 20U };
	sf::Text ceilX{         "Game ceil horizontal size" , arial, 20U };
	sf::Text numberOfMines{ "Number of mines"           , arial, 20U };

	sf::Text fieldSizeXvalue{    "", arial, 20U };
	sf::Text fieldSizeYvalue{    "", arial, 20U };
	sf::Text ceilYvalue{         "", arial, 20U };
	sf::Text ceilXvalue{         "", arial, 20U };
	sf::Text numberOfMinesvalue{ "", arial, 20U };

	MenuButton m_backButton;
	MenuButton fieldSizeXplus, fieldSizeXminus, fieldSizeYplus, fieldSizeYminus;//number of ceils in x and y axis
	MenuButton ceilSizeXplus, ceilSizeXminus, ceilSizeYplus, ceilSizeYminus;//in pixels
	MenuButton numberOfMinesplus, numberOfMinesminus;
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	int getSettingInt(std::string l_settingName);
	std::string getSettingString(std::string l_settingName);
	void setSettingInt(std::string l_settingName, int value);
	void setSettingString(std::string l_settingName, std::string value);
	void loadSettings(const char* fileName);
	void saveSettings(const char* fileName);
	void reactToButtons();
	void sendMousePos(sf::Vector2i);
	void sendMousePress(sf::Vector2i);
	void sendMouseRelease(sf::Vector2i);
	bool isBack() { return m_backButton.checkClick(); }
	Settings();
	~Settings();
};