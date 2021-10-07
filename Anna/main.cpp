
#include <iostream>
#include "parse.h"

int main()
{
    std::string word = "Victoria";
   std::string text1 = "Victoria Falls is a waterfall in south central Africa in the Zambezi River between southeast Zambia and northwest Zimbabwe. It is 108.3 m high and 1,703 m wide.";
    Parse p1(word, text1);
    std::cout << p1.getEntity() << std::endl;

    // chashxatox@
    std::string text2 = "The person going to the waterfall was Victoria";
    Parse p2(word, text2);
    std::cout << p2.getEntity() << std::endl;

    std::string text3 = "Victoria is person";
    Parse p3(word, text3);
    std::cout << p3.getEntity() << std::endl;
    return 0;
}
