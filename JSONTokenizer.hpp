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
        JSONToken getToken();


    private:
        string inputFileName;
        ifstream inputstream;
        bool charOfInterest(char c);
        string KeyParser();
        string ValueParser();
        
};


#endif