/*this is a file that contains a function that normalizes a given word. To implement that function I used 2 more functions: first one to split the sentence into words, and the second one to search for a word in the database to find a matching word.
In the main normalizer function I considered that the word may be a indirect form of pronoun, may be one of the irregular verbs, may end with -ing, -es, -s, -'s, -ed, -n't, -'re, -'ve. */

#include <iostream>
#include <vector>
#include <string>
#include "databases.h"


//a function to split sentence into words
std::vector<std::string> text_to_vector(std::string& text){
    
    std::vector<std::string> tokens;         //the vector to be returned
    
    std::string strWord;   //for collecting letters in this string to pushback into vector
    std::string strNum;    //for collecting numbers in this string to pushback into vector
    
    
    for(int i=0; i <= text.size(); ++i){

	    //if the symbol is -'- (apatarc)  and it has letters on the two sides of it
	    if(text[i]==39 && i>0 && i<text.size()-1 && ((text[i-1]>='A'&&text[i-1]<='Z' || text[i-1]>='a'&&text[i-1]<='z') && (text[i+1]>='A'&&text[i+1]<='Z' || text[i+1]>='a'&&text[i+1]<='z'))){
		    strWord += text[i];
	    }

	    //if the symbol is a letter
	    else if((text[i]>='A' && text[i]<='Z')  ||  (text[i]>='a' && text[i]<='z')) {
		    strWord += text[i];
	    }

	    //if the symbol is number '0' but his right or left sides are letters, then we can consider that there must be the letter 'o' in spite of '0'
	    else if((i!=0)&&(i<text.size())&&(text[i]=='0') && ((text[i-1]>='A'&&text[i-1]<='Z' || text[i-1]>='a'&&text[i-1]<='z') || (text[i+1]>='A'&&text[i+1]<='Z' || text[i+1]>='a'&&text[i+1]<='z'))){
                    strWord += 'o';
	    }
	    else if(text[i]>='0' && text[i]<='9'){
		    strNum += text[i];
	    }
	    
	    //if the symbol is "space" or "tab" or it's the last symbol
	    else if(text[i] == '\0' || text[i] == ' ' || text[i]==9 || text[i]==11){
		    if(strWord.size()>0){
			    tokens.push_back(strWord);
			    strWord.clear();
		    }
		    if(strNum.size()>0){
			    tokens.push_back(strNum);
			    strNum.clear();
		    }
	    }	
    }
    
    return tokens;
}

//_________________________________________________________________________________________________________________________________________________________________________________

//a function that returns true if the argument word is meaningful, false otherwise
bool is_word(std::string word){
	for(int i=0; i < wordsDB.size(); ++i){	//wordsDB   is a   vector<string>   where we have collected words as a database
		if(word == wordsDB[i]){
			return true;
		}
	}
	return false;
}

//_________________________________________________________________________________________________________________________________________________________________________________

//normalizer function
std::string normalizer(std::string word){
	
	if(is_word(word)){		//if the word is in his direct form
		return word;
	}

	//searches a lemma if the word is a pronoun
	auto it = pronounsDB.find(word);
	if(it != pronounsDB.end()){
		std::string normalized = it->second;
		return normalized;
	}

	//if the word is in irregular form (written - write, drunk - drink), returns direct form
	auto driven = irregularVerbsDB.find(word);
	if(driven != irregularVerbsDB.end()){
		std::string normalized = driven->second;
		return normalized;
	}

	if(word.size() <= 2){
		return word;
	}

	//ending with -ing
	if(word.substr(word.size()-3, 3) == "ing"){
		
		if(word.size()>4){
			
			std::string normalized = word.substr(0, word.size()-3);  //cut the "-ing"
			
			if(is_word(normalized+'e')){  		//the case when 'e' is dropped when added "-ing" (care - caring, ride - riding)
				normalized += 'e';
				return normalized;
			}
			if(is_word(normalized)){		//if it's not the previous case, then it's not a problematic word like "car", "rid", etc.
				return normalized;
			}
			if(is_word(normalized.substr(0, normalized.size()-1))){       //the case when the last letter is duplicated (hit - hitting)
				normalized = normalized.substr(0, normalized.size()-1);   //cut the last letter
				return normalized;
			}
		}

		return word;	//if failed to find the exact case anyways
	}

	//ending with -es
	else if(word.substr(word.size()-2, 2) == "es"){

		std::string normalized = word.substr(0, word.size()-2);   //cut the "-es"
		
		if(is_word(normalized + 'e')){		//the cases when 'e' is dropped (case - cases, admire - admires)
			normalized += 'e';
			return normalized;
		}
		if(is_word(normalized)){		//if it's not the previous case then it's not "care" or "ride" or smth
			return normalized;
		}
		if(normalized[normalized.size()-1] == 'i'){		//the case when 'y' changes to 'i' (study - studies)
			normalized = normalized.substr(0, normalized.size()-2) + 'y';
			return normalized;
		}
		
		return word;	//if failed to find the exact case anyways
	}

	//ending with -s
	else if(word[word.size()-1] == 's'){	
		
		if(word.substr(word.size()-2, 2) == "'s"){	//the belonging case ("cat's", "boy's")

			std::string normalized = word.substr(0, word.size()-2);	//cut the "-'s"

			if(is_word(normalized)){
				return normalized;
			}
		}

		std::string normalized = word.substr(0, word.size()-1);   //cut the "-s"

		if(is_word(normalized)){			//the case when "-s" cut is the word we need
			return normalized;
		}
		
		return word;	//if failed to find the exact case anyways
	}

	//ending with -ed
	else if(word.substr(word.size()-2, 2) == "ed"){

		std::string normalized = word.substr(0, word.size()-2);   //cut the "-ed"

		if(is_word(normalized + 'e')){		//the case when 'e' is dropped (admire - admired)
			normalized += 'e';
			return normalized;
		}
		if(is_word(normalized)){		//if it's not the previous case (cared - care)
			return normalized;
		}

		if(is_word(normalized.substr(0, normalized.size()-1))){       //the case when the last letter is duplicated (wrap - wrapped)
			normalized = normalized.substr(0, normalized.size()-1);  //cut the last letter
			return normalized;
		}

		return word;	//if failed to find the exact case anyways
	}

	//ending with -n't    (might have been -n't, xosqi` "didn't", "haven't")
	else if(word.substr(word.size()-3, 3) == "n't"){
		
		std::string normalized = word.substr(0, word.size()-3);   //cut the "-n't"
	       	
		driven = irregularVerbsDB.find(normalized);	//xosqi` "didn't" must return "do", "couldn't" - "can"
		if(driven != irregularVerbsDB.end()){
		       	normalized = driven->second;
			return normalized;
		}

		if(is_word(normalized)){		//havent - have
			return normalized;
		}
		else if(is_word(normalized + 'n')){	//"can't" case
			normalized += 'n';
			return normalized;
		}
		
		return word;	//if failed to find the exact case anyways
	}

	//ending with -r'e ("you're")
	else if(word.substr(word.size()-3, 3) == "'re"){
		
		std::string normalized = word.substr(0, word.size()-3);   //cut the "-'re" ("you're" becomes "you", "they're" - "they")
		
		//searches a lemma if the cut word is a pronoun ("you're" - "you",   "we're" -"we")
		it = pronounsDB.find(normalized);
		if(it != pronounsDB.end()){
			std::string foundPronoun = it->second;
			return foundPronoun;
		}


		if(is_word(normalized)){	//returns "you"
			return normalized;
		}

		return word;	//if failed to find the exact case anyways
	}

	//ending with -'ve ("could've", "would've", "i've")
	else if(word.substr(word.size()-3, 3) == "'ve"){

		std::string normalized = word.substr(0, word.size()-3);   //cut the "-'re" ("you're" becomes "you", "they're" - "they")
		
		it = pronounsDB.find(normalized);	//xosqi` "they've", "i've"
		if(it != pronounsDB.end()){
			normalized = it->second;
			return normalized;
		}

		driven = irregularVerbsDB.find(normalized);	//xosqi` "could've"
		if(driven != irregularVerbsDB.end()){
		       	normalized = driven->second;
			return normalized;
		}

		return normalized;	//if couldn't find appropriate case
	}
		
	return word;	//the case when function couldn't normalize the input word
}


/*		.
		.
		.
		.
		.
		...to be continued...
*/
