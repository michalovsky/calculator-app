#pragma once

#include <vector>
#include <string>
#include <iostream>

//Buffer keeps input in strings, example: words[0]="7.3" words[1]="+" words[2]="2"

namespace calculator
{
class Buffer
{
public:
    Buffer();

    std::string getCurrentWord();
    void setCurrentWordAsResult(bool currentWordIsResult);
    bool isCurrentWordResult();
    void addToNewWord(const std::string&);
    void addToExistingWord(const std::string&);
    void clearCurrentWord();
    void clearWords();
    void removeLastWord();
    std::string getWordsAsLine();
    std::vector<std::string> getWords();

private:
    std::vector<std::string> words;
    std::string wordsAsLine;
    int currentWordIndex;
    bool currentWordResult;
};

}
