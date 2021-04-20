#include <iostream>
#include <fstream>
#include <string> 
#include "Pair.cpp"
#include "JSONParser.cpp"
#include "EntityInstance.cpp"
#include "EntitySet.cpp"

int main(int argc, char *argv[]){
    ifstream inputStream;
    ifstream inputStream2;
    inputStream.open(argv[1], std::ios::in);
    inputStream2.open(argv[2], std::ios::in);
    if( ! inputStream.is_open()) {
        cout<<"Unable to open"<<argv[1] <<". Terminating...";
        exit(2);
    }
    if( ! inputStream2.is_open()){
        cout<<"Unable to open"<<argv[2] <<". Terminating...";
        exit(2);
    }
    inputStream.close();
    inputStream2.close();
    JSONParser jsonPARSER(argv[1]);
    JSONParser jsonPARSER2(argv[2]);
    EntitySet entitySet = jsonPARSER.parseJSONEntity();
    EntitySet entitySet2 = jsonPARSER2.parseJSONEntity();
    entitySet.commonElements(entitySet2);//EntitySet::commonElements geenerates the 2D array for us and also prints the array automatically. 


    return 0;
}