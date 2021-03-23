#include "iostream"
#include <string>
#include <vector>
#include "EntityInstance.hpp"
using namespace std;

void EntityInstance::addPair(Pair &pair){
    entityPairs.push_back(pair);
}

void EntityInstance::print(){
    for(auto pairs: entityPairs){
        pairs.print(5, false);
    }
}
