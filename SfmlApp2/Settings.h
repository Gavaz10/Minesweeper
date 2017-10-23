#pragma once
class Settings
{
private:
	std::map<std::string, int> m_settingsMapInt;
	std::map<std::string, std::string> m_settingsMapString;
public:
	int getSettingInt(std::string l_settingName);
	std::string getSettingString(std::string l_settingName);
	void setSettingInt(std::string l_settingName, int value);
	void setSettingString(std::string l_settingName, std::string value);
	void loadSettings(const char* fileName);
	void saveSettings(const char* fileName);
	Settings();
	~Settings();
};

