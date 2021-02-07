#include "OperationSolver.h"

#include <algorithm>
#include <utility>

namespace calculator
{
namespace
{
struct Token
{
    Token& operator=(const std::string& newValue)
    {
        value = newValue;
        return *this;
    }

    std::string value;
    bool toRemove{false};
};

std::vector<Token> createTokensFromLines(const std::vector<std::string>& tokensLines);
void handleTokens(std::vector<Token>& tokens, const std::function<double(double, double)>&,
                  const std::string& operatorSign);
void handleMultiplicationTokens(std::vector<Token>& tokens);
void handleDivisionTokens(std::vector<Token>& tokens);
void handlePlusTokens(std::vector<Token>& tokens);
void handleMinusTokens(std::vector<Token>& tokens);
std::string getResultFromTokens(std::vector<Token>& tokens);
std::string roundNumber(const std::string& numberToRound);
bool tokensContainGivenToken(std::vector<Token>& tokens, const std::string& givenToken);

const auto plusSign = "+";
const auto minusSign = "-";
const auto multiplicationSign = "x";
const auto divisionSign = "/";
const auto dotSign = ".";
}

std::string OperationSolver::solve(const std::vector<std::string>& tokensLines)
{
    auto tokens = createTokensFromLines(tokensLines);

    handleMultiplicationTokens(tokens);
    handleDivisionTokens(tokens);
    handlePlusTokens(tokens);
    handleMinusTokens(tokens);

    return getResultFromTokens(tokens);
}

namespace
{
std::vector<Token> createTokensFromLines(const std::vector<std::string>& tokensLines)
{
    std::vector<Token> tokens;
    tokens.reserve(tokensLines.size());
    for (const auto& word : tokensLines)
    {
        tokens.push_back({word, false});
    }
    return tokens;
}

void handleTokens(std::vector<Token>& tokens, const std::function<double(double, double)>& operation,
                  const std::string& operatorSign)
{
    while (tokensContainGivenToken(tokens, operatorSign))
    {
        int tokenIndex = 0;
        for (auto& token : tokens)
        {
            if (token.value == operatorSign)
            {
                tokens[tokenIndex - 1].toRemove = true;
                tokens[tokenIndex + 1].toRemove = true;
                auto value1 = std::stod(tokens[tokenIndex - 1].value);
                auto value2 = std::stod(tokens[tokenIndex + 1].value);
                token = std::to_string(operation(value1, value2));
                break;
            }
            tokenIndex++;
        }

        tokens.erase(
            std::remove_if(tokens.begin(), tokens.end(), [](const Token& token) { return token.toRemove; }),
            tokens.end());
    }
}

void handleMultiplicationTokens(std::vector<Token>& tokens)
{
    handleTokens(tokens, std::multiplies<>(), multiplicationSign);
}

void handleDivisionTokens(std::vector<Token>& tokens)
{
    handleTokens(tokens, std::divides<>(), divisionSign);
}

void handlePlusTokens(std::vector<Token>& tokens)
{
    handleTokens(tokens, std::plus<>(), plusSign);
}

void handleMinusTokens(std::vector<Token>& tokens)
{
    handleTokens(tokens, std::minus<>(), minusSign);
}

std::string getResultFromTokens(std::vector<Token>& tokens)
{
    int resultIndex = 0;
    for (int tokenIndex = 0; tokenIndex < tokens.size(); tokenIndex++)
    {
        if (not tokens[tokenIndex].value.empty())
        {
            resultIndex = tokenIndex;
        }
    }

    return roundNumber(tokens[resultIndex].value);
}

std::string roundNumber(const std::string& numberToRound)
{
    std::size_t foundDot = numberToRound.find(dotSign);
    std::string roundedNumber = numberToRound;

    if (foundDot != std::string::npos)
    {
        roundedNumber = roundedNumber.substr(0, foundDot + 3);
    }

    return roundedNumber;
}

bool tokensContainGivenToken(std::vector<Token>& tokens, const std::string& givenToken)
{
    return std::any_of(tokens.begin(), tokens.end(),
                       [&](const Token& token) { return token.value == givenToken; });
}
}
}
