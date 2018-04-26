#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
using namespace std;

class game_of_life
{
public:
	game_of_life();
	game_of_life(sf::RenderWindow* window);
	bool get_alive();
	void set_alive(bool is_alive);
	void get_neighbour(game_of_life cells[50][50], int i, int j);
	void draw(int i, int j);
	void apply_alive();
private:
	sf::RenderWindow* window;
	bool is_alive = 0;
	bool temp_alive = 0;

};

