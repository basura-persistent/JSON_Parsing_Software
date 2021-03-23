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
        void makeValue(double value);

        string getKey();
        string getStringValue();
        double getDigitValue(); 

        bool &isKey();
        bool &isStringValue();
        bool &isDigitValue();

        bool &isColon();
        bool &isComa();
        void print();

        bool &endOfFile();
    
    private:
        bool _isOpenBrace, _isCloseBrace, _isOpenBracket, _isCloseBracket, _isColon, _isComa, _isKey, _isStringValue, _isDigitValue, _endOfFile;
        string _key, _stringValue;

        double _digitValue;
        


};

#endif 