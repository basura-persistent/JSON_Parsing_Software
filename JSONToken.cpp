#include <iostream>
#include <iomanip>
#include <string>
#include "JSONToken.hpp"
using namespace std;

JSONToken::JSONToken(): _isOpenBrace{false},
                        _isCloseBrace{false},
                        _isOpenBracket{false},
                        _isCloseBracket{false},
                        _isDigit{false},
                        _isString{false},
                        _isComa{false},
                        _isColon{false},
                        _endOfFile{false}{}

bool &JSONToken::isOpenBrace(){return _isOpenBrace;}

bool &JSONToken::isCloseBrace(){return _isCloseBrace;}

bool &JSONToken::isOpenBracket(){return _isOpenBracket;}

bool &JSONToken::isCloseBracket(){return _isCloseBracket;}

bool &JSONToken::isColon(){return _isColon;}
bool &JSONToken::isComa(){return _isComa;}

string JSONToken::getString(){return _string;}
double JSONToken::getDigit(){return _digit;}

bool &JSONToken::isString(){return _isString;}
bool &JSONToken::isDigit(){return _isDigit;}


void JSONToken::makeString(string newString){
    _string = newString;
}

void JSONToken::makeDouble(double newDouble){
    _digit = newDouble;
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
    else if(isColon()){
        cout<<":"<<endl;
    }
    else if(isDigit()){
        cout<<getDigit()<<endl;
    }
    else if(isString()){
        cout<<getString()<<endl;
    }
    else{
        cout<<"Unkown Token"<<endl;
    }
}

bool &JSONToken::endOfFile(){
    return _endOfFile;
}









