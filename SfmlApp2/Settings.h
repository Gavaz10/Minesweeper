#pragma once
class Settings
{
private:
	std::map<std::string, int> m_settingsMapInt;
	std::map<std::string, std::string> m_settingsMapString;
	std::set<std::string> m_setOfAvailableSettings;

	void addDefaultSettingString(std::string l_settingName, std::string defaultValue);
	void addDefaultSettingInt(std::string l_settingName, int defaultValue);
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

