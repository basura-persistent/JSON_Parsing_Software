#include <iostream>
#include <iomanip>
#include <string>
#include "JSONToken.hpp"
using namespace std;

JSONToken::JSONToken(): _isOpenBrace{false},
                        _isCloseBrace{false},
                        _isOpenBracket{false},
                        _isCloseBracket{false},
                        _isKey{false},
                        _isValue{false},
                        _isComa(false),
                        _endOfFile{false}{}

bool &JSONToken::isOpenBrace(){return _isOpenBrace;}

bool &JSONToken::isCloseBrace(){return _isCloseBrace;}

bool &JSONToken::isOpenBracket(){return _isOpenBracket;}

bool &JSONToken::isCloseBracket(){return _isCloseBracket;}

bool &JSONToken::isColon(){return _isColon;}
bool &JSONToken::isComa(){return _isComa;}

string JSONToken::getKey(){return _key;}
string JSONToken::getValue(){return _value;}

bool &JSONToken::isKey(){return _isKey;}
bool &JSONToken::isValue(){return _isValue;}

void JSONToken::makeKey(string key){
    _key = key;
}

void JSONToken::makeValue(string value){
    _value = value;
}

void JSONToken::print(){
    // cout<<"printing "<<_key<<endl;
    // cout<<"iskey is"<<_isKey<<endl;
    // cout<<"coma is "<<_isComa<<endl;
    if(isOpenBrace()){
        cout<<"["<<endl;
    }
    else if(isCloseBrace()){
        cout<<"]"<<endl;
    }
    else if(isOpenBracket()){
        cout<<"{"<<endl;
    }
    else if(isCloseBracket()){
        cout<<"}"<<endl;
    }
    // else if(isColon()){
    //     cout<<":"<<endl;
    // }
    else if(isComa()){
        cout<<","<<endl;
    }
    else if(isKey()){
        cout<<_key<<endl;

    }
    else if(isValue()){
        cout<<":"<<endl;
        cout<<_value<<endl;
    }
}

bool &JSONToken::endOfFile(){
    return _endOfFile;
}






