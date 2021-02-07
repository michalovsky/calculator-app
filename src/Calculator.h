#pragma once

#include "Buffer.h"
#include "InteractionHandler.h"
#include "IntersectedTileInformationInterpreter.h"
#include "TilesLayout.h"
#include "UserInputReader.h"

namespace calculator
{
class Calculator
{
public:
    Calculator(std::shared_ptr<sf::RenderWindow>, std::unique_ptr<TilesLayout>,
               std::unique_ptr<UserInputReader>, std::shared_ptr<Buffer>, std::unique_ptr<InteractionHandler>,
               std::unique_ptr<IntersectedTileInformationInterpreter>);

    void run();

private:
    void clearWindow();
    void update();
    void closeWindow();
    void drawWindow();

    std::shared_ptr<sf::RenderWindow> window;
    std::unique_ptr<TilesLayout> tiles;
    std::unique_ptr<UserInputReader> userInputReader;
    std::shared_ptr<Buffer> buffer;
    std::unique_ptr<InteractionHandler> interactionHandler;
    std::unique_ptr<IntersectedTileInformationInterpreter> tileInformationInterpreter;
};
}
