#include <iostream>
#include <fstream>
#include <string> 
#include "Pair.cpp"
#include "JSONParser.cpp"
#include "EntityInstance.cpp"
#include "EntitySet.cpp"

int main(int argc, char *argv[]){
    ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if( ! inputStream.is_open()) {
        cout<<"Unable to open"<<argv[1] <<". Terminating...";
        exit(2);
    }
    inputStream.close();
    JSONParser jsonPARSER(argv[1]);
    EntitySet entitySet = jsonPARSER.parseJSONObject();
    entitySet.print();
    // string str = "123.4567";
    // double num_double = std::stod(str);
    // cout<<num_double;
    // JSONTokenizer jsonTOKENIZER(argv[1]);
    // JSONToken token =  jsonTOKENIZER.getToken();
    // token.print();
    // Pair pair(token.getKey(), token.getValue());
    // pair.print(5, token.isComa());
    // while( ! token.endOfFile()){
    //     // token.print();
        
    //     token = jsonTOKENIZER.getToken();
    // }
}