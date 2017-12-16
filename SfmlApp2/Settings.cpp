#include "stdafx.h"
#include "Settings.h"

void Settings::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);

	target.draw(m_backButton, states);

	target.draw(fieldSizeXplus, states);
	target.draw(fieldSizeXminus, states);
	target.draw(fieldSizeYplus, states);
	target.draw(fieldSizeYminus, states);
	target.draw(ceilSizeXplus, states);
	target.draw(ceilSizeXminus, states);
	target.draw(ceilSizeYplus, states);
	target.draw(ceilSizeYminus, states);
	target.draw(numberOfMinesplus, states);
	target.draw(numberOfMinesminus, states);

	target.draw(fieldSizeX, states);
	target.draw(fieldSizeY, states);
	target.draw(ceilY, states);
	target.draw(ceilX, states);
	target.draw(numberOfMines, states);

	target.draw(fieldSizeXvalue, states);
	target.draw(fieldSizeYvalue, states);
	target.draw(ceilYvalue, states);
	target.draw(ceilXvalue, states);
	target.draw(numberOfMinesvalue, states);
}

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

void Settings::reactToButtons()
{
	if (fieldSizeXplus.checkClick())
	{
		setSettingInt("field_ceil_count_x", (getSettingInt("field_ceil_count_x") + 1));
	}
	if (fieldSizeYplus.checkClick())
	{
		setSettingInt("field_ceil_count_y", (getSettingInt("field_ceil_count_y") + 1));
	}
	if (ceilSizeXplus.checkClick())
	{
		setSettingInt("field_ceil_size_x", (getSettingInt("field_ceil_size_x") + 1));
	}
	if (ceilSizeYplus.checkClick())
	{
		setSettingInt("field_ceil_size_y", (getSettingInt("field_ceil_size_y") + 1));
	}
	if (numberOfMinesplus.checkClick())
	{
		setSettingInt("number_of_mines", (getSettingInt("number_of_mines") + 1));
	}

	if (fieldSizeXminus.checkClick() && getSettingInt("field_ceil_count_x"))
	{
		setSettingInt("field_ceil_count_x", (getSettingInt("field_ceil_count_x") - 1));
	}
	if (fieldSizeYminus.checkClick() && getSettingInt("field_ceil_count_y"))
	{
		setSettingInt("field_ceil_count_y", (getSettingInt("field_ceil_count_y") - 1));
	}
	if (ceilSizeXminus.checkClick() && getSettingInt("field_ceil_size_x"))
	{
		setSettingInt("field_ceil_size_x", (getSettingInt("field_ceil_size_x") - 1));
	}
	if (ceilSizeYminus.checkClick() && getSettingInt("field_ceil_size_y"))
	{
		setSettingInt("field_ceil_size_y", (getSettingInt("field_ceil_size_y") - 1));
	}
	if (numberOfMinesminus.checkClick())
	{
		setSettingInt("number_of_mines", (getSettingInt("number_of_mines") - 1));
	}

	fieldSizeXvalue.   setString(std::to_string(getSettingInt("field_ceil_count_x")));
	fieldSizeYvalue.   setString(std::to_string(getSettingInt("field_ceil_count_y")));
	ceilYvalue.        setString(std::to_string(getSettingInt("field_ceil_size_x")));
	ceilXvalue.        setString(std::to_string(getSettingInt("field_ceil_size_y")));
	numberOfMinesvalue.setString(std::to_string(getSettingInt("number_of_mines")));
}

int Settings::getSettingInt(std::string l_settingName)
{
	if (m_settingsMapInt.count(l_settingName) == 0)
		return -1;
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

void Settings::sendMousePos(sf::Vector2i pos)
{
	m_backButton.sendMousePos(pos);

	fieldSizeXplus.sendMousePos(pos);
	fieldSizeYplus.sendMousePos(pos);
	ceilSizeXplus. sendMousePos(pos);
	ceilSizeYplus. sendMousePos(pos);
	numberOfMinesplus.sendMousePos(pos);

	fieldSizeXminus.sendMousePos(pos);
	fieldSizeYminus.sendMousePos(pos);
	ceilSizeXminus. sendMousePos(pos);
	ceilSizeYminus. sendMousePos(pos);
	numberOfMinesminus.sendMousePos(pos);
}

void Settings::sendMousePress(sf::Vector2i pos)
{
	m_backButton.sendMousePress(pos);

	fieldSizeXplus.sendMousePress(pos);
	fieldSizeYplus.sendMousePress(pos);
	ceilSizeXplus. sendMousePress(pos);
	ceilSizeYplus. sendMousePress(pos);
	numberOfMinesplus.sendMousePress(pos);

	fieldSizeXminus.sendMousePress(pos);
	fieldSizeYminus.sendMousePress(pos);
	ceilSizeXminus. sendMousePress(pos);
	ceilSizeYminus. sendMousePress(pos);
	numberOfMinesminus.sendMousePress(pos);
}

void Settings::sendMouseRelease(sf::Vector2i pos)
{
	m_backButton.sendMouseRelease(pos);

	fieldSizeXplus.sendMouseRelease(pos);
	fieldSizeYplus.sendMouseRelease(pos);
	ceilSizeXplus. sendMouseRelease(pos);
	ceilSizeYplus. sendMouseRelease(pos);
	numberOfMinesplus.sendMouseRelease(pos);

	fieldSizeXminus.sendMouseRelease(pos);
	fieldSizeYminus.sendMouseRelease(pos);
	ceilSizeXminus. sendMouseRelease(pos);
	ceilSizeYminus. sendMouseRelease(pos);
	numberOfMinesminus.sendMouseRelease(pos);
}

Settings::Settings()
{
	screenSizeX = 640, screenSizeY = 480;

	addDefaultSettingInt("field_ceil_count_x", 20);
	addDefaultSettingInt("field_ceil_count_y", 20);
	addDefaultSettingInt("field_ceil_size_x", 20);
	addDefaultSettingInt("field_ceil_size_y", 20);
	addDefaultSettingInt("number_of_mines", 15);
	addDefaultSettingInt("screen_size_x", 640);
	addDefaultSettingInt("screen_size_y", 480);

	m_rectangle.setSize({ (float)screenSizeX, (float)screenSizeY });
	m_rectangle.setFillColor(sf::Color::White);

	int height = 40;
	m_backButton.setRect(0, screenSizeY - height, 200, height);

	int buttonSizeX = 30, buttonSizeY = 30;
	
	//setting color of all texts
	fieldSizeX.setFillColor(sf::Color::Black);
	fieldSizeY.setFillColor(sf::Color::Black);
	ceilY.     setFillColor(sf::Color::Black);
	ceilX.     setFillColor(sf::Color::Black);
	numberOfMines.setFillColor(sf::Color::Black);
	fieldSizeXvalue.setFillColor(sf::Color::Black);
	fieldSizeYvalue.setFillColor(sf::Color::Black);
	ceilYvalue.     setFillColor(sf::Color::Black);
	ceilXvalue.     setFillColor(sf::Color::Black);
	numberOfMinesvalue.setFillColor(sf::Color::Black);
	
	//setting origin of all texts to be centered
	fieldSizeX.setOrigin(fieldSizeX.getGlobalBounds().width / 2, fieldSizeX.getGlobalBounds().height / 2);
	fieldSizeY.setOrigin(fieldSizeY.getGlobalBounds().width / 2, fieldSizeY.getGlobalBounds().height / 2);
	ceilY.     setOrigin(ceilY.getGlobalBounds().     width / 2, ceilY.     getGlobalBounds().height / 2);
	ceilX.     setOrigin(ceilX.getGlobalBounds().     width / 2, ceilX.     getGlobalBounds().height / 2);
	numberOfMines.setOrigin(ceilX.getGlobalBounds().width / 2, ceilX.getGlobalBounds().height / 2);
	fieldSizeXvalue.setOrigin(0, fieldSizeX.getGlobalBounds().height / 2);
	fieldSizeYvalue.setOrigin(0, fieldSizeY.getGlobalBounds().height / 2);
	ceilYvalue.     setOrigin(0, ceilY.getGlobalBounds().height / 2);
	ceilXvalue.     setOrigin(0, ceilX.getGlobalBounds().height / 2);
	numberOfMinesvalue.setOrigin(0, numberOfMines.getGlobalBounds().height / 2);
	

	int widthOfText = fieldSizeY.getGlobalBounds().width / 2;
	int heightOfText = fieldSizeY.getGlobalBounds().height;

	//setting position of all texts to be centered
	fieldSizeX.setPosition(screenSizeX / 2, 100.f);
	fieldSizeY.setPosition(screenSizeX / 2, 160.f);
	ceilY.     setPosition(screenSizeX / 2, 220.f);
	ceilX.     setPosition(screenSizeX / 2, 280.f);
	numberOfMines.setPosition(screenSizeX / 2, 340.f);
	fieldSizeXvalue.setPosition(screenSizeX / 2 + widthOfText + 40.f + buttonSizeX * 3, 100.f);
	fieldSizeYvalue.setPosition(screenSizeX / 2 + widthOfText + 40.f + buttonSizeX * 3, 160.f);
	ceilYvalue.     setPosition(screenSizeX / 2 + widthOfText + 40.f + buttonSizeX * 3, 220.f);
	ceilXvalue.     setPosition(screenSizeX / 2 + widthOfText + 40.f + buttonSizeX * 3, 280.f);
	numberOfMinesvalue.setPosition(screenSizeX / 2 + widthOfText + 40.f + buttonSizeX * 3, 340.f);

	//settings pos and size of minus buttons
	fieldSizeXminus.setRect(screenSizeX / 2 + widthOfText + 10.f + buttonSizeX, 100.f - heightOfText, buttonSizeX, buttonSizeY);
	fieldSizeYminus.setRect(screenSizeX / 2 + widthOfText + 10.f + buttonSizeX, 160.f - heightOfText, buttonSizeX, buttonSizeY);
	ceilSizeXminus.setRect (screenSizeX / 2 + widthOfText + 10.f + buttonSizeX, 220.f - heightOfText, buttonSizeX, buttonSizeY);
	ceilSizeYminus.setRect (screenSizeX / 2 + widthOfText + 10.f + buttonSizeX, 280.f - heightOfText, buttonSizeX, buttonSizeY);
	numberOfMinesminus.setRect(screenSizeX / 2 + widthOfText + 10.f + buttonSizeX, 340.f - heightOfText, buttonSizeX, buttonSizeY);
	//...of plus buttons
	fieldSizeXplus.setRect (screenSizeX / 2 + widthOfText + 30.f + buttonSizeX * 2, 100.f - heightOfText, buttonSizeX, buttonSizeY);
	fieldSizeYplus.setRect (screenSizeX / 2 + widthOfText + 30.f + buttonSizeX * 2, 160.f - heightOfText, buttonSizeX, buttonSizeY);
	ceilSizeXplus.  setRect(screenSizeX / 2 + widthOfText + 30.f + buttonSizeX * 2, 220.f - heightOfText, buttonSizeX, buttonSizeY);
	ceilSizeYplus.  setRect(screenSizeX / 2 + widthOfText + 30.f + buttonSizeX * 2, 280.f - heightOfText, buttonSizeX, buttonSizeY);	
	numberOfMinesplus.setRect(screenSizeX / 2 + widthOfText + 30.f + buttonSizeX * 2, 340.f - heightOfText, buttonSizeX, buttonSizeY);
}



Settings::~Settings()
{

}
