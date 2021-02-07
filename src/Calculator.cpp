#include "Calculator.h"

namespace calculator
{

Calculator::Calculator(std::shared_ptr<sf::RenderWindow> renderWindowInit,
                       std::unique_ptr<TilesLayout> layoutInit,
                       std::unique_ptr<UserInputReader> inputReaderInit, std::shared_ptr<Buffer> bufferInit,
                       std::unique_ptr<InteractionHandler> interactionHandlerInit,
                       std::unique_ptr<IntersectedTileInformationInterpreter> interpreterInit)
    : window{std::move(renderWindowInit)},
      tiles{std::move(layoutInit)},
      userInputReader{std::move(inputReaderInit)},
      buffer{std::move(bufferInit)},
      interactionHandler{std::move(interactionHandlerInit)},
      tileInformationInterpreter{std::move(interpreterInit)}
{
    window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - window->getSize().x / 2,
                                     sf::VideoMode::getDesktopMode().height / 2 - window->getSize().y / 2));
    window->setFramerateLimit(60);
}

void Calculator::run()
{
    while (window->isOpen())
    {
        clearWindow();
        update();
        drawWindow();
    }
}

void Calculator::update()
{
    const auto inputKey = userInputReader->readInputKey();

    interactionHandler->handleMouseOverOnTilesLayout(*tiles, userInputReader->readMousePosition());

    if (inputKey == calculator::InputKey::MouseLeft)
    {
        if (const auto clickedTileInfo =
                interactionHandler->getClickedTileInformation(*tiles, userInputReader->readMousePosition()))
        {
            tileInformationInterpreter->interpretTileInformation(*clickedTileInfo);
        }
    }
    else if (inputKey == calculator::InputKey::Escape)
    {
        closeWindow();
    }

    tiles->updateResult(buffer->getWordsAsLine());
}

void Calculator::clearWindow()
{
    window->clear(sf::Color::White);
}

void Calculator::closeWindow()
{
    window->close();
}

void Calculator::drawWindow()
{
    tiles->draw(*window);
    window->display();
}

}
