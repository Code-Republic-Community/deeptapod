#ifndef WORDSPLITTER_H
#define WORDSPLITTER_H

#include <vector>
#include <string>

class WordSlitter
{
public:
    WordSlitter(std::string& str) : sentence{str} {}
    std::vector<std::string> wordSplitter();
private:
    void is_abbrev(std::string &word, int &size, int &flag);
    std::string sentence;
};

#endif //WORDSPLITTER_H
