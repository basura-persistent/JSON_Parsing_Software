#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "JSONTokenizer.hpp"
#include <string>
using namespace std;

JSONTokenizer::JSONTokenizer( string name):
                                        inputFileName{name}{
                                            inputstream.open(inputFileName, ios::in);
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
                return key;
            }
        }
    }
    return key;
}

string JSONTokenizer::ValueParser(){
    char c2;
    string value;
    while(inputstream.get(c2)){
        if(isalnum(c2)|| char(c2) == '.'){
            value = value + c2;
            if(char(inputstream.peek() == '"')){//checking for string value
                return value;
            }
            else if(char(inputstream.peek()) == ','){//checking for integer value 
                return value;
            }
        }
    }
    return value;
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
        jsonToken.isValue() = true;
        string parsed_value = ValueParser();
        jsonToken.makeValue(parsed_value);
    }

    


    return jsonToken;




    

}


