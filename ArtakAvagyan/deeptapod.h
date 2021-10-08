#ifndef DEEPTAPOD_H
#define DEEPTAPOD_H
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

class Deeptapod
{
public:
	Deeptapod(const std::string );

public:
	void Set_String(const std::string );
	std::string Get_String()const;

	std::vector<std::string> Get_sentens()const;
	std::vector<std::string> Get_paragraf()const;

	std::vector<std::string> Divide_into_sentenses();
	std::vector<std::string> Divide_into_paragraphs();



private:
	bool is_a_paragraphs(std::string);
	std::string m_str;
	std::vector<std::string>m_paragraph;
	std::vector<std::string>m_sentens;
};

#endif // DEEPTAPOD_H
