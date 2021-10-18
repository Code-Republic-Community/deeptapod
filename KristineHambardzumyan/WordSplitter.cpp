#include <iostream>
#include <vector>
#include <string>
#include <fstream>

bool IsAbbreviation(const std::string&);
void ErasePunctuationMarksFromTheBeginning(std::string&);
void ErasePunctuationMarksFromTheEnd(std::string&);

std::vector<std::string> SplitIntoWords(std::string sentence) {
	std::vector<std::string> split_words;
	std::string word;
	for (int i = 0; i <= sentence.size(); ++i) {
		if ((sentence[i] == ' ') || (sentence[i] == '\0') || (sentence[i] == '/')) { // separators of the word
			ErasePunctuationMarksFromTheBeginning(word);
			ErasePunctuationMarksFromTheEnd(word);
			if (word != "") {
				split_words.push_back(word);
				word = "";
			} else continue;
                } else word += sentence[i]; //havn't encountered a separator yet
	}
	return split_words;
}

void ErasePunctuationMarksFromTheBeginning(std::string& word) {
	int index{0};
	while ((word[index] == '"') || (word[index] == '(') ||
	       (word[index] == '[') || (word[index] == '{') ||
	       (word[index] == '\'')) {
		++index;
	}
	word.erase(0, index);
}

void ErasePunctuationMarksFromTheEnd(std::string& word) {
		bool word_is_abbreviation{false};
		int word_size = word.size();
		while (((word[word_size-1] == '?') || (word[word_size-1] == '!') ||
			(word[word_size-1] == '.') || (word[word_size-1] == ',') ||
			(word[word_size-1] == ':') || (word[word_size-1] == ';') ||
			(word[word_size-1] == ')') || (word[word_size-1] == '}') ||
			(word[word_size-1] == ']') || (word[word_size-1] =='\"') ||
		        (word[word_size-1] == '\'')) && (word_is_abbreviation == false)) { 

			if (word[word_size-1] == '.') {
				if (!(IsAbbreviation(word))) {
					word.erase(word_size-1);
				} else word_is_abbreviation == true;
			} else { 
                                word.erase(word_size-1);
			  }
			word_size--;
		}
}

bool IsAbbreviation(const std::string& word) {
	std::ifstream inFile("abbreviations.txt");
        if (!inFile.is_open()) { 
		std::cout << "Unable to open the file!\n";
       	} else {
		std::string abbreviation;
		while (std::getline(inFile, abbreviation)) {
                	if (word == abbreviation) {
				return true;
                         }
               }
           }
	inFile.close();
	return false;
}


/* int main() {

        std::vector<std::string> testCase;
        testCase = SplitIntoWords("\"See 11:12  you   'tomorrow' at 5 p.m.,\" said Ann.");
        for (int i = 0; i < testCase.size(); ++i) {
                std::cout << testCase[i] << '\n';
        }
        return 0;
}
*/
