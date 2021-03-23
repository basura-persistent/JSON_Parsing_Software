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

    private:
        vector<Pair> entityPairs;
         queue<bool> addComa;



};

#endif 