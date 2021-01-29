#pragma once
#include "Tile.h"
#include "Constants.h"
#include <memory>

class Tiles
{
public:
	Tiles();
	void initialize();
	void update(std::string resultLine);
	std::vector<std::unique_ptr<Tile>> & getTiles();
private:
	void initializePositions();
	std::vector<std::unique_ptr<Tile>> tiles;
	std::vector<sf::Vector2f> tilesPositions;
	const int amountOfTiles = 18;
};

