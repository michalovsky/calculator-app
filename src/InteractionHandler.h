#pragma once

#include "TilesLayout.h"

namespace calculator
{
class InteractionHandler
{
public:
    void handleMouseOverOnTilesLayout(TilesLayout& tilesLayout, sf::Vector2f mousePosition);
    std::optional<IntersectedTileInformation> getClickedTileInformation(TilesLayout& tilesLayout,
                                                                        sf::Vector2f mousePosition);
};

}
