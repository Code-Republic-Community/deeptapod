#include "databases.h"

#include <iostream>
#include <vector>
#include <string>

bool is_apostrophe(const char& symbol) {
	if(symbol == 39){
		return true;
	}
	return false;
}

bool is_letter(const char& symbol) {
	if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
		return true;
	}
	return false;
}

bool is_number(const char& symbol) {
	if (symbol >= '0' && symbol <= '9') {
		return true;
	}
	return false;
}

bool is_end_of_word(const char& symbol) {
	if (symbol == '\0' || symbol == ' ' || symbol == 9 || symbol == 11) {
		return true;
	}
	return false;
}

bool is_too_short(const std::string& term) {
	return (term.size() <= 2) ? true : false;
}

bool is_long_enough(const std::string& term) {
	return (term.size() >= 5) ? true : false;
}


//a function to split sentence into words
std::vector<std::string> split_text_into_words(const std::string& text){
    
    std::vector<std::string> tokens;         //the vector to be returned
    
    std::string strWord;
    std::string strNum;
        
    for (int i = 0; i <= text.size(); ++i) {
	    if (i > 0 && i < text.size()-1 && (is_apostrophe(text[i]) && is_letter(text[i-1]) && is_letter(text[i+1]))) {
		    strWord += text[i];
	    } else if (is_letter(text[i])) {
		    strWord += text[i];
	    } else if (i > 0 && i < text.size() && text[i] == '0' && is_letter(text[i-1]) && is_letter(text[i+1])) {
	    	    strWord += 'o';
	    } else if (is_number(text[i])) {
		    strNum += text[i];
	    } else if (is_end_of_word(text[i])) {
		    if (strWord.size()>0) {
		    	tokens.push_back(strWord);
			strWord.clear();
		    }
		    if (strNum.size()>0) {
		    	tokens.push_back(strNum);
			strNum.clear();
		    }
	    }	
    }
    return tokens;
}


//a function that returns true if the argument word is meaningful, false otherwise
bool is_word(const std::string& term) {
	for (int i = 0; i < wordsDB.size(); ++i) {
		if (term == wordsDB[i]) {
			return true;
		}
	}
	return false;
}


//normalizer function
std::string normalize(const std::string& term) {
	
	if (is_word(term)) {		//if the word is in his direct form
		return term;
	}

	//searches a lemma if the term is a pronoun
	auto itPr = pronounsDB.find(term);
	if (itPr != pronounsDB.end()) {
		return itPr->second;
	}

	//if the word is in irregular form (written - write, drunk - drink), returns direct form
	auto itIrr = irregularVerbsDB.find(term);
	if (itIrr != irregularVerbsDB.end()) {
		return itIrr->second;
	}

	if (is_too_short(term)) {
		return term;
	}

	//ending with -ing
	if (term.substr(term.size()-3, 3) == "ing") {
		if (is_long_enough(term)) {
			
			std::string normalized = term.substr(0, term.size()-3);  //cut the "-ing"
			
			if (is_word(normalized+'e')) {  		//the case when 'e' is dropped when added "-ing" (care - caring, ride - riding)
				normalized += 'e';
				return normalized;
			}
			if (is_word(normalized)) {		//if it's not the previous case, then it's not a problematic word like "car", "rid", etc.
				return normalized;
			}
			if (is_word(normalized.substr(0, normalized.size()-1))) {       //the case when the last letter is duplicated (hit - hitting)
				normalized = normalized.substr(0, normalized.size()-1);   //cut the last letter
				return normalized;
			}
		}
		return term;	//if failed to find the exact case anyways
	}

	//ending with -es
	if (term.substr(term.size()-2, 2) == "es") {

		std::string normalized = term.substr(0, term.size()-2);   //cut the "-es"
		
		if (is_word(normalized + 'e')) {		//the cases when 'e' is dropped (case - cases, admire - admires)
			normalized += 'e';
			return normalized;
		}
		if (is_word(normalized)) {		//if it's not the previous case then it's not "care" or "ride" or smth
			return normalized;
		}
		if (normalized[normalized.size()-1] == 'i') {		//the case when 'y' changes to 'i' (study - studies)
			normalized = normalized.substr(0, normalized.size()-2) + 'y';
			return normalized;
		}
		return term;	//if failed to find the exact case anyways
	}

	//ending with -s
	if (term[term.size()-1] == 's') {	
		
		if (term.substr(term.size()-2, 2) == "'s") {	//the belonging case ("cat's", "boy's")

			std::string normalized = term.substr(0, term.size()-2);	//cut the "-'s"
			return normalized;
		}

		std::string normalized = term.substr(0, term.size()-1);   //cut the "-s"

		if (is_word(normalized)) {		//the case when "-s" cut is the word we need
			return normalized;
		}	
		return term;	//if failed to find the exact case anyways
	}

	//ending with -ed
	if (term.substr(term.size()-2, 2) == "ed") {

		std::string normalized = term.substr(0, term.size()-2);   //cut the "-ed"

		if( is_word(normalized + 'e')) {		//the case when 'e' is dropped (admire - admired)
			normalized += 'e';
			return normalized;
		}
		if (is_word(normalized)) {		//if it's not the previous case (cared - care)
			return normalized;
		}

		if (is_word(normalized.substr(0, normalized.size()-1))) {       //the case when the last letter is duplicated (wrap - wrapped)
			normalized = normalized.substr(0, normalized.size()-1);  //cut the last letter
			return normalized;
		}
		return term;	//if failed to find the exact case anyways
	}

	//ending with -n't    (might have been -n't, xosqi` "didn't", "haven't")
	if (term.substr(term.size()-3, 3) == "n't") {
		
		std::string normalized = term.substr(0, term.size()-3);   //cut the "-n't"
	       	
		itIrr = irregularVerbsDB.find(normalized);	//xosqi` "didn't" must return "do", "couldn't" - "can"
		if (itIrr != irregularVerbsDB.end()) {
		       	return itIrr->second;
		}

		if (is_word(normalized)) {		//"haven't" - "have"
			return normalized;
		} else if (is_word(normalized + 'n')) {	//"can't" case
			normalized += 'n';
			return normalized;
		}
		return term;	//if failed to find the exact case anyways
	}

	//ending with -r'e ("you're")
	if (term.substr(term.size()-3, 3) == "'re") {
		
		std::string normalized = term.substr(0, term.size()-3);   //cut the "-'re"
		
		//searches a lemma if the cut word is a pronoun ("you're" - "you",   "we're" -"we")
		itPr = pronounsDB.find(normalized);
		if (itPr != pronounsDB.end()) {
			return itPr->second;
		}

		if (is_word(normalized)) {	//returns "you"
			return normalized;
		}
		return term;	//if failed to find the exact case anyways
	}

	//ending with -'ve ("could've", "would've", "i've")
	if (term.substr(term.size()-3, 3) == "'ve") {

		std::string normalized = term.substr(0, term.size()-3);   //cut the "-'re" ("you're" becomes "you", "they're" - "they")
		
		itPr = pronounsDB.find(normalized);	//xosqi` "they've", "i've"
		if (itPr != pronounsDB.end()) {
			return itPr->second;
		}

		itIrr = irregularVerbsDB.find(normalized);	//xosqi` "could've"
		if (itIrr != irregularVerbsDB.end()) {
		       	return itIrr->second;
		}
		return normalized;	//if couldn't find appropriate case
	}

	return term;	//the case when function couldn't normalize the input word
}

/*		.
		.
		.
		.
		.
		...to be continued...
*/
