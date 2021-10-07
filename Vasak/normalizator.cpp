#include <iostream>
#include <vector>
#include <string>
std::vector<std::string> wordsDB = {"you", "can", "have", "feed", "admire"}; //fake DB



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

std::string normalizer(std::string word){
	
	if(is_word(word)){		//if the word is in his direct form
		return word;
	}

	if(word.size()<=2){		//"as", "be", "or"
		return word;
	}

	//ending with -ing
	if(word.substr(word.size()-3, word.size()) == "ing"){
		
		if(word.size()>4 && word!="thing" && word!="sting" && word!="bring" &&word!="boing" && word!="cling" && word!="during" && word!="according"){
			
			std::string normalized = word.substr(0, word.size()-3);  //cut the "-ing"
			
			if(is_word(normalized)){		//the case when "-ing" cut is the word we need
				return normalized;
			}
			if(is_word(normalized+'e')){  		//the case when 'e' is dropped when added "-ing" (care - caring)
				normalized += 'e';
				return normalized;
			}
			if(is_word(normalized.substr(0, normalized.size()-2))){       //the case when the last letter is duplicated (hit - hitting)
				normalized = normalized.substr(0, normalized.size()-2);   //cut the last letter
				return normalized;
			}
			else{
				return normalized;
			}
		}
		else if(word.size()<=4){	//"ring", "sing", "king", 
			return word;
		}

		return word;	//if failed to find the exact case anyways
	}

	//ending with -es
	else if(word.substr(word.size()-2, word.size()) == "es"){

		std::string normalized = word.substr(0, word.size()-2);   //cut the "-es"
		
		if(is_word(normalized)){		//the case when "-es" cut is the word we need
			return normalized;
		}
		if(is_word(normalized + 'e')){		//the cases when 'e' is dropped (case - cases, admire - admires)
			normalized += 'e';
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
	
		if(is_word(word)){	//xosqi "bias", "alias", "adios", "access", "ass", "chess"
			return word;
		}

		std::string normalized = word.substr(0, word.size()-1);   //cut the "-s"

		if(is_word(normalized)){			//the case when "-s" cut is the word we need
			return normalized;
		}
		
		return word;	//if failed to find the exact case anyways
	}

	//ending with -ed
	else if(word.substr(word.size()-2, word.size()) == "ed"){
		
		if(is_word(word)){		//xosqi`  feed, weed, need
			return word;
		}

		if(word.size()<4 && word!="fed" && word!="led"){	//for example` red, bed, med, ped, ted, wed, ned
			return word;
		}
		else if(word=="fed"){		//simple past case (feed - fed)
			word = "feed";
			return word;
		}
		else if(word=="led"){		//simple past case (lead - led)
			word = "lead";
			return word;
		}

		std::string normalized = word.substr(0, word.size()-2);   //cut the "-ed"

		if(is_word(normalized)){			//when "-ed" cut is the word we need
			return normalized;
		}
		if(is_word(normalized + 'e')){		//the case when 'e' is dropped (admire - admired)
			normalized += 'e';
			return normalized;
		}

		if(is_word(normalized.substr(0, normalized.size()-1))){       //the case when the last letter is duplicated (wrap - wrapped)
			normalized = normalized.substr(0, normalized.size()-2);  //cut the last letter
			return normalized;
		}

		return word;	//if failed to find the exact case anyways
	}

	//ending with -nt    (might have been -n't, xosqi` "didn't", "haven't")
	else if(word.substr(word.size()-2, word.size()) == "nt"){
		
		if(is_word(word)){		//for example` "fluent", "eloquent", "amount", "amusement", "agent"
			return word;
		}
		else if(word=="bent"){		//simple past (bend - bent)
			word = "bend";
			return word;
		}
		else if(word=="burnt"){
			word = "burn";
			return word;
		}
		else if(word=="learnt"){
			word = "learn";
			return word;
		}
		else if(word=="meant"){
			word = "mean";
			return word;
		}

		else if(word=="sent"){
			word = "send";
			return word;
		}

		else if(word=="spent"){
			word = "spend";
			return word;
		}
		
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
		
		if(is_word(word)){	//xosqi "acquire", "where", "admire", "dare"
			return word;
		}

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
