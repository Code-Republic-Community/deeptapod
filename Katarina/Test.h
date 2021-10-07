#ifndef TEST_H
#define TEST_H
#include<iostream>
#include<vector>
#include <algorithm>

namespace Test{

    class Test_divideIntoParagraphs
    {
     public:
     void test_divideIntoParagraphs();
    
    private:
    void prepareDataSet(std::string,std::string);
    std::string text;
    std::vector<std::string> paragraph;
    std::vector<std::string> p1;
    std::vector<std::string> p2;

    }; 

    class Test_divideIntoSentenses
    {
     public:
     void test_divideIntoSentenses();
    
    private:
    void prepareDataSet(std::string,std::string);
    std::string text;
    std::vector<std::string> sentence;
    std::vector<std::string> c1;
    std::vector<std::string> c2;

  
    };

    
    class Test_divideIntoWords
    {
     public:
     void test_divideIntoWords();
    
    private:
    void prepareDataSet(std::string,std::string);
    std::string sentence;
    std::vector<std::string> word;
    std::vector<std::string> w1;
    std::vector<std::string> w2;

  
    };
}
#include"Test.hpp" 
#endif // TEST_H 