#include "Split.h"



Split::Split(const std::string& str)  // ctor
{
	m_str = str;
}


void Split::setString(const std::string& str) //Set
{
	m_str = str;
}

std::string Split::getString()const  // Get
{
	return m_str;
}


std::vector<std::string> Split::getSentens()const
{
	return m_sentens;
}


std::vector<std::string> Split::getParagraphs()const
{
	return m_paragraph;
}


std::vector<std::string> Split::splitToSentences()  // for Sentenses
{
	int ellipsis = 3 ;
	auto lf = [&](char it){return it == '.' || it == '?' || it == '!' || it == '"' ;};
	auto it = m_str.begin();
	auto it_begin = m_str.begin();
	std::string tmp;
	while (it <= m_str.end())
	{
		while (*it_begin == ' ' || *it_begin == '\n' || *it_begin == '\t')
		{
			it_begin++;
		}
		it = std::find_if(it_begin,m_str.end(),[&](char ch)
				{return ch == '.' || ch == '?' || ch == '!' || ch == '"' || ch == '\n' ;} );
		int count = 1 ;
		while (*it == *std::next(it))
		{
			++it;
			++count;
		}
		if (*std::prev(it) == '.' && count == ellipsis) {continue;}
		if (*it == '\n' && lf(*std::prev(it))) {continue;}
		if (*it == '"') { it--;}
		if (lf(*std::prev(it)) && *it == '"')
		{
			it = std::find(std::next(it_begin), m_str.end(), '"');
			std::copy(it_begin,++it,back_inserter(tmp));
			it_begin = it;
			m_sentens.push_back(tmp);
			tmp.clear();
			continue;
		}
		if (*it == '.')   /* for floating numbers */
		{
			if (*std::prev(it) > '0' && *std::prev(it) < '9' && *std::next(it) > '0' && *std::next(it) < '9')
			{
				continue;
			}
		}
		std::copy(it_begin,++it,back_inserter(tmp));
		it_begin = it;
		m_sentens.push_back(tmp);
		tmp.clear();
		if (*(it) == '"')
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



bool Split::isParagraphs(std::string str)  // for paragraphs
{
	auto lf = [&](char it){return it == '.' || it == '?' || it == '!' || it == '"';};

	int mid_size = str.size() / 2;
	auto it = str.begin()+mid_size;
	if ( lf(*(std::prev(it))) && (*(std::next(it))== '\t' || *(std::next(it))== ' ' || (*(std::next(it))== '\n') && (*(it+2) == '\t'))){return true;} 
	return false;
}


std::vector<std::string> Split::splitToParagraphs()
{
	auto it_start = m_str.begin();
	auto it =m_str.begin();
	while (it < m_str.end())
	{
		it = std::find(it_start,m_str.end(),'\n');
		std::string tmp ;
		std::copy(it - 5,it + 6,back_inserter(tmp));
		if (isParagraphs(tmp))
		{
			while (*it == *(std::next(it)))
			{
				++it;
			}
			std::string tmp;
			std::copy(it_start,it,back_inserter(tmp));
			m_paragraph.push_back(tmp);
		}
		if (it == m_str.end()) {break;}
		it_start = std::next(it);
	}
	std::string tmp ;
	std::copy(it_start,m_str.end(),back_inserter(tmp));
	m_paragraph.push_back(tmp);
	return m_paragraph;
}
