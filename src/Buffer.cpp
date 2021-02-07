#include "Buffer.h"

namespace calculator
{
Buffer::Buffer() : words{"0"}, currentWordIndex{0}, currentWordResult{false} {}

std::string Buffer::getCurrentWord()
{
    if (currentWordIndex >= 0 && currentWordIndex < (int)words.size())
    {
        return words[currentWordIndex];
    }
    return std::string();
}

void Buffer::setCurrentWordAsResult(bool currentWordIsResult)
{
    currentWordResult = currentWordIsResult;
}

bool Buffer::isCurrentWordResult()
{
    return currentWordResult;
}

void Buffer::removeLastWord()
{
    if (currentWordIndex >= 0 && currentWordIndex < (int)words.size())
    {
        if ((int)words[currentWordIndex].size() == 1)
        {
            words[currentWordIndex] = "";
        }
        else
        {
            int wordSize = (int)words[currentWordIndex].size();
            words[currentWordIndex] = words[currentWordIndex].substr(0, wordSize - 1);
        }
    }
}

void Buffer::addToExistingWord(const std::string& character)
{
    if (currentWordIndex >= 0 && currentWordIndex < (int)words.size())
    {
        words[currentWordIndex] += character;
    }
}

void Buffer::clearCurrentWord()
{
    if (currentWordIndex >= 0 && currentWordIndex < (int)words.size())
    {
        words[currentWordIndex] = "";
    }
}

void Buffer::addToNewWord(const std::string& character)
{
    currentWordIndex++;

    words.push_back(character);
}

void Buffer::clearWords()
{
    words.clear();

    words.erase(words.begin(), words.end());
    currentWordIndex = 0;
    words.emplace_back("");

    wordsAsLine = "";
}

std::string Buffer::getWordsAsLine()
{
    wordsAsLine = "";
    for (auto& str : words)
    {
        wordsAsLine += str;
    }

    if (wordsAsLine.empty())
    {
        return "0";
    }

    return wordsAsLine;
}

std::vector<std::string> Buffer::getWords()
{
    return words;
}

}
