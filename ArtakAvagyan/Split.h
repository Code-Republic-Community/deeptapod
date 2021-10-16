#ifndef SPLIT_H_
#define SPLIT_H_
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

class Split
{
public:
	Split(const std::string&);

public:
	void setString(const std::string&);
	std::string getString()const;

	std::vector<std::string> getSentens () const;
	std::vector<std::string> getParagraphs () const;

	std::vector<std::string> splitToSentences ();
	std::vector<std::string> splitToParagraphs ();



private:
	bool isParagraphs(std::string);
	std::string m_str;
	std::vector<std::string>m_paragraph;
	std::vector<std::string>m_sentens;
};

#endif //   SPLIT_H_ 
