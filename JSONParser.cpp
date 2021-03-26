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
    return _token.isCloseBrace();
}


EntitySet JSONParser::parseJSONObject(){
      // parseJSONObject is responsible for parsing a JSON object. As such,
     // the first token is expected to be an open brace.
     if(!ValidateOpenBrace()){
         cout << "Error: JSONPARSER::parseJSONObject: Expected open brace, but found" << endl;
         _token.print();
         cout<<"Terminating"<<endl;
         exit(1);
     }

     EntitySet entitySet;

     while(!_tokenizer.streamPeek()){
            cout<<"looping"<<endl;
            _token = _tokenizer.getToken();
            if(_token.isCloseBrace()){
                break;
            }
            if(_token.isComa()){
                _token = _tokenizer.getToken();
            }
            if(!_token.isOpenBracket()){//this should be brackets 
                cout << "Error: JSONPARSER::parseJSONObject: Expected open braket, but found" << endl;
                _token.print();
                cout<<"Terminating"<<endl;
                exit(1);
            }
            EntityInstance instance;
            do {
                Pair pair = parseAPair();
                instance.addPair(pair);
                //  cout<<"pushing back"<<_token.isComa()<<endl;
                instance.insertComa(_token.isComa());
                _token = _tokenizer.getToken();
                //instnace print here 
            } while(_token.isComa());
            if( ! _token.isCloseBracket()){//checking close bracket of entity instance 
                cout << "Error: JSONPARSER::parseJSONObject: Expected close bracket, but found" << endl;
                _token.print();
                cout<<"Terminating"<<endl;
                exit(1);

            }
            entitySet.addEntity(instance);
     }

     if(!ValidateCloseBrace()){
                cout << "Error: JSONPARSER::parseJSONObject: Expected close bracket, but found" << endl;
                _token.print();
                cout<<"Terminating"<<endl;
                exit(1);

     }

     return entitySet;
}

Pair JSONParser::parseAPair(){

    string key;
    string value;
    _token = _tokenizer.getToken();
    if(! _token.isKey()){
        cout<< "Error: JSONPARSER::parseAPair: Expected a key but instead found"<<endl;
        _token.print();
        cout<<"Terminating"<<endl;
        exit(1);
    }
    key = _token.getKey();
    // cout<<"found a key"<<key<<endl;
    _token = _tokenizer.getToken();
    // cout<<"Value"<<endl;
    // _token.print();
    if(! _token.isDigitValue() && !_token.isStringValue()){
        cout<< "Error: JSONPARSER::parseAPair: Expected a Value but instead found"<<endl;
       _token.print();
        cout<<"Terminating"<<endl;
        exit(1);
    }
    if(!_token.isDigitValue()){
        string value = _token.getStringValue();
        // cout<<"this string value"<<value<<endl;
        Pair pair(key, value);
        return pair;
    }
    else{
        double value = _token.getDigitValue();
        // cout<<"this double value"<<value<<endl;
        Pair pair(key, value);
        pair.isDouble() = true;
        return pair;
    }
    // value = token.getValue();
}







                                               

