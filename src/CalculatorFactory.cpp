#include "CalculatorFactory.h"

namespace calculator
{

std::unique_ptr<Calculator> CalculatorFactory::createCalculator()
{
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(300, 480), "Calculator");
    auto buffer = std::make_shared<calculator::Buffer>();
    return std::make_unique<Calculator>(window, std::make_unique<TilesLayout>(),
                                        std::make_unique<calculator::UserInputReader>(window), buffer,
                                        std::make_unique<calculator::InteractionHandler>(),
                                        std::make_unique<calculator::IntersectedTileInformationInterpreter>(
                                            buffer, std::make_unique<OperationSolver>()));
}
}