#include "stdafx.h"
#include "Settings.h"


int Settings::getSettingInt(std::string l_settingName)
{
	if (m_settingsMapInt.count(l_settingName) == 0)
		return 0;
	return m_settingsMapInt[l_settingName];
}

std::string Settings::getSettingString(std::string l_settingName)
{
	if (m_settingsMapInt.count(l_settingName) == 0)
		return "";
	return m_settingsMapString[l_settingName];
}

void Settings::setSettingInt(std::string l_settingName, int value)
{
	m_settingsMapInt[l_settingName] = value;
}

void Settings::setSettingString(std::string l_settingName, std::string value)
{
	m_settingsMapString[l_settingName] = value;
}

void Settings::loadSettings(const char * fileName)
{

}

void Settings::saveSettings(const char * fileName)
{

}

Settings::Settings()
{
	m_settingsMapInt["field_size_x"] = 10;
	m_settingsMapInt["field_size_y"] = 10;
	m_settingsMapInt["field_ceil_size_x"] = 10;
	m_settingsMapInt["field_ceil_size_y"] = 10;
	m_settingsMapInt["number_of_mines"] = 15;
}


Settings::~Settings()
{

}
