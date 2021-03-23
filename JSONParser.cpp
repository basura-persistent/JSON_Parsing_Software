#include "JSONParser.hpp"
#include "EntitySet.hpp"


JSONParser::JSONParser(string inputFileName): _tokenizer{inputFileName}{}

void JSONParser::TokenPrint(){
    _token.print();
}

bool JSONParser::ValidateEndOfFile(){
    return _token.endOfFile();
}

bool JSONParser::ValidateOpenBrace(){
    _token = _tokenizer.getToken();
    return _token.isOpenBrace();
}

bool JSONParser::ValidateCloseBrace(){
    _token = _tokenizer.getToken();
    return _token.isCloseBrace();
}


EntityInstance JSONParser::parseJSONObject(){
      // parseJSONObject is responsible for parsing a JSON object. As such,
     // the first token is expected to be an open brace.
     _token = _tokenizer.getToken();
     if(!_token.isOpenBracket()){//this should be brackets 
         cout << "Error: JSONPARSER::parseJSONObject: Expected open brace, but found" << endl;
         _token.print();
         cout<<"Terminating"<<endl;
         exit(1);
     }
     EntityInstance instance;
     do {
        Pair pair = parseAPair();
         instance.addPair(pair);
         _token = _tokenizer.getToken();
     } while(_token.isComa());
     if( ! _token.isCloseBracket()){//checking close bracket of entity instance 
         cout << "Error: JSONPARSER::parseJSONObject: Expected close brace, but found" << endl;
         _token.print();
         cout<<"Terminating"<<endl;
         exit(1);

     }
     return instance;
}

Pair JSONParser::parseAPair(){

    string key;
    string value;
    JSONToken token = _tokenizer.getToken();
    if(! token.isKey()){
        cout<< "Error: JSONPARSER::parseAPair: Expected a key but instead found"<<endl;
        token.print();
        cout<<"Terminating"<<endl;
        exit(1);
    }
    key = token.getKey();
    // cout<<"found a key"<<key<<endl;
    token = _tokenizer.getToken();
    cout<<"Value"<<endl;
    token.print();
    if(! token.isDigitValue() && !token.isStringValue()){
        cout<< "Error: JSONPARSER::parseAPair: Expected a Value but instead found"<<endl;
        token.print();
        cout<<"Terminating"<<endl;
        exit(1);
    }
    if(token.isDigitValue()){
        
    }
    value = token.getValue();
    cout<<"placing this value"<<value<<endl;
    Pair pair(key, value);
    return pair;
}







                                               

