#ifndef JSON_TOKENIZER_HPP
#define JSON_TOKENIZER_HPP

#include <string>
#include<fstream>
#include "JSONToken.hpp"
#include <string>

using namespace std;

class JSONTokenizer {
    public:
        JSONTokenizer(string);
        JSONTokenizer();
        JSONToken getToken();
        bool streamPeek();


    private:
        string inputFileName;
        ifstream inputstream;
        string stringParser();
        double doubleParser();
        
};


#endif