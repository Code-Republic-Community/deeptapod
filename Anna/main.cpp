#include <iostream>
#include "entityRecognition.h"

int main()
{
    std::string word = "Victoria";
    std::string text1 = "Victoria Falls is a waterfall in south central Africa in the Zambezi River between southeast Zambia and northwest Zimbabwe. It is 108.3 m high and 1,703 m wide.";
    EntitySpecifier p1(word, text1, text1);
    std::cout << "1:" << p1.getEntity() << std::endl;

    // chashxatox@
    std::string text2 = "The person going to the waterfall was Victoria";
    EntitySpecifier p2(word, text2, text2);
    std::cout << "2:" << p2.getEntity() << std::endl;

    std::string text3 = "Victoria is person";
    EntitySpecifier p3(word, text3, text3);
    std::cout << "3:" << p3.getEntity() << std::endl;

    std::string text4 = "waterfall Victoria is person dfuhqf person qefhqfq";
    EntitySpecifier p4(word, text4, text4);
    std::cout << "4:" << p4.getEntity() << std::endl;

    return 0;
}
