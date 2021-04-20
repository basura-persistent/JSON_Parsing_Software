#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include "JSONTokenizer.hpp"
#include "JSONToken.hpp"
#include <string>
using namespace std;

JSONTokenizer::JSONTokenizer( string name):
                                        inputFileName{name}{
                                            inputstream.open(inputFileName, ios::in);
}

bool JSONTokenizer::streamPeek(){
    if(char(inputstream.peek()) == EOF){
        return true;
    }
    return false;
}

string JSONTokenizer::stringParser(){
    char c1;
    string key;
    while(inputstream.get(c1)){
        
        if(isalnum(c1)){
            key = key + string(1, c1);
            if(char(inputstream.peek()) == '"'){
                inputstream.get(c1);
                return key;
            }
        }
    }
    return key;
}

double JSONTokenizer::doubleParser(){
    char c2;
    string value;
    double num_double = 0;
    while(inputstream.get(c2)){
        if(isdigit(c2)|| char(c2) == '.'){//may need to check for open and close quote string here 
            value = value + c2;
             if(isspace(inputstream.peek())){//if next character is space break loop and return current token 
                double num_double = stod(value);
                return num_double;
            }
            else if(char(inputstream.peek()) == ','){
                double num_double = stod(value);
                return num_double;
            }
        }
    }
    return num_double;
}


JSONToken JSONTokenizer::getToken(){
    char c;
     if( ! inputstream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    inputstream >> c;


    JSONToken jsonToken;
    // cout<<"found this c    "<<c<<endl;
    
    if(c=='"' && isalnum(inputstream.peek())){
        // cout<<"actiavted while "<<c<<"and next is "<<char(inputstream.peek())<<endl;
        jsonToken.isString() = true;
        string parsed_key = stringParser();
        // cout<<"returned this"<<parsed_key<<endl;
        jsonToken.makeString(parsed_key);
    }
     else if(isdigit(c)){
        inputstream.putback(c);
        jsonToken.isDigit() = true;
        double parsedDouble = doubleParser();
        jsonToken.makeDouble(parsedDouble);
    }
    else if(c==','){
        jsonToken.isComa() = true;
    }
    else if(c== ':'){
        jsonToken.isColon() = true;
    }
    else if(c=='{'){
        jsonToken.isOpenBracket()= true;
    }
    else if(c=='}'){
        jsonToken.isCloseBracket() = true;
    }
    else if(c=='['){
        jsonToken.isOpenBrace() = true;
    }
    else if(c==']'){
        jsonToken.isCloseBrace()= true;
    }
    else if(inputstream.eof()){
        jsonToken.endOfFile() = true;
    }
    
    return jsonToken;

}


