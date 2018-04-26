#include <SFML/Graphics.hpp>
#include "game_of_life.h"	

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Game of Life");
	window.setFramerateLimit(60);
	game_of_life game(&window);

	bool image = 0;
	sf::Clock timer;
	sf::Clock timer2;
	game_of_life cells[50][50];
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			game_of_life temp_cell(&window);
			if (rand() % 100 < 25)
			{
				temp_cell.set_alive(true);
			}
			else
			{
				temp_cell.set_alive(false);
			}
			cells[i][j] = temp_cell;
		}
	}

	sf::Texture texture;
	if (!texture.loadFromFile("homer.bmp"))
	{
		cout << "Error" << endl;
		return 1;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(1.76f, 1.76f));

	int generation = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type==sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					image = 1;
					timer2.restart();
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (timer.getElapsedTime().asSeconds() >= 0.5f && image == 0)
		{
			system("cls");
			cout <<"Generation:	" << ++generation << endl;
			cout << endl;
			cout << "----------------------------" << endl;
			cout << "Press ESC for Homer Simpson " << endl;
			cout << "----------------------------" << endl;
			for (int i = 0; i < 50; i++)
			{
				for (int j = 0; j < 50; j++)
				{
					cells[i][j].get_neighbour(cells, i, j);
				}
			}

			for (int i = 0; i < 50; i++)
			{
				for (int j = 0; j < 50; j++)
				{
					cells[i][j].apply_alive();
				}
			}
			timer.restart();
		}

		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				cells[i][j].draw(i, j);
			}
		}	

		if (image == 1)
		{
			
			window.draw(sprite);
			if (timer2.getElapsedTime().asSeconds() > 5)
			{
				return 0;
			}
		}
		window.display();
	}

	return 0;
}