class Normalizator
{
	public:
		//method functions
		std::vector<std::string> text_to_vector(std::string& text);
		bool is_word(std::string& word);
		std::string normalize(std::string word);

		//constructors, operators & destructor
		Normalizator();
		~Normalizator();

	private:
		std::string m_text;
		std::string m_word;
		std::vector<std::string> wordsDB;
}
