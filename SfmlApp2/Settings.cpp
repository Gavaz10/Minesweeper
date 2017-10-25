#include "stdafx.h"
#include "Settings.h"


void Settings::addDefaultSettingString(std::string l_settingName, std::string defaultValue)
{
	m_setOfAvailableSettings.insert(l_settingName);
	m_settingsMapString[l_settingName] = defaultValue;
}

void Settings::addDefaultSettingInt(std::string l_settingName, int defaultValue)
{
	m_setOfAvailableSettings.insert(l_settingName);
	m_settingsMapInt[l_settingName] = defaultValue;
}

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
	if (!m_setOfAvailableSettings.count(l_settingName))
		return;
	m_settingsMapInt[l_settingName] = value;
}

void Settings::setSettingString(std::string l_settingName, std::string value)
{
	if (!m_setOfAvailableSettings.count(l_settingName))
		return;
	m_settingsMapString[l_settingName] = value;
}

void Settings::loadSettings(const char * fileName)
{
	std::ifstream inputStream(fileName);

	std::string settingName, value;

	while (inputStream >> settingName && inputStream >> value)
	{
		if (!m_setOfAvailableSettings.count(settingName))
			continue;
		if (isNumber(value))
		{
			m_settingsMapInt[settingName] = toInt(value);
		}
		else
		{
			m_settingsMapString[settingName] = value;
		}
	}

	inputStream.close();
}

void Settings::saveSettings(const char * fileName)
{
	std::ofstream outputStream(fileName);

	for (auto pair : m_settingsMapInt)
	{
		outputStream << pair.first << " " << pair.second << std::endl;
	}
	outputStream.close();
}

Settings::Settings()
{
	addDefaultSettingInt("field_ceil_count_x", 20);
	addDefaultSettingInt("field_ceil_count_y", 20);
	addDefaultSettingInt("field_ceil_size_x", 20);
	addDefaultSettingInt("field_ceil_size_y", 20);
	addDefaultSettingInt("number_of_mines", 15);
	addDefaultSettingInt("screen_size_x", 640);
	addDefaultSettingInt("screen_size_y", 480);
}


Settings::~Settings()
{

}
