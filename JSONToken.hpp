#ifndef JSON_TOKEN_HPP
#define JSON_TOKEN_HPP

#include <string>
#include <fstream>
using namespace std;

class JSONToken {

    public:
        JSONToken();
        bool &isOpenBrace();
        bool &isCloseBrace();

        bool &isOpenBracket();
        bool &isCloseBracket();

        void makeKey(string key);
        void makeValue(string value);

        string getKey();
        string getValue();

        bool &isKey();
        bool &isValue();

        bool &isColon();
        bool &isComa();
        void print();

        bool &endOfFile();
    
    private:
        bool _isOpenBrace, _isCloseBrace, _isOpenBracket, _isCloseBracket, _isColon, _isComa, _isKey, _isValue, _endOfFile;
        string _key, _value;


};

#endif 