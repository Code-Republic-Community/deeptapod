#include "entityRecognition.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

EntitySpecifier::EntitySpecifier(std::string& word, std::string& sentence, std::string& text)
    : m_word{word}, m_sentence{sentence}, m_text{text}
{
    //DianEntityFunction(m_word) -> m_nameEntities
     if (m_nameEntities.size() == 1) {
        m_entity = m_nameEntities.begin()->first;
    } else if (m_nameEntities.size() > 1) {
        textAnalysis();
    } else {
        std::cout << "unknown word" << std::endl;
    }
}

EntitySpecifier::~EntitySpecifier()
{}

std::string EntitySpecifier::getEntity()
{
    return m_entity;
}

void EntitySpecifier::textAnalysis()
{
    removeUnUseEntity();
    if (m_nameEntities.size() == 1) {
        m_entity = m_nameEntities.begin()->first;
    } else if (m_nameEntities.size() > 1) {
        fillTheMapValue();
        int maxEntityValue = -1;
        int countMaxEntityValue = 0;
        bool isRepetitiousMaxValue = true;
        for (const auto& [key, value] : m_nameEntities) {
            if (maxEntityValue < value) {
                if (!inCount) {
                    --countMaxEntityValue;
                    isRepetitiousMaxValue = true;
                }
                m_entity = key;
                maxEntityValue = value;
            } else if (maxEntityValue == value) {
                isRepetitiousMaxValue = false;
                ++countMaxEntityValue;
            }
        }
        if (countMaxEntityValue >= 1) {
            std::cout << "  There are many entities" << std::endl;
            m_entity = "";
            //call new function, logica
        }
    } else {
        std::cout << "unknown word" << std::endl;
    }
}

//maybe is wrong
void EntitySpecifier::removeUnUseEntity()
{
    std::size_t firstEntity;
    for(auto it = m_nameEntities.begin(); it != m_nameEntities.end(); ) {
        firstEntity = m_text.find(it->first);
        if (firstEntity == std::string::npos) {
            it = m_nameEntities.erase(it);
        } else {
            ++it;
        }
    }
}

void EntitySpecifier::fillTheMapValue()
{
    devideSenetenceWord();
    for (auto& [key, value] : m_nameEntities) {
        for (int i = 0; i < m_wordsInText.size(); ++i) {
            if (key == m_wordsInText[i]) {
                ++value;
            }
        }
    }
}

void EntitySpecifier::devideSenetenceWord()
{
    std::string tmp;
    for (int i = 0; i < m_text.size(); ++i) {
        if (m_text[i] == ' ' && tmp.size() > 0) {
            m_wordsInText.push_back(tmp);
            tmp.clear();
        } else {
            tmp += m_text[i];
        }
    }
    if (tmp.size() > 1) {
        m_wordsInText.push_back(tmp);
    }
}
