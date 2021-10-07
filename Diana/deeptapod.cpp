#include <iostream>
#include <string>
#include <vector>

class Word
{
    public:
    void setWord(const std::string& word) { this->word = word;}
   // void setNumber(const std::string& number) { this->number = number;}
   // void setTense(const std::string& tense) { this->tense = tense;}
    void setGenus(const std::string& genus) { this->genus = genus;}
    void setTranscription(const std::string& transcription) {this->transcription = transcription;}
    
    public:
    void addHomophone(const std::string& homophone) { homophones.push_back(homophone); }
    void addMeaning(const std::string& meaning) { meanings.push_back(meaning); }
    void addPartOfWord(const std::string& part) { partOfWord.push_back(part); }
    void addSynonym(const std::string& synonym) { synonyms.push_back(synonym); }
    void addAntonym(const std::string& antonym) { antonyms.push_back(antonym); }
    void addInflectedForm(const std::string& inflectedForm) { inflectedForms.push_back(inflectedForm); }
    void addNarrowerTerm(const std::string& narrowerTerm) { narrowerTerms.push_back(narrowerTerm); }
    void addBroaderTerm(const std::string& broaderTerm) { broaderTerms.push_back(broaderTerm); }
    void addLexicallyCloseWord(const std::string& closeWord) { lexicallyCloseWords.push_back(closeWord); }
    void addAnagram(const std::string& anagram) { anagrams.push_back(anagram); }
    void addInternetDomain(const std::string& internetDomain) { internetDomains.push_back(internetDomain); }
    void addEntity(const std::string& entity) { entities.push_back(entity); }
    void addPhrase(const std::string& phrase) { phrases.push_back(phrase); }
    void addPreposition(const std::string& preposition) { prepositions.push_back(preposition); }
    void addHyphenition(const std::string& hyphenition) { hyphenitions.push_back(hyphenition); }
    void addPuzzle(const std::string& puzzle) { puzzles.push_back(puzzle); }
    
    public:
    std::string getWord() { return word;}
   // std::string getNumber() { return number;}
   // std::string getTense() { return tense;}
    std::string getGenus() { return genus;}
    std::string getTranscription() { return transcription;}
    
    public:
    std::vector<std::string> getHomophones() { return homophones; }
    std::vector<std::string> getMeaning() { return meanings; }
    std::vector<std::string> getPartOfWord() { return partOfWord; }
    std::vector<std::string> getSynonyms() { return synonyms; }
    std::vector<std::string> getAntonyms() { return antonyms; }
    std::vector<std::string> getInflectedForms() { return inflectedForms; }
    std::vector<std::string> getNarrowerTerms() { return narrowerTerms; }
    std::vector<std::string> getBroaderTerms() { return broaderTerms;}
    std::vector<std::string> getLexicallyCloseWords() { return lexicallyCloseWords; }
    std::vector<std::string> getAnagrams() { return anagrams; }
    std::vector<std::string> getInternetDomains() { return internetDomains; }
    std::vector<std::string> getEntities() { return entities; }
    std::vector<std::string> getPhrases() { return phrases; }
    std::vector<std::string> getPrepositions() { return prepositions; }
    std::vector<std::string> getHyphenitions() { return hyphenitions; }
    std::vector<std::string> getPuzzles() { return puzzles; }
    
    public:
    Word(){};
    friend std::ostream& operator<<(std::ostream &out, const Word& word);
    
    private:
    std::string word;
   // std::string number;                          
   // std::string tense;
    std::string genus;                       //male/female
    std::string transcription;               //pronunciation         
 
    private:
    std::vector<std::string> homophones;     //same pronunciations different forms
    std::vector<std::string> meanings;       //definitions    
    std::vector<std::string> partOfWord;     //noun/verb/adjective and etc.           
    std::vector<std::string> synonyms;      
    std::vector<std::string> antonyms;
    std::vector<std::string> inflectedForms;  //plural forms of nouns/  the past tense, past participle, present participle forms of verbs/ comporative, superlative forms of adjective          
    std::vector<std::string> narrowerTerms;   //an authorized, preferred heading that is narrower in definition and scope.
    std::vector<std::string> broaderTerms;    //an autorized, preferred heading that is broader in definition and scope.
    std::vector<std::string> lexicallyCloseWords;
    std::vector<std::string> anagrams;        //combinations of word's characters that make sense
    std::vector<std::string> internetDomains;
    std::vector<std::string> entities;        //human,animal or item
    std::vector<std::string> phrases;
    std::vector<std::string> prepositions;    //on, in, for, under and etc.
    std::vector<std::string> hyphenitions;    //syllables
    std::vector<std::string> puzzles;         //all combinations of word's characters
    
};

/*Word::Word()
{
    word = "";
   // number = "";                      
   // tense = "";
    genus = "";
    transcription = "";                            
}*/

std::ostream& operator<<(std::ostream &out, const Word& term)
{
    out << term.word << ": " << std::endl;
  //  out << "number : " << term.number << std::endl;
  //  out << "tense : " << term.tense << std::endl;
    out << "genus : " << term.genus << std::endl;
    out << "transcription : " << term.transcription << std::endl;
    
    out << "homophones : ";
    for(int i = 0; i < term.homophones.size(); ++i) { out << term.homophones[i] << " "; }
    out << std::endl;

    out << "meanings : ";
    for(int i = 0; i < term.meanings.size(); ++i) { out << term.meanings[i] << " "; }
    out << std::endl;

    out << "part of word : ";
    for(int i = 0; i < term.partOfWord.size(); ++i) { out << term.partOfWord[i] << " "; }
    out << std::endl;

    out << "synonyms : ";
    for(int i = 0; i < term.synonyms.size(); ++i) { out << term.synonyms[i] << " "; }
    out << std::endl;

    out << "antonyms : ";
    for(int i = 0; i < term.antonyms.size(); ++i) { out << term.antonyms[i] << " "; }
    out << std::endl;

    out << "inflected forms : ";
    for(int i = 0; i < term.inflectedForms.size(); ++i) { out << term.inflectedForms[i] << " "; }
    out << std::endl;

    out << "narrower terms : ";
    for(int i = 0; i < term.narrowerTerms.size(); ++i) { out << term.narrowerTerms[i] << " "; }
    out << std::endl;

    out << "broader terms : ";
    for(int i = 0; i < term.broaderTerms.size(); ++i) { out << term.broaderTerms[i] << " "; }
    out << std::endl;

    out << "lexically close word : ";
    for(int i = 0; i < term.lexicallyCloseWords.size(); ++i) { out << term.lexicallyCloseWords[i] << " "; }
    out << std::endl;
    
    out << "anagrams : ";
    for(int i = 0; i < term.anagrams.size(); ++i) { out << term.anagrams[i] << " "; }
    out << std::endl;
    
    out << "internet domains : ";
    for(int i = 0; i < term.internetDomains.size(); ++i) { out << term.internetDomains[i] << " "; }
    out << std::endl;
    
    out << "entities : ";
    for(int i = 0; i < term.entities.size(); ++i) { out << term.entities[i] << " "; }
    out << std::endl;
    
    out << "phrases : ";
    for(int i = 0; i < term.phrases.size(); ++i) { out << term.phrases[i] << " "; }
    out << std::endl;
    
    out << "prepositions : ";
    for(int i = 0; i < term.prepositions.size(); ++i) { out << term.prepositions[i] << " "; }
    out << std::endl;
    
    out << "hyphenitions : ";
    for(int i = 0; i < term.hyphenitions.size(); ++i) { out << term.hyphenitions[i] << " "; }
    out << std::endl;
    
    out << "puzzles : ";
    for(int i = 0; i < term.puzzles.size(); ++i) { out << term.puzzles[i] << " "; }
    out << std::endl;
    
    return out;
}


int main()
{
    Word word;
    word.setWord("developers");
//    word.setNumber("plural");
    word.setTranscription("[div'elhuperz]");
    word.addMeaning("The coolest guys");
    word.addPartOfWord("noun");
    word.addPuzzle("velodepers");
    word.addPuzzle("eldeperovs");
    word.addNarrowerTerm("short-stop");
    word.addBroaderTerm("creator");
    word.addLexicallyCloseWord("development");
    word.addEntity("human");
    std::cout << word << std::endl;

    return 0;
}
