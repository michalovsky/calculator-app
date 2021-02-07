#include "InteractionHandler.h"


namespace calculator
{
void InteractionHandler::handleMouseOverOnTilesLayout(TilesLayout& tilesLayout, sf::Vector2f mousePosition)
{
    tilesLayout.changeTilesColor(sf::Color::White);

    const auto mouseOverColor = sf::Color(189, 189, 189, 255);
    tilesLayout.changeTilesColorOnIntersection(mouseOverColor, mousePosition);
}

std::optional<IntersectedTileInformation> InteractionHandler::getClickedTileInformation(TilesLayout& tilesLayout, sf::Vector2f mousePosition)
{
    return tilesLayout.getInformationAboutTileBeingIntersected(mousePosition);
}



}
