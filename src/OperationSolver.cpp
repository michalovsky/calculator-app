#include "OperationSolver.h"

#include <algorithm>
#include <utility>

namespace calculator
{
namespace
{
struct Token
{
    std::string value;
    bool toRemove{false};
};

std::vector<Token> createTokensFromLines(const std::vector<std::string>& tokensLines);
void handleMultiplicationDivisionTokens(std::vector<Token>& tokens);
void handlePlusMinusTokens(std::vector<Token>& tokens);
void clearRedundantTokens(std::vector<Token>& tokens);
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

    handleMultiplicationDivisionTokens(tokens);
    handlePlusMinusTokens(tokens);

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

void handleToken(std::vector<Token>& tokens, std::vector<Token>::size_type tokenIndex,
                 const std::function<double(double, double)>& operation)
{
    tokens[tokenIndex - 1].toRemove = true;
    tokens[tokenIndex + 1].toRemove = true;
    const auto value1 = std::stod(tokens[tokenIndex - 1].value);
    const auto value2 = std::stod(tokens[tokenIndex + 1].value);
    tokens[tokenIndex].value = std::to_string(operation(value1, value2));
}

void handleMultiplicationDivisionTokens(std::vector<Token>& tokens)
{
    while (tokensContainGivenToken(tokens, multiplicationSign) ||
           tokensContainGivenToken(tokens, divisionSign))
    {
        for (size_t tokenIndex = 0; tokenIndex < tokens.size(); tokenIndex++)
        {
            const auto tokenValue = tokens[tokenIndex].value;
            if (tokenValue == multiplicationSign)
            {
                handleToken(tokens, tokenIndex, std::multiplies<>());
                break;
            }
            else if (tokenValue == divisionSign)
            {
                handleToken(tokens, tokenIndex, std::divides<>());
                break;
            }
        }

        clearRedundantTokens(tokens);
    }
}

void handlePlusMinusTokens(std::vector<Token>& tokens)
{
    while (tokensContainGivenToken(tokens, plusSign) || tokensContainGivenToken(tokens, minusSign))
    {
        for (size_t tokenIndex = 0; tokenIndex < tokens.size(); tokenIndex++)
        {
            const auto tokenValue = tokens[tokenIndex].value;
            if (tokenValue == plusSign)
            {
                handleToken(tokens, tokenIndex, std::plus<>());
                break;
            }
            else if (tokenValue == minusSign)
            {
                handleToken(tokens, tokenIndex, std::minus<>());
                break;
            }
        }

        clearRedundantTokens(tokens);
    }
}

void clearRedundantTokens(std::vector<Token>& tokens)
{
    tokens.erase(
        std::remove_if(tokens.begin(), tokens.end(), [](const Token& token) { return token.toRemove; }),
        tokens.end());
}

std::string getResultFromTokens(std::vector<Token>& tokens)
{
    int resultIndex = 0;
    for (size_t tokenIndex = 0; tokenIndex < tokens.size(); tokenIndex++)
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
    const auto foundDot = numberToRound.find(dotSign);
    auto roundedNumber = numberToRound;

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
