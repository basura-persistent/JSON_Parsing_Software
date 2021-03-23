#ifndef ENTITYSET_HPP
#define ENTITYSET_HPP


#include "EntityInstance.hpp"
class EntitySet{
    public:
        EntitySet();

        void addEntity(EntityInstance &);
        void print();

    private:
        vector<EntityInstance> instances;
};

#endif 