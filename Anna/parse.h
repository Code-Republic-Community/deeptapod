#ifndef PARSE_H
#define PARSE_H

#include <vector>
#include <string>
#include <unordered_map>

class Parse
{
public:
    Parse(std::string& searchingWord, std::string& text);
    std::string getEntity() const;

public:
    //function "geters" belongs Diana
    static bool isCity(std::string&);
    static bool isCountry(std::string&);
    static bool isVillage(std::string&);
    static bool isStreet(std::string&);
    static bool isOcean(std::string&);
    static bool isSea(std::string&);
    static bool isLake(std::string&);
    static bool isWaterfall(std::string&);
    static bool isRiver(std::string&);
    static bool isPeninsula(std::string&);
    static bool isPerson(std::string&);
    static bool isAnimal(std::string&);
    static bool isBrid(std::string&);
    static bool isCur(std::string&);
    static bool isSubject(std::string&);

private:
    void fillTheMap();
    void fillTheEntity();
    void textAnalysis();
   // int helpIsEqualString(std::string& s1, std::string& s2);
private:
    // link function to function name
    static std::unordered_map<bool(*)(std::string&), std::string> _fullFunc;
    std::vector<std::string> _nameEntities;

private:
    std::string _word;
    std::string _text;
    std::string _entity;
};

#endif //PARSE_H
