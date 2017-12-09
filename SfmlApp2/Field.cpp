#include "stdafx.h"

void Field::init(Settings& l_settings)
{
	m_numberOfCeilsX = l_settings.getSettingInt("field_ceil_count_x");
	m_numberOfCeilsY = l_settings.getSettingInt("field_ceil_count_y");
	m_ceilSizeX = l_settings.getSettingInt("field_ceil_size_x");
	m_ceilSizeY = l_settings.getSettingInt("field_ceil_size_y");
	m_numberOfMines = l_settings.getSettingInt("number_of_mines");

	gameOver = false;
	gameEnd = false;
	gameStarted = false;

	firstClick = true;

	m_ceils.resize(m_numberOfCeilsY, std::vector<FieldCeil>(m_numberOfCeilsX));
	for (int i = 0; i < m_ceils.size(); i++)
	{
		for (int j = 0; j < m_ceils[i].size(); j++)
		{
			m_ceils[i][j] = FieldCeil();
		}
	}


	m_rectangle.setSize({ m_ceilSizeX * m_numberOfCeilsX * 1.f, m_ceilSizeY * m_numberOfCeilsY * 1.f });
	m_rectangle.setFillColor(sf::Color::White);

	float sizeX = m_numberOfCeilsX * m_ceilSizeX, sizeY = m_numberOfCeilsY * m_ceilSizeY;
#ifdef SWEEPER_DEBUG == 1
	std::cout << sizeX << " " << sizeY << " " << gameOverText.getGlobalBounds().width << " " << gameOverText.getGlobalBounds().height << "\n";
#endif // SWEEPER_DEBUG == 1

	while (gameOverText.getGlobalBounds().width >= sizeX)
	{
		gameOverText.setCharacterSize(gameOverText.getCharacterSize() - 1);
	}

	while (gameOverText2.getGlobalBounds().width >= sizeX)
	{
		gameOverText2.setCharacterSize(gameOverText2.getCharacterSize() - 1);
	}

	while (gameOverText.getGlobalBounds().height >= sizeY)
	{
		gameOverText.setCharacterSize(gameOverText.getCharacterSize() - 1);
	}

	while (gameOverText2.getGlobalBounds().height >= sizeY)
	{
		gameOverText2.setCharacterSize(gameOverText2.getCharacterSize() - 1);
	}

	gameOverText.setPosition({ sizeX / 2 - gameOverText.getGlobalBounds().width / 2, sizeY / 2 - gameOverText.getGlobalBounds().height  });
	gameOverText2.setPosition({ sizeX / 2 - gameOverText2.getGlobalBounds().width / 2, sizeY / 2 + gameOverText2.getGlobalBounds().height / 2 });

	gameOverText.setFillColor(sf::Color::Red);
	gameOverText2.setFillColor(sf::Color::Red);

	for (int i = 0; i < m_numberOfCeilsY; i++)
	{
		for (int j = 0; j < m_numberOfCeilsX; j++)
		{
			m_ceils[i][j].setPosition(j * m_ceilSizeX * 1.f, i * m_ceilSizeY * 1.f);
			m_ceils[i][j].setState(CLOSED);
			m_ceils[i][j].setSize(m_ceilSizeX, m_ceilSizeY);
			m_ceils[i][j].updateSprites();
		}
	}
}

void Field::anyButton()
{
	if (!gameOver)
		return;
	gameEnd = true;
}

void Field::setUpWindow(sf::RenderWindow& window)
{
	window.create(sf::VideoMode(this->m_numberOfCeilsX * this->m_ceilSizeX, this->m_numberOfCeilsY * this->m_ceilSizeY), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
}

void Field::openCeil(int x, int y)
{
	if (gameOver)//bcz game ended
		return;

	if (!checkCeilPosition(x, y))
		return;
	m_ceils[y][x].openCeil();

	if (m_ceils[y][x].isMine())//end game if mine
		gameOver = true;
}

int Field::calcNumberOfMinesAround(int x, int y)
{
	int cnt = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i < 0 || j < 0 || i >= m_numberOfCeilsX || j >= m_numberOfCeilsY)
				continue;
			if (m_ceils[j][i].isMine())
				cnt++;
		}
	}
	return cnt;
}

void Field::startGame(Settings& l_settings)
{
	init(l_settings);
}

void Field::endGame()
{

}

void Field::setUpField(Settings& l_settings, sf::RenderWindow& window)
{
	startGame(l_settings);
	setUpWindow(window);
}

void Field::generateMines(int l_numberOfMines, sf::Vector2i l_firstClick)
{
	if (l_numberOfMines >= m_numberOfCeilsX * m_numberOfCeilsY)
		throw new std::exception("so many mines");
	int cnt = l_numberOfMines;
	while (cnt != 0)
	{
		sf::Vector2i nextMine = { rand() % m_numberOfCeilsX, rand() % m_numberOfCeilsY };
		if (nextMine == l_firstClick)
			continue;
		if (m_ceils[nextMine.y][nextMine.x].isMine())
			continue;
		m_ceils[nextMine.y][nextMine.x].setHiddenMine();
		cnt--;
	}
	for (int i = 0; i < m_numberOfCeilsY; i++)
	{
		for (int j = 0; j < m_numberOfCeilsX; j++)
		{
			m_ceils[i][j].setNumberOfMinesAround(calcNumberOfMinesAround(j, i));
		}
	}
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);
	for (int x = 0; x < m_numberOfCeilsX; x++)
	{
		for (int y = 0; y < m_numberOfCeilsY; y++)
		{
			target.draw(m_ceils[y][x], states);
		}
	}
	if (gameOver)
	{
		target.draw(gameOverText, states);
		target.draw(gameOverText2, states);
	}
}

void Field::setSize(int x, int y)
{
	m_numberOfCeilsX = x;
	m_numberOfCeilsY = y;
}

void Field::setSize(sf::Vector2i size)
{
	setSize(size.x, size.y);
}

bool Field::checkMousePosition(int x, int y)
{
	return !(x < 0 || y < 0 || x >= m_numberOfCeilsX * m_ceilSizeX || y >= m_numberOfCeilsY * m_ceilSizeY);
}

bool Field::checkMousePosition(sf::Vector2i pos)
{
	return checkMousePosition(pos.x, pos.y);
}

bool Field::checkCeilPosition(int x, int y)
{
	return !(x < 0 || y < 0 || x >= m_numberOfCeilsX || y >= m_numberOfCeilsY);
}

bool Field::checkCeilPosition(sf::Vector2i pos)
{
	return checkCeilPosition(pos.x, pos.y);
}

sf::Vector2i Field::getCeilPos(sf::Vector2i pos)
{
	return sf::Vector2i(pos.x / m_ceilSizeX, pos.y / m_ceilSizeY);
}

void Field::clickMouse(sf::Vector2i pos)
{
	sf::Vector2i ceilPos = getCeilPos(pos);
	if (!checkCeilPosition(ceilPos))
		return;
	clickedPos = ceilPos;
}

void Field::releaseMouse(sf::Vector2i pos)
{
	sf::Vector2i ceilPos = getCeilPos(pos);
	if (!checkCeilPosition(ceilPos))
		return;
	if (clickedPos != ceilPos)
		return;
	if (firstClick)
	{
		generateMines(m_numberOfMines, ceilPos);
		firstClick = false;
	}
	openCeil(ceilPos.x, ceilPos.y);
}

void Field::sendMousePos(sf::Vector2i pos)
{
	sf::Vector2i ceilPos = getCeilPos(pos);
	if (clickedPos != ceilPos)
		clickedPos = { -1, -1 };
	if (lastPontedCeil == ceilPos)
		return;
	if (checkCeilPosition(lastPontedCeil))
		m_ceils[lastPontedCeil.y][lastPontedCeil.x].unpointToCeil();
	lastPontedCeil = ceilPos;
	if (checkCeilPosition(lastPontedCeil))
		m_ceils[lastPontedCeil.y][lastPontedCeil.x].pointToCeil();
}

Field::Field()
{
	
}


Field::~Field()
{
}
