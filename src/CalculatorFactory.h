#pragma once

#include "Calculator.h"

namespace calculator
{
class CalculatorFactory
{
public:
    static std::unique_ptr<Calculator> createCalculator();
};
}