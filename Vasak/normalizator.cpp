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
    
	if(text[i]>='A' && text[i]<='Z'   ||   text[i]>='a' && text[i]<='z'){
            strWord += text[i];
        }
        //if the symbol is number '0' but his right or left sides are letters, then we can consider that there must be the letter 'o' in spite of '0'
        else if((i!=0)&&(i<text.size())&&(text[i]=='0') && ((text[i-1]>='A'&&text[i-1]<='Z'  ||  text[i-1]>='a'&&text[i-1]<='z') || (text[i+1]>='A'&&text[i+1]<='Z'  ||  text[i+1]>='a'&&text[i+1]<='z'))){
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

	if(word == "am" || word == "is" || word == "are"){	//cases of "be" (I II III demqer)
		word = "be";
		return word;
	}

	if(word.size() <= 2){
		return word;
	}

	//if the word is in irregular form (written - write, drunk - drink), returns direct form
	auto it = irregularVerbs.find(word);
	if(it != irregularVerbs.end()){
		std::string normalized = it->second;
		return normalized;
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
				return word;
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

	//ending with -nt    (might have been -n't, xosqi` "didn't", "haven't")
	else if(word.substr(word.size()-2, word.size()) == "nt"){
		
		std::string normalized = word.substr(0, word.size()-2);   //cut the "-nt"

		if(is_word(normalized)){		//havent - have
			return normalized;
		}
		else if(is_word(normalized + 'n')){	//"can't" case
			normalized += 'n';
			return normalized;
		}
		
		return word;	//if failed to find the exact case anyways
	}

	//ending with -re ("you're" darcel a "youre")
	else if(word.substr(word.size()-2, word.size()-1) == "re"){
		
		std::string normalized = word.substr(0, word.size()-2);   //cut the "-re" ("youre" becomes "you")
		
		if(is_word(normalized)){	//returns "you"
			return normalized;
		}

		return word;	//if failed to find the exact case anyways
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
