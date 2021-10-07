#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> text_to_vector(std::string&);
bool is_word(std::string&);
std::string normalizer(std::string);

int main(){
	std::string str;
	std::cout<<"enter text"<<std::endl;
	getline(std::cin, str);

	std::vector<std::string> words = text_to_vector(str);  //txt is our vector with words of text

	std::cout << '\n' << "your text splitted into words and here they are:" << std::endl;

	for(int i=0; i < words.size(); ++i){
		std::cout<<words[i]<<' ';
	}

	std::cout << '\n'<< '\n' << "normalized words are:" << std::endl;

	for(int i=0; i < words.size(); ++i){
	
		std::cout << normalizer(words[i]) << std::endl;
	
	}

return 0;
}
