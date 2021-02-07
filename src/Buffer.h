#pragma once

#include <string>
#include <vector>

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
    std::vector<std::string>::size_type currentWordIndex;
    bool currentWordResult;
};

}
