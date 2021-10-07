#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void is_abbrev(std::string&, int&, int&);

std::vector<std::string> wordSplitter(std::string sentence) {

	std::vector<std::string> words;
	std::string word = "";
	int size{0}; //size of the current word

	 for(int i = 0; i <= sentence.size(); ++i) {

	 if((sentence[i] == ' ') || (sentence[i] == '\0') || (sentence[i] == '/')) { //separators of words

		if((word[0] == '"') || (word[0] == '(') ||
                   (word[0] == '[') || (word[0] == '{')) {

                	word.erase(0,1);
                        size--;
                 } //erases one of these \" ( { [ symbols from the beggining of the word  

	int flag = 0; // indicates wheather the word is an abbreviation or not. If not, we can delete the last occurring symbols 
        
	while(((word[size-1] == '?') || (word[size-1] == '!')  || 
	       (word[size-1] == '.') || (word[size-1] == ',')  || 
	       (word[size-1] == ':') || (word[size-1] == ';')  || 
	       (word[size-1] == ')') || (word[size-1] == '}')  ||
	       (word[size-1] == ']') || (word[size-1] =='\"')) && 
	       (flag == 0)) {
                       
		 if(word[size-1] == '.') {  //looking for an abbeviation

			is_abbrev(word, size, flag); 

	          } else if((word[size-1] == ':') || (word[size-1] == ',')) {

                    	 if(((word[size-2] >= '0') && (word[size-2] <= '9')) && 
			     (word[size+1] >= '0') && (word[size+1] <= '9')) {
			     	continue;
                         } else {
				word.erase(size-1);
				size--;
		  	  }
                    }
		 	else { // if current character is any of these ? ! \" } ] , ) . (is to be deleted)
		   		word.erase(size-1);
        		 	size--;
                        }
	}//end of while loop

                        words.push_back(word); //word is ready to be added to the vector
                        word = "";
                        size = 0;
                }
                 else { //haven't encountered a separator yet
                        word += sentence[i];
                        size++;
                 }
	}
	return words;
}

/* is_abbrev function determines if the word ending with dot(.) is an abbreviation. 
 * If so, it does no changes, otherwise it deletes the last accurence of a dot.
 */

void is_abbrev(std::string &word, int &size, int &flag){
	std::ifstream inFile;
        inFile.open("abbreviations.txt");

        if(!inFile.is_open()) {
        	std::cout << "Unable to open the file!\n";
        } else {
          	std::string abbrev;
                while((std::getline(inFile, abbrev)) && (flag == 0)){ //reads abbreviations line by line
              		if(abbrev == word) {
                  		flag = 1;
                	 }
               }
                if(flag == 0){
                	word.erase(size-1);
                        size--;
                }
           }//end of else
          
       	inFile.close();
}	

/* int main(){

        std::vector<std::string> testCase;
        testCase = wordSplitter("\"See you tomorrow at 5 p.m.,\" said Ann.");
        for(int i = 0; i < testCase.size(); ++i){
                std::cout << testCase[i] << '\n';
        }
        return 0;
}
*/
