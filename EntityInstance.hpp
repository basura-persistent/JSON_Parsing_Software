#ifndef ENTITY_INSTANCEHPP
#define ENTITY_INSTANCEHPP


#include "iostream"
#include <string>
#include <vector>
#include <queue>
#include "Pair.hpp"

class EntityInstance {
    public:
        void addPair(Pair &pair);
        int numAttributes();
        vector<string> attributeNames;
        void insertComa(bool isComa);
        
        void print();

        double gpa();
        string ID();
        string Term();

    private:
        vector<Pair> entityPairs;
         queue<bool> addComa;
     //add local variable to locally scan pair gpa value 

};

#endif 