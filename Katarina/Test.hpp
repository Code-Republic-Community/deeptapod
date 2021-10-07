#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>

    void  Test::Test_divideIntoSentenses::prepareDataSet(std::string in, std::string out) {

            std::fstream input(in);
              while (!input.eof()) {
                std::string str ; 
                std::getline(input, str);
                text += str ;
            }
            
            std::fstream output(out);
            while (!output.eof()) {
                std::string str ; 
                std::getline(output, str);
               if(str != " "){
                  sentence.push_back(str);
               }
            }

    }  

      void Test::Test_divideIntoSentenses::test_divideIntoSentenses(){

        c2.push_back("The museum is so huge, you could spend weeks there.");
        c2.push_back("Henry got tired walking around the museum and said \"Enough!I need to take a break and rest.\"");
        c2.push_back("We took lots of breaks and sat in cafes along the river Seine.");
        c2.push_back("The French food we ate was delicious.");


        c1.push_back("I live in a house near the mountains.");
        c1.push_back("I have two brothers and one sister, and I was born last.");
        c1.push_back("My father teaches mathematics, and my mother is a nurse at a big hospital.");


          for(int i = 1; i <= 2; ++i){
            
            char c = i + 48;

            std::string input = std::string("S_c") + c  +  std::string("_input.txt");
            std::string output = std::string("S_c") + c  +  std::string("_output.txt");

            Test::Test_divideIntoSentenses::prepareDataSet(input,output);
      
            bool equal;


            if(i == 1){
              equal = (sentence == c1); 
               }
            if(i == 2){
              equal = (sentence == c2); 
            }
        
            std::cout<< "Test " << i << ":" << std::endl;

            if(equal){

             std::cout<<"Test passed"<<std::endl;

           }else{

             std::cout<<"test failed"<<std::endl;

             std::cout<<"Output::"<<std::endl;
               for (int j = 0; j < c1.size(); j++){
                 std::cout<<c1[j]<<std::endl;
           }
                  std::cout<<std::endl;
                  std::cout<<std::endl;

            std::cout<<"Expected Output::"<<std::endl;
               for (int k = 0; k < sentence.size(); k++)
           {
               std::cout<<sentence[k]<<std::endl;
      
           }

           }
              std::cout<<std::endl;
               sentence.clear();
          }



       
          // for(int i = 1; i <= 7; ++i){
            
          //   char c = i + 48;

          //   std::string input = std::string("S_c") + c  +  std::string("_input.txt");
          //   std::string output = std::string("S_c") + c  +  std::string("_output.txt");

          //   Test::Test_divideIntoSentenses::prepareDataSet(input,output);
       
          //     auto result = DivideIntoSentenses(text);

          //   bool equal = (sentence == result);

          //   std::cout<< "Test " << i << ":" << std::endl;

          //   if(equal){

          //    std::cout<<"Test passed"<<std::endl;

          //  }else{

          //    std::cout<<"test failed"<<std::endl;

          //    std::cout<<"Output::"<<std::endl;
          //      for (int j = 0; j < result.size(); j++){
          //        std::cout<<result[j]<<std::endl;
          //  }
          //         std::cout<<std::endl;
          //         std::cout<<std::endl;

          //   std::cout<<"Expected Output::"<<std::endl;
          //      for (int k = 0; k < sentence.size(); k++)
          //  {
          //      std::cout<<sentence[k]<<std::endl;
      
          //  }

          //  }
          //     std::cout<<std::endl;
          //      sentence.clear();
          // }

  }






  void  Test::Test_divideIntoParagraphs::prepareDataSet(std::string in, std::string out) {

            std::fstream input(in);

              while (!input.eof()) {
                std::string str ; 
                std::getline(input, str);
                if(str == "/"){
                  text += "\n";
                }
                else{
                  text += str ;
                  text += " ";
                } 
                
            }
            
            std::string new_str;
            std::fstream output(out);
            while (!output.eof()) {
                std::string str ; 
                std::getline(output, str);
                
                 if(str == "/"){
                   paragraph.push_back(new_str);
                   new_str = "";
                 }

                 else if(str == "@"){
                     new_str += "\n";
                  } else{
                  new_str += str;
                } 
           
            }

    }  

      void Test::Test_divideIntoParagraphs:: test_divideIntoParagraphs(){
           
           p1.push_back("Lucas goes to school every day of the week. He has many subjects to go to each school day: English, art, science, mathematics, gym, and history.His mother packs a big backpack full of books and lunch for Lucas.");
           p1.push_back("His first class is English, and he likes that teacher very much. His English teacher says that he is a good pupil, which Lucas knows means thatshe thinks he is a good student.");

           p2.push_back("His next class is art. He draws on paper with crayons and pencils and sometimes uses a ruler. Lucas likes art. It is his favorite class.");

             for(int i = 1; i <= 2; ++i){
            
            char c = i + 48;

            std::string input = std::string("P_c") + c  +  std::string("_input.txt");
            std::string output = std::string("P_c") + c  +  std::string("_output.txt");

            Test::Test_divideIntoParagraphs::prepareDataSet(input,output);
      
            bool equal;

            if(i == 1){
              equal = (paragraph == p1); 
               }
            if(i == 2){
              equal = (paragraph == p2); 
            }
        
            std::cout<< "Test " << i << ":" << std::endl;

            if(equal){

             std::cout<<"Test passed"<<std::endl;

           }else{

             std::cout<<"test failed"<<std::endl;

             std::cout<<"Output::"<<std::endl;
               for (int j = 0; j < p2.size(); j++){
                 std::cout<<p2[j]<<std::endl;
           }
                  std::cout<<std::endl;
                  std::cout<<std::endl;

            std::cout<<"Expected Output::"<<std::endl;
               for (int k = 0; k < paragraph.size(); k++)
           {
               std::cout<<paragraph[k]<<std::endl;
      
           }

           }
              std::cout<<std::endl;
      
                paragraph.clear();

          }


          //   for(int i = 1; i <= 7; ++i){
            
          //   char c = i + 48;

          //   std::string input = std::string("P_c") + c  +  std::string("_input.txt");
          //   std::string output = std::string("P_c") + c  +  std::string("_output.txt");

          //   Test::Test_divideIntoParagraphs::prepareDataSet(input,output);
      
          // auto result = DivideIntoParagraphs(text);

          // bool equal = (paragraph == result);
        
          //   std::cout<< "Test " << i << ":" << std::endl;

          //   if(equal){

          //    std::cout<<"Test passed"<<std::endl;

          //  }else{

          //    std::cout<<"test failed"<<std::endl;

          //    std::cout<<"Output::"<<std::endl;
          //      for (int j = 0; j < p2.size(); j++){
          //        std::cout<<p2[j]<<std::endl;
          //  }
          //         std::cout<<std::endl;
          //         std::cout<<std::endl;

          //   std::cout<<"Expected Output::"<<std::endl;
          //      for (int k = 0; k < paragraph.size(); k++)
          //  {
          //      std::cout<<paragraph[k]<<std::endl;
      
          //  }

          //  }
          //     std::cout<<std::endl;
      
          //       paragraph.clear();

          // }
         
  }
     

      void  Test::Test_divideIntoWords::prepareDataSet(std::string in, std::string out) {

            std::fstream input(in);

              while (!input.eof()) {

                std::getline(input, sentence);
      
            }
            
            std::fstream output(out);
            while (!output.eof()) {

                std::string str ; 
                output<<str;
                word.push_back(str);
                
            }

    }  

          void Test::Test_divideIntoWords:: test_divideIntoWords(){

          Test::Test_divideIntoWords::prepareDataSet("W_c1_input.txt","W_c1_output.txt");

            w1.push_back("Stephanie");
            w1.push_back("recently");
            w1.push_back("took");
            w1.push_back("a");
            w1.push_back("weekend");
            w1.push_back("trip");
            w1.push_back("to");
            w1.push_back("Los");
            w1.push_back("Angeles");
            w1.push_back("California");

            w2.push_back("What");
            w2.push_back("about");

             for(int i = 1; i <= 2; ++i){
            
            char c = i + 48;

            std::string input = std::string("W_c") + c  +  std::string("_input.txt");
            std::string output = std::string("W_c") + c  +  std::string("_output.txt");

            Test::Test_divideIntoWords::prepareDataSet(input,output);
      
            bool equal;

            if(i == 1){
              equal = (word == w1); 
               }
            if(i == 2){
              equal = (word == w2); 
            }
        
            std::cout<< "Test " << i << ":" << std::endl;

            if(equal){

             std::cout<<"Test passed"<<std::endl;

           }else{

             std::cout<<"test failed"<<std::endl;

             std::cout<<"Output::"<<std::endl;
               for (int j = 0; j < w2.size(); j++){
                 std::cout<<w2[j]<<std::endl;
           }
                  std::cout<<std::endl;
                  std::cout<<std::endl;

            std::cout<<"Expected Output::"<<std::endl;
               for (int k = 0; k < word.size(); k++)
           {
               std::cout<<word[k]<<std::endl;
      
           }

           }
              std::cout<<std::endl;
      
                word.clear();

          }

          //   for(int i = 1; i <= 7; ++i){
            
          //   char c = i + 48;

          //   std::string input = std::string("W_c") + c  +  std::string("_input.txt");
          //   std::string output = std::string("W_c") + c  +  std::string("_output.txt");

          //   Test::Test_divideIntoWords::prepareDataSet(input,output);
      
          //   auto result = DivideIntoWords(text);

          //   bool equal = (word == result);
        
          //   std::cout<< "Test " << i << ":" << std::endl;

          //   if(equal){

          //    std::cout<<"Test passed"<<std::endl;

          //  }else{

          //    std::cout<<"test failed"<<std::endl;

          //    std::cout<<"Output::"<<std::endl;
          //      for (int j = 0; j < w2.size(); j++){
          //        std::cout<<w2[j]<<std::endl;
          //  }
          //         std::cout<<std::endl;
          //         std::cout<<std::endl;

          //   std::cout<<"Expected Output::"<<std::endl;
          //      for (int k = 0; k < word.size(); k++)
          //  {
          //      std::cout<<word[k]<<std::endl;
      
          //  }

          //  }
          //     std::cout<<std::endl;
      
          //       word.clear();

          // }
          }