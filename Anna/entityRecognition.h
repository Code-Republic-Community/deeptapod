#ifndef ENTITYRECOGNITION_H
#define ENTITYRECOGNITION_H

#include <string>
#include <vector>
#include <map>

class EntitySpecifier
{
public:
    EntitySpecifier(std::string& word, std::string& sentence, std::string& text);
    ~EntitySpecifier();

public:
    void textAnalysis();                    //find possible entity
    std::string getEntity();                //return entity
    std::vector<std::string> m_wordsInText; //keeps the text word

private:
    //helper
    void devideSenetenceWord();
    void removeUnUseEntity();
    void fillTheMapValue();

private:
    std::string m_word;
    std::string m_text;
    std::string m_entity;
    std::string m_sentence;
    std::map<std::string, int> m_nameEntities = {{"person", 0}, {"waterfall", 0}, {"company", 0}, {"state", 0}};
};


#endif //ENTITYRECOGNITION_H
