#ifndef ENTITYSET_HPP
#define ENTITYSET_HPP

#include <deque>
#include <vector>
#include "EntityInstance.hpp"
class EntitySet{
    public:
        EntitySet();

        void addEntity(EntityInstance &);
        void print();
        deque<EntityInstance> getInstances(){return instances;}
        //function that returns queue of instances
        void commonElements(EntitySet &entity);
        void arrayPrint();
        void inputArrayGenerator();

        

    private:
        deque<EntityInstance> instances;
        bool isMember(EntityInstance &other);
        EntityInstance instanceWithID(string ID);
        void deleteInstanceWithID(string ID);
        vector<pair<EntityInstance,EntityInstance> > commonElementsVector;
        int outputGPAMatrix[8][8];
        int getGpaBand(double gpa);



};

#endif 