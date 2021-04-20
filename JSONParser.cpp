#include "JSONParser.hpp"
#include "EntitySet.hpp"
#include "EntityInstance.hpp"

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


EntityInstance JSONParser::parseJSONObject(){
      // parseJSONObject is responsible for parsing a JSON object. As such,
     // the first token is expected to be an open brace.
     _token = _tokenizer.getToken();
     if(!_token.isOpenBracket()){
         cout << "Error: JSONPARSER::parseJSONObject: Expected open brace, but found" << endl;
         _token.print();
         cout<<"Terminating"<<endl;
         exit(1);
     }

     EntityInstance instance;

     
            do {
                Pair pair = parseAPair();
                instance.addPair(pair);
                //  cout<<"pushing back"<<_token.isComa()<<endl;
                _token = _tokenizer.getToken();
                // cout<<"Printing token"<<endl;
                // _token.print();
                if(_token.isComa()){
                    instance.insertComa(_token.isComa());
                }
                // pair.print(5, _token.isComa());
                //instnace print here 
            } while(_token.isComa());
            instance.insertComa(_token.isComa());
            if( ! _token.isCloseBracket()){//checking close bracket of entity instance 
                cout << "Error: JSONPARSER::parseJSONObject: Expected close bracket, but found" << endl;
                _token.print();
                cout<<"Terminating"<<endl;
                exit(1);

            }

     

     return instance;
}

EntitySet JSONParser::parseJSONEntity() {
    JSONToken _token = _tokenizer.getToken();
    if(!_token.isOpenBrace()){
        cout << "Error: JSONPARSER::parseJSONEntity: Expected Open brace, but found" << endl;
        _token.print();
        cout<<"Termaintating"<<endl;
        exit(1);
    }
    EntitySet entitySet;
    while(! _token.isCloseBracket()){
        EntityInstance instance = parseJSONObject();
        entitySet.addEntity(instance);
        _token = _tokenizer.getToken();
        if(! _token.isComa()){
            break;
        }
    }

    if(! _token.isCloseBrace()) {
        cout<< "Error JSON::ParseJsonentity expected close brace but found"<<endl;
        _token.print();
        exit(1);
    }
    return entitySet;
}

Pair JSONParser::parseAPair(){

    string key;
    string value;
    _token = _tokenizer.getToken();
    if(! _token.isString()){
        cout<< "Error: JSONPARSER::parseAPair: Expected a key but instead found"<<endl;
        _token.print();
        cout<<"Terminating"<<endl;
        exit(1);
    }
    key = _token.getString();
    _token = _tokenizer.getToken();
    if(! _token.isColon()){
        cout<< "Error: JSONPARSER::parseAPair: Expected a colon but instead found"<<endl;
        _token.print();
        cout<<"Terminating"<<endl;
        exit(1);
    }
    // cout<<"found a key"<<key<<endl;
    _token = _tokenizer.getToken();
    // cout<<"Value"<<endl;
    // _token.print();
    if(! _token.isDigit() && !_token.isString()){
        cout<< "Error: JSONPARSER::parseAPair: Expected a Value but instead found"<<endl;
       _token.print();
        cout<<"Terminating"<<endl;
        exit(1);
    }
    if(!_token.isDigit()){
        string stringValue = _token.getString();
        // cout<<"this string value"<<value<<endl;
        // cout<<"passing this key"<<key<<endl;
        Pair pair(key, stringValue);
        return pair;
    }
    else{
        double doubleValue = _token.getDigit();
        // cout<<"this double value"<<value<<endl;
        Pair pair(key, doubleValue);
        return pair;
    }
    // value = token.getValue();
}







                                               

