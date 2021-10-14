#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
#include "deeptapod.h"
#include "Test.h"
#include "WordSplitter.h"

namespace Test
{
    //####################################### Devide Senteces ############################################
    void Test_divideIntoSentenses::prepareDataSet(std::string in, std::string out) {

        m_text.clear();
        /* std::string str;
           std::ifstream input(in);
           while (!input.eof()) {
             m_text.push_back(input.get());
           }
        */
        std::string str;
        std::ifstream input(in);
        while(std::getline(input, str)) {
            m_text += str;
        }
        std::fstream output(out);
        while(std::getline(output, str)) {
            if(str != " ") {
                m_sentence.push_back(str);
            }
        }
    }

    void Test_divideIntoSentenses::test_divideIntoSentenses()
    {
        char c{};
        for(int i = 1; i <= 7; ++i) {
            c = i + 48;
            std::string input = std::string("S_c") + c + std::string("_input.txt");
            std::string output = std::string("S_c") + c + std::string("_output.txt");
            Test::Test_divideIntoSentenses::prepareDataSet(input, output);

            Deeptapod test(m_text);
            auto result = test.Divide_into_sentenses();
            bool equal = (m_sentence == result);
            std::cout << "Test " << i << ":" << std::endl;
            if(equal) {
                std::cout << "Test passed" << std::endl;
            } else {
                std::cout << "test failed" << std::endl;
                std::cout << "Output::" << std::endl;
                for (int j = 0; j < result.size(); j++) {
                    std::cout<<result[j] << std::endl;
                }
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Expected Output::" << std::endl;
                for (int k = 0; k < m_sentence.size(); k++) {
                    std::cout << m_sentence[k] << std::endl;
                }
            }
            std::cout << std::endl;
            m_sentence.clear();
        }
    }

    //####################################### Devide Paragraf ############################################
    void Test_divideIntoParagraphs::prepareDataSet(std::string in, std::string out)
    {
        std::ifstream input(in);
        std::string str{};
        m_text.clear();
        while(std::getline(input, str)) {
            if(str == "/") {
                m_text += "\n";
            } else {
                m_text += str;
                m_text += " ";
            }
        }
        std::string new_str;
        std::fstream output(out);
        while(std::getline(output, str)) {
            if(str == "/") {
                m_paragraph.push_back(new_str);
                new_str = "";
            } else if(str == "@") {
                new_str += "\n";
            } else {
                new_str += str;
            }
        }
    }

    void Test_divideIntoParagraphs::test_divideIntoParagraphs()
    {
        char c{};
        for(int i = 1; i <= 7; ++i) {
            c = i + 48;
            std::string input = std::string("P_c") + c + std::string("_input.txt");
            std::string output = std::string("P_c") + c + std::string("_output.txt");
            Test::Test_divideIntoParagraphs::prepareDataSet(input,output);
            Deeptapod test(m_text);
            std::cout << "#####################################" << m_text << "##############################" << std::endl;
            auto result = test.Divide_into_paragraphs();
            bool equal = (m_paragraph == result);
            std::cout << "Test " << i << ":" << std::endl;
            if(equal) {
                std::cout<<"Test passed"<<std::endl;
            } else {
                std::cout<<"test failed"<<std::endl;
                std::cout<<"Output::"<<std::endl;
                for(int j = 0; j < result.size(); j++) {
                    std::cout << result[j] << std::endl;
                }
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Expected Output::" << std::endl;
                for(int k = 0; k < m_paragraph.size(); k++) {
                    std::cout << m_paragraph[k] << std::endl;
                }
            }
            std::cout << std::endl;
            m_paragraph.clear();
        }
    }

    //####################################### Devide Word ############################################
    void  Test_divideIntoWords::prepareDataSet(std::string in, std::string out)
    {
        std::ifstream input(in);
        std::getline(input, m_sentence);
        std::fstream output(out);
        std::string str;
        while (std::getline(output, str)) {
            m_word.push_back(str);
        }
    }

    void Test_divideIntoWords::test_divideIntoWords()
    {
        for(int i = 1; i <= 9; ++i){
            char c = i + 48;
            std::string input = std::string("W_c") + c  +  std::string("_input.txt");
            std::string output = std::string("W_c") + c  +  std::string("_output.txt");
            Test::Test_divideIntoWords::prepareDataSet(input,output);
            std::cout << "#####################" << m_sentence << "#####################\n";
            WordSlitter test(m_sentence);
            auto result = test.wordSplitter();
            bool equal = (m_word == result);
            std::cout<< "Test " << i << ":" << std::endl;
            if(equal) {
                std::cout << "Test passed" << std::endl;
            } else {
                std::cout << "test failed" << std::endl;
                std::cout << "Output::" << std::endl;
                for (int j = 0; j < result.size(); j++){
                    std::cout << result[j] << std::endl;
                }
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Expected Output::" << std::endl;
                for (int k = 0; k < m_word.size(); k++) {
                    std::cout << m_word[k] << std::endl;
                }
            }
            std::cout << std::endl;
            m_word.clear();
        }
    }
};
