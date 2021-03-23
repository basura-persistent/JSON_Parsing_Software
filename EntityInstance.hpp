#ifndef ENTITY_INSTANCEHPP
#define ENTITY_INSTANCEHPP


#include "iostream"
#include <string>
#include <vector>
#include "Pair.hpp"

class EntityInstance {
    public:
        void addPair(Pair &pair);
        int numAttributes();
        vector<string> attributeNames;

        void print();

        double gpa();

    private:
        vector<Pair> entityPairs;




};

#endif 