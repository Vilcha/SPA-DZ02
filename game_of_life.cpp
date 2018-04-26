#include "game_of_life.h"

using namespace std;

game_of_life::game_of_life()
{
}

game_of_life::game_of_life(sf::RenderWindow * window)
{
	this->window = window;
}

bool game_of_life::get_alive()
{
	return is_alive;
}

void game_of_life::set_alive(bool is_alive)
{
	this->is_alive = is_alive;
}

void game_of_life::get_neighbour(game_of_life cells[50][50], int i, int j)
{
	int neighbours = 0;
	if (cells[i - 1][j - 1].get_alive() && i > 0 && j > 0)
	{
		neighbours++;
	}
	if (cells[i - 1][j].get_alive() && i > 0)
	{
		neighbours++;
	}
	if (cells[i - 1][j + 1].get_alive() && i > 0 && j < 49)
	{
		neighbours++;
	}
	if (cells[i][j - 1].get_alive() && j > 0)
	{
		neighbours++;
	}
	if (cells[i][j + 1].get_alive() && j < 49)
	{
		neighbours++;
	}
	if (cells[i + 1][j - 1].get_alive() && i < 49 && j > 0)
	{
		neighbours++;
	}
	if (cells[i + 1][j].get_alive() && i < 49)
	{
		neighbours++;
	}
	if (cells[i + 1][j + 1].get_alive() && i < 49 && j < 49)
	{
		neighbours++;
	}
	if ((neighbours < 2 || neighbours > 3) && is_alive);
	{
		temp_alive = 0;
	}
	if ((neighbours == 3 || neighbours == 2) && is_alive)
	{
		temp_alive = 1;
	}
	if ((neighbours == 3) && !is_alive)
	{
		temp_alive = 1;
	}
}

void game_of_life::draw(int i, int j)
{
	sf::RectangleShape sq(sf::Vector2f(16, 16));
	sq.setPosition(i * 18, j * 18);
	sq.setOutlineThickness(1);
	sq.setOutlineColor(sf::Color());
	if (is_alive)
	{
		sq.setFillColor(sf::Color(255, 0, 255));
	}
	else
	{
		sq.setFillColor(sf::Color(30, 30, 30));
	}
	window->draw(sq);
}

void game_of_life::apply_alive()
{
	is_alive = temp_alive;
}

	//survive if number of neighbours is 2 or 3
	//die if number of neighbours is less than 2 or more than 3
	//create new life form if there's exactly 3 neighbours around the cell


