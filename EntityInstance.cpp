#include "iostream"
#include <string>
#include <vector>
#include <iomanip>
#include "EntityInstance.hpp"
using namespace std;

void EntityInstance::addPair(Pair &pair){
    entityPairs.push_back(pair);
}

void EntityInstance::insertComa(bool isComa){
    addComa.push(isComa);
}

void EntityInstance::print(){
    cout<<setw(5)<<"{"<<endl;
    for(auto pairs: entityPairs){
        // cout<<"add coma front"<<addComa.front()<<endl;
        pairs.print(10, addComa.front());
        addComa.pop();

    }
    cout<<setw(5)<<"}";


}
