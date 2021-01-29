#include "Buffer.h"

std::vector<std::string> Buffer::words{ "0" };
int Buffer::currentWordIndex = 0;
std::string Buffer::wordsAsLine{ "" };
bool Buffer::currentWordResult{ false };

std::string Buffer::getCurrentWord()
{
	if (currentWordIndex >= 0 && currentWordIndex < (int)words.size())
	{
		return words[currentWordIndex];
	}
	return std::string();
}

void Buffer::setCurrentWordResult(bool inp)
{
	currentWordResult = inp;
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

void Buffer::addToExistingWord(std::string character)
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

void Buffer::addToNewWord(std::string character)
{
	currentWordIndex++;

	words.push_back(character);
}

void Buffer::clearWords()
{
	words.clear();

	words.erase(words.begin(), words.end());
	currentWordIndex = 0;
	words.push_back("");

	wordsAsLine = "";
}

std::string Buffer::getWordsAsLine()
{
	wordsAsLine = "";
	for (auto & str : words)
	{
		wordsAsLine += str;
	}

	if (wordsAsLine == "")
	{
		return "0";
	}

	return wordsAsLine;
}

std::vector<std::string> Buffer::getWords()
{
	return words;
}

