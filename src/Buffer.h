#pragma once
#include <vector>
#include <string>
#include <iostream>

//Buffer keeps input in strings, example: words[0]="7.3" words[1]="+" words[2]="2"

class Buffer
{
public:
	Buffer() = delete;
	static std::string getCurrentWord();
	static void setCurrentWordResult(bool);
	static bool isCurrentWordResult();
	static void addToNewWord(std::string);
	static void addToExistingWord(std::string);
	static void clearCurrentWord();
	static void clearWords();
	static void removeLastWord();
	static std::string getWordsAsLine();
	static std::vector<std::string> getWords();
private:
	static std::vector<std::string> words;
	static std::string wordsAsLine;
	static int currentWordIndex;
	static bool currentWordResult;
};

