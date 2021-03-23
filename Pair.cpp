#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Pair.hpp"


using namespace std;

Pair::Pair(string attributeName, string attributeValue): _attributeName{""}, _attributeStringValue{""}{
    _attributeName = attributeName;
    _attributeStringValue =  attributeValue;
    cout<<"constructing this string value"<<_attributeStringValue<<endl;
}

Pair::Pair(string attributeName, double attributeValueInt): _attributeNumberValue{0},
                                                            _isNumber{false}
{

    _attributeName = attributeName;
    _attributeNumberValue = attributeValueInt;
}

bool &Pair::isDouble(){
    return _isNumber;
}

double Pair::numberValue(){
    return _attributeNumberValue;
}

string Pair::stringValue(){
    return _attributeStringValue;
}

string Pair::attributeName(){
    return _attributeName;
}

void Pair::print(int numOfSpace, bool addComa){
    cout<<attributeName()<<":";
    // if(isDouble()){
        // if(numberValue() == 0){
          if(!_isNumber){
            cout<<_attributeStringValue;
              
          }
          else{ 
              cout<<_attributeNumberValue;
          }
        // }
        cout<<endl;
    // }
    // else{
    //     cout<<"\""<<stringValue()<<"\"";
    // }

    // if(addComa){
    //     cout<<",";
    // }
    // cout<<endl;
}
