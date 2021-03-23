#include <iostream>
#include <fstream>
#include "JSONTokenizer.hpp"
#include "JSONToken.hpp"
#include "Pair.cpp"

int main(int argc, char *argv[]){
    ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if( ! inputStream.is_open()) {
        cout<<"Unable to open"<<argv[1] <<". Terminating...";
        exit(2);
    }
    inputStream.close();
    JSONTokenizer jsonTOKENIZER(argv[1]);
    JSONToken token =  jsonTOKENIZER.getToken();
    token.print();
    Pair pair(token.getKey(), token.getValue());
    pair.print(5, token.isComa());
    while( ! token.endOfFile()){
        // token.print();
        
        token = jsonTOKENIZER.getToken();
    }
}