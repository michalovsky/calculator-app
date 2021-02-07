#pragma once

#include <string>
#include <vector>

namespace calculator
{
class OperationSolver
{
public:
    std::string solve(const std::vector<std::string>& tokensLines);
};
}
