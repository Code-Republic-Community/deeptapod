#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

namespace Test{

    class Test_divideIntoParagraphs
    {
    public:
        void test_divideIntoParagraphs();
    private:
        void prepareDataSet(std::string, std::string);
        std::string m_text;
        std::vector<std::string> m_paragraph;
    };

    class Test_divideIntoSentenses
    {
    public:
        void test_divideIntoSentenses();
    private:
        void prepareDataSet(std::string, std::string);
        std::string m_text;
        std::vector<std::string> m_sentence;
    };

    class Test_divideIntoWords
    {
    public:
        void test_divideIntoWords();
    private:
        void prepareDataSet(std::string, std::string);
        std::string m_sentence;
        std::vector<std::string> m_word;
    };
};
#endif // TEST_H
