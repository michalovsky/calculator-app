#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>

class Input
{
public:
	Input() = delete;
	static int read(sf::RenderWindow & window);
	static sf::Vector2f readMousePosition(sf::RenderWindow & window);
};

