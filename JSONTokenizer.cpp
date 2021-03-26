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

bool JSONTokenizer::charOfInterest(char c){
    if(c=='['||c==']'|| c=='{' || c=='}'||c=='"'||c==','||c==':'){
        // cout<<c<<endl;
        // if(c=='"'){
        //     cout<<"found"<<c<<endl;
        //     cout<<"next value"<<char(inputstream.peek())<<endl;
        // }
        return true;
    }
    return false;
}

string JSONTokenizer::KeyParser(){
    char c1;
    string key;
    while(inputstream.get(c1)){
        
        if(isalpha(c1)){
            key = key + string(1, c1);
            if(char(inputstream.peek()) == '"'){
                inputstream.get(c1);
                return key;
            }
        }
    }
    return key;
}

JSONToken JSONTokenizer::ValueParser(JSONToken &token){
    char c2;
    string value;
    while(inputstream.get(c2)){
        if(isalnum(c2)|| char(c2) == '.'){//may need to check for open and close quote string here 
            value = value + c2;
            if(char(inputstream.peek()) == '"'){//checking for string value
                inputstream.get(c2);
                if(char(inputstream.peek()) == ','){
                    token.isComa() = true;
                }
                token.isStringValue() = true;
                token.makeValue(value);
                return token;
            }
            else if(isspace(inputstream.peek())){//if next character is space break loop and return current token 
                token.isDigitValue() = true;
                // string str = "123.4567";
    // double num_double = std::stod(str);
    // cout<<num_double;
                double num_double = stod(value);
                token.makeValue(num_double);
                return token;
            }
            else if(char(inputstream.peek()) == ','){
                token.isDigitValue() = true;
                token.isComa() = true;
                // string str = "123.4567";
    // double num_double = std::stod(str);
    // cout<<num_double;
    //token has coma 
                double num_double = stod(value);
                token.makeValue(num_double);
                return token;
            }
        }
    }
    return token;
}


JSONToken JSONTokenizer::getToken(){
    char c;
     if( ! inputstream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while(inputstream.get(c)){
        if(charOfInterest(c)){
            // if(c== '"'){
            //     cout<<"found breaking"<<c<<endl;
            //     cout<<"next value"<<char(inputstream.peek())<<endl;
            // }
            break;
        }
    }


    JSONToken jsonToken;
    // cout<<"found this c    "<<c<<endl;
    if(inputstream.eof()){
        jsonToken.endOfFile() = true;
    }
    else if(c=='['){
        jsonToken.isOpenBrace() = true;
    }
    else if(c=='{'){
        jsonToken.isOpenBracket()= true;
    }
    else if(c==']'){
        jsonToken.isCloseBrace()= true;
    }
    else if(c=='}'){
        jsonToken.isCloseBracket() = true;
    }
    else if(c==','){
        jsonToken.isComa() = true;
        //  while(inputstream.get(c)){
        //      cout<<c<<endl;
             
        // }

    }
    else if(c=='"' && isalpha(inputstream.peek())){
        // cout<<"actiavted while "<<c<<"and next is "<<char(inputstream.peek())<<endl;
        jsonToken.isKey() = true;
        string parsed_key = KeyParser();
        // cout<<"returned this"<<parsed_key<<endl;
        jsonToken.makeKey(parsed_key);
    }
    else if(c== ':'){
        jsonToken = ValueParser(jsonToken);

    }

    


    return jsonToken;




    

}


