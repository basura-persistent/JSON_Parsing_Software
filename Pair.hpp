#ifndef PAIR_HPP
#define PAIR_HPP
#include <iostream>
#include <string>
using namespace std;

class Pair{

public:
     // use the first constructor if the value of the pair is a string
    // and use the second one if it is a double value.
    Pair(string attributeName, string attributeValue);
    Pair(string attributeName, double attributeValueInt);
    bool &isDouble();
    double numberValue();
    string stringValue();
    string attributeName();
    void print(int numSpaces, bool addComa);

private:
    string _attributeName, _attributeStringValue;
    double _attributeNumberValue;
    bool _isNumber;

};

#endif 