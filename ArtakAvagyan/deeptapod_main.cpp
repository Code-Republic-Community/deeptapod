#include "deeptapod.h"



int main()
{
	std::string str;
	str = "I llustrations of the Family of Psittacidae, or Parrots is an 1832 book by Edward Lear containing 42 hand-coloured lithographs (example pictured) ...\n\tLear started painting parrots for the book in 1830 when he was 18 years old, and to get material for his book he studied live birds at the London Zoo and in private collections.\n\n\t \"Although the book was a financial failure, Lear's paintings of parrots established his reputation as one of the best natural history artists of his time.\" It found him work with leading contemporary naturalists, and the young Queen Victoria engaged him to help her with her painting technique. Lear's works influenced children's illustrators such as Beatrix Potter and Maurice Sendak.\n He continued with his nature painting for some years, but from about 1835 he became concerned about his failing eyesight, and increasingly concentrated on his nonsense works and landscape painting. He may have contributed to the illustrations for Charles Darwin's Voyage of the Beagle.";
	Deeptapod test(str);
	std::cout<<test.Get_String()<<std::endl;
	std::cout<< "------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
	auto it =test.Divide_into_sentenses();
	std::copy(it.begin(),it.end(),std::ostream_iterator<std::string>(std::cout,"\n"));
	std::cout<< "------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
	auto it_2 = test.Divide_into_paragraphs();
	std::copy(it_2.begin(),it_2.end(),std::ostream_iterator<std::string>(std::cout,"\n"));

}
