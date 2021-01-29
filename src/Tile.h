#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Tile
{
public:
	Tile(std::string label, sf::Vector2f position);
	Tile(sf::Vector2f position);
	void updateRegularTile(sf::Vector2f position);
	void updateResultTile(sf::Vector2f position, std::string resultLine);
public:
	std::string getValue() const;
	sf::RectangleShape & getRect();
	int getWidth() const;
	int getHeight() const;
	sf::Text & getText();
private:
	void initializeRegularTile(sf::Vector2f position);
	void initializeResultTile(sf::Vector2f position);
private:
	std::string value;
	sf::RectangleShape rect;
	int width, height;
	sf::Text text;
	sf::Font font;
};

