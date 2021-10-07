#include "deeptapod.h"



Deeptapod::Deeptapod(const std::string str)  // ctor
{
	m_str = str;
}


void Deeptapod::Set_String(const std::string str) //Set
{
	m_str = str;
}

std::string Deeptapod::Get_String()const  // Get
{
	return m_str;
}


std::vector<std::string> Deeptapod::Get_sentens()const
{
	return m_sentens;
}


std::vector<std::string> Deeptapod::Get_paragraf()const
{
	return m_paragraph;
}





std::vector<std::string> Deeptapod::Divide_into_sentenses()  // for Sentenses
{
	auto lf = [&](char it){return it == '.' || it == '?' || it == '!' || it == '"';};
	auto it = m_str.begin();
	auto it_begin = m_str.begin();
	std::string tmp;
	while(it <= m_str.end())
	{
		it = std::find_if(it_begin,m_str.end(),[&](char ch)
				{return ch == '.' || ch == '?' || ch == '!' || ch == '"';});
		while(*it == *(std::next(it))){
			++it;
		}
		if(*it == '"'){ it--;}
		std::copy(it_begin,++it,back_inserter(tmp));
		it_begin = it;
		m_sentens.push_back(tmp);
		tmp.clear();
		if(*(it) == '"')
		{
			it = std::find(std::next(it_begin), m_str.end(), '"');
			std::copy(it_begin,++it,back_inserter(tmp));
			it_begin = it;
			m_sentens.push_back(tmp);
			tmp.clear();
		}

	}
	return m_sentens;
}



bool Deeptapod::is_a_paragraphs(std::string str)  // for paragraphs
{
	auto lf = [&](char it){return it == '.' || it == '?' || it == '!' || it == '"';};

	int mid_size = str.size() / 2;
	auto it = str.begin()+mid_size;
	if( lf(*(std::prev(it))) && (*(std::next(it))== '\t' || *(std::next(it))== ' ' || (*(std::next(it))== '\n') && (*(it+2) == '\t'))){return true;} 
	return false;
}


std::vector<std::string> Deeptapod::Divide_into_paragraphs()
{
	auto it_start = m_str.begin();
	auto it =m_str.begin();
	while(it < m_str.end())
	{
		it = std::find(it_start,m_str.end(),'\n');
		std::string tmp ;
		std::copy(it-5,it+6,back_inserter(tmp));
			if(is_a_paragraphs(tmp))
			{
				std::string tmp;
				std::copy(it_start,it,back_inserter(tmp));
				m_paragraph.push_back(tmp);
			}
		if(it == m_str.end()){break;}
		it_start =std::next(it);
	}
	std::string tmp ;
	std::copy(it_start,m_str.end(),back_inserter(tmp));
	m_paragraph.push_back(tmp);
	return m_paragraph;
}
