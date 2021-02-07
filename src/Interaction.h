#pragma once

#include "Buffer.h"
#include "OperationSolver.h"
#include "TilesLayout.h"

namespace calculator
{
class Interaction
{
public:
    void handleMouseOverOnTilesLayout(TilesLayout& tilesLayout, sf::Vector2f mousePosition);
    void handleMouseClickOnTilesLayout(TilesLayout& tilesLayout, sf::Vector2f mousePosition);

private:
    bool layoutCharacterIsNumber(LayoutCharacter);
    bool layoutCharacterIsOperationSign(LayoutCharacter);
    bool layoutCharacterIsResultSign(LayoutCharacter);
    bool layoutCharacterIsDot(LayoutCharacter);
    bool layoutCharacterIsClear(LayoutCharacter);
    bool layoutCharacterIsRemove(LayoutCharacter);
    void handleNumbers(const std::string& value);
    void handleSigns(const std::string& value);
    void handleResult();
    void handleDot(const std::string& value);
    void handleClear();
    void handleRemove();
};

}
