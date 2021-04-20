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
        void makeString(string newString);
        void makeDouble(double value);

        string getString();
        double getDigit(); 

        bool &isKey();
        bool &isString();
        bool &isDigit();

        bool &isColon();
        bool &isComa();
        void print();

        bool &endOfFile();
    
    private:
        bool _isOpenBrace, _isCloseBrace, _isOpenBracket, _isCloseBracket, _isColon, _isComa, _isString, _isDigit, _endOfFile;
        string _string;

        double _digit;
        


};

#endif 