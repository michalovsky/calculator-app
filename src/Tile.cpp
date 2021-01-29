#include "Tile.h"


Tile::Tile(std::string label, sf::Vector2f position) :value(label)
{
	initializeRegularTile(position);
}

Tile::Tile(sf::Vector2f position)
{
	initializeResultTile(position);
}

void Tile::updateRegularTile(sf::Vector2f position)
{
	rect.setPosition(position);
	text.setPosition(sf::Vector2f(rect.getPosition().x + 28, rect.getPosition().y + 5));
}

void Tile::updateResultTile(sf::Vector2f position, std::string resultLine)
{
	text.setString(resultLine);
	rect.setPosition(position);
	text.setPosition(sf::Vector2f(rect.getPosition().x + 5, rect.getPosition().y ));
}

std::string Tile::getValue() const
{
	return value;
}

sf::RectangleShape & Tile::getRect()
{
	return rect;
}

sf::Text & Tile::getText()
{
	return text;
}

void Tile::initializeRegularTile(sf::Vector2f position)
{
	rect.setSize(sf::Vector2f(70.f, 60.f));
	width = 70;
	height = 60;
	rect.setFillColor(sf::Color::White);
	rect.setOutlineThickness(1);
	rect.setOutlineColor(sf::Color::Black);
	rect.setPosition(position);

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cerr << "error\n";
	}

	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setString(value);
	text.setPosition(sf::Vector2f(rect.getPosition().x + 28, rect.getPosition().y + 5));
}

void Tile::initializeResultTile(sf::Vector2f position)
{
	rect.setSize(sf::Vector2f(294.f, 60.f));
	width = 294;
	height = 60;
	rect.setFillColor(sf::Color::White);
	rect.setOutlineThickness(3);
	rect.setOutlineColor(sf::Color::Black);
	rect.setPosition(position);

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cerr << "error\n";
	}

	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Black);
	text.setString("0");
	text.setPosition(sf::Vector2f(rect.getPosition().x + 5, rect.getPosition().y));
}

int Tile::getWidth() const
{
	return width;
}

int Tile::getHeight() const
{
	return height;
}


