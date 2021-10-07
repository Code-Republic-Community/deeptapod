#include <iostream>
#include "parse.h"

//recurring cod. change

Parse::Parse(std::string& searchingWord, std::string& text) : _word{searchingWord}, _text{text}
{
    fillTheMap();
    fillTheEntity();
    if (_nameEntities.size() == 1) {
        _entity = _nameEntities[0];
    } else if (_nameEntities.size() > 1) {
        //call func analize_text
        textAnalysis();
    } else {
        std::cout << "unknown word" << std::endl;
    }
}

std::string Parse::getEntity() const
{
    return _entity;
}

std::unordered_map<bool(*)(std::string&), std::string> Parse::_fullFunc;

void Parse::fillTheMap()
{
    _fullFunc[isCity] = "city";
    _fullFunc[isCountry] = "country";
    _fullFunc[isVillage] = "village";
    _fullFunc[isStreet] = "street";
    _fullFunc[isOcean] = "ocean";
    _fullFunc[isSea] = "sea";
    _fullFunc[isLake] = "lake";
    _fullFunc[isWaterfall] = "waterfall";
    _fullFunc[isRiver] = "river";
    _fullFunc[isPeninsula] = "peninsula";
    _fullFunc[isPerson] = "person";
    _fullFunc[isAnimal] = "animal";
    _fullFunc[isBrid] = "bird";
    _fullFunc[isCur] = "cur";
    _fullFunc[isSubject] = "subject";

}

void Parse::fillTheEntity()
{
    for (const auto& elem : _fullFunc) {
        if (elem.first(_word)) {
            _nameEntities.push_back(elem.second);
        }
    }
}
//es karcum em anpitana u kara aveli shat xangari qan te ogni
void Parse::textAnalysis()
{
    std::size_t firstEntity;
    std::size_t size = 0;
    for (int i = 0; i < _nameEntities.size();) {
        firstEntity = _text.find(_nameEntities[i]);
        if (firstEntity == std::string::npos) {
            _nameEntities.erase(_nameEntities.begin() + i);
        } else {
            ++i;
        }
    }
    if (_nameEntities.size() == 1) {
        _entity = _nameEntities[0];
    } else if (_nameEntities.size() > 1){
        std::cout << "There are many entities" << std::endl;
        _entity = _nameEntities[0];
    } else {
        std::cout << "unknown word" << std::endl;
    }
}


bool Parse::isCity(std::string& name)
{
    return false;
}

bool Parse::isCountry(std::string& name)
{
    return false;
}

bool Parse::isVillage(std::string& name)
{
    return false;
}

bool Parse::isStreet(std::string& name)
{
    return false;
}

bool Parse::isOcean(std::string& name)
{
    return false;
}

bool Parse::isSea(std::string& name)
{
    return false;
}

bool Parse::isLake(std::string& name)
{
    return false;
}

bool Parse::isWaterfall(std::string& name)
{
    return true;
}

bool Parse::isRiver(std::string& name)
{
    return false;
}

bool Parse::isPeninsula(std::string& name)
{
    return false;
}

bool Parse::isPerson(std::string& name)
{
    return true;
}

bool Parse::isAnimal(std::string& name)
{
    return false;
}

bool Parse::isBrid(std::string& name)
{
    return false;
}

bool Parse::isCur(std::string& name)
{
    return false;
}

bool Parse::isSubject(std::string& name)
{
    return false;
}

// helper
/*int Parse::helpIsEqualString(std::string& s1, std::string& s2)
{
    int countMatchingCharacters = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) {
            countMatchingCharacters++;
        } else if (s1[i] >= 'A' && s1[i] != 'Z') {
            if ((s1[i] + 32) == s2[i]) {
                countMatchingCharacters++;
            }
        } else if (s1[i] >= 'a' && s1[i] != 'z') {
            if ((s1[i] - 32) == s2[i]) {
                countMatchingCharacters++;
            }
        }
    }
    return countMatchingCharacters;
}*/
