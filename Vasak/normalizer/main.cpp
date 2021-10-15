#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> split_text_into_words(const std::string&);
bool is_word(const std::string&);
std::string normalize(const std::string&);

int main(){
	std::string str;
	std::cout<<"enter text"<<std::endl;
	getline(std::cin, str);

	std::vector<std::string> words = split_text_into_words(str);  //txt is our vector with words of text

	std::cout << '\n' << "your text splitted into words and here they are:" << std::endl;

	for(int i=0; i < words.size(); ++i){
		std::cout<<words[i]<<' ';
	}

	std::cout << '\n'<< '\n' << "normalized words are:" << std::endl;

	for(int i=0; i < words.size(); ++i){
	
		std::cout << normalize(words[i]) << std::endl;
	
	}

return 0;
}
