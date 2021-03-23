#ifndef ENTITYSET_HPP
#define ENTITYSET_HPP

#include <queue>

#include "EntityInstance.hpp"
class EntitySet{
    public:
        EntitySet();

        void addEntity(EntityInstance &);
        void print();

    private:
        queue<EntityInstance> instances;
};

#endif 