#include "OperationSolver.h"


std::string OperationSolver::solve(std::vector<std::string> words)
{
	std::vector<Word> localWords;

	for (auto & word : words)
	{
		localWords.emplace_back(word);
	}

	while (checkIfStringExists(localWords, "x") || checkIfStringExists(localWords, "/"))
	{
		int wordIndex = 0;
		for (auto & word : localWords)
		{
			if (word.value == "x")
			{
				localWords[wordIndex - 1].toRemove = true;
				localWords[wordIndex + 1].toRemove = true;
				word = std::to_string(std::stod(localWords[wordIndex - 1].value) * std::stod(localWords[wordIndex + 1].value));
				break;
			}
			else if (word.value == "/")
			{
				localWords[wordIndex - 1].toRemove = true;
				localWords[wordIndex + 1].toRemove = true;
				word = std::to_string(std::stod(localWords[wordIndex - 1].value) / std::stod(localWords[wordIndex + 1].value));
				break;
			}
			wordIndex++;
		}

		localWords.erase(std::remove_if(localWords.begin(), localWords.end(), [](const Word & word) {return word.isToRemove(); }), localWords.end());
	}

	while (checkIfStringExists(localWords, "+") || checkIfStringExists(localWords, "-"))
	{
		int wordIndex = 0;
		for (auto & word : localWords)
		{
			if (word.value == "+")
			{
				localWords[wordIndex - 1].toRemove = true;
				localWords[wordIndex + 1].toRemove = true;
				word = std::to_string(std::stod(localWords[wordIndex - 1].value) + std::stod(localWords[wordIndex + 1].value));
				break;
			}
			else if (word.value == "-")
			{
				localWords[wordIndex - 1].toRemove = true;
				localWords[wordIndex + 1].toRemove = true;
				word = std::to_string(std::stod(localWords[wordIndex - 1].value) - std::stod(localWords[wordIndex + 1].value));
				break;
			}
			wordIndex++;
		}

		localWords.erase(std::remove_if(localWords.begin(), localWords.end(), [](const Word & word) {return word.isToRemove(); }), localWords.end());
	}

	int resultIndex = 0, wordIndex = 0;
	for (auto & word : localWords)
	{
		if (word.value != "")
		{
			resultIndex = wordIndex;
		}
		wordIndex++;
	}

	 std::string resultNumber = roundNumber(localWords[resultIndex].value);
	 return resultNumber;
}

bool OperationSolver::checkIfStringExists(std::vector<Word> & words, std::string str)
{
	for (auto & word : words)
	{
		if (word.value == str)
		{
			return true;
		}
	}
	return false;
}

std::string OperationSolver::roundNumber(std::string numberToRound)
{
	std::size_t foundDot = numberToRound.find(".");

	std::string roundedNumber = numberToRound;

	if (foundDot != std::string::npos)
	{
		roundedNumber = roundedNumber.substr(0, foundDot + 3);
	}

	return roundedNumber;
}


