#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Word 
{
public: 
	Word(std::string str) :value(str){}
	std::string value;
	bool toRemove{ false };
	bool isToRemove() const { return toRemove; }

};

class OperationSolver
{
public:
	OperationSolver() = delete;
	static std::string solve(std::vector<std::string> words);
private:
	static bool checkIfStringExists(std::vector<Word> & words,std::string strToCheck);
	static std::string roundNumber(std::string);
};

