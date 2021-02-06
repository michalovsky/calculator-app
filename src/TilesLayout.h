#pragma once

#include "Tile.h"
#include <memory>
#include <array>

class Tiles
{
public:
	Tiles();

	void update(const std::string& resultLine);
    //TODO: remove getter
    const std::array<std::unique_ptr<calculator::Tile>, 19>& getTiles();
    void draw(sf::RenderWindow&);

    static const int resultTileIndex = 18;

private:
    static std::array<sf::Vector2f, 19>& createTilePositions();
    static std::array<std::unique_ptr<calculator::Tile>, 19>& createTiles();

    const std::array<sf::Vector2f, 19>& tilePositions;
    const std::array<std::unique_ptr<calculator::Tile>, 19>& tiles;
};

