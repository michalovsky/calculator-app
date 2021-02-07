#include "CalculatorFactory.h"

int main()
{
    auto calculator = calculator::CalculatorFactory::createCalculator();
    calculator->run();

    return 0;
}