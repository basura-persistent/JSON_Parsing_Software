
#include <queue>
#include "EntitySet.hpp"
#include "EntityInstance.hpp"

// EntitySet::EntitySet();

void EntitySet::addEntity(EntityInstance &entityInstance){
    instances.push(entityInstance);
}


void EntitySet::print(){
    cout<<"["<<endl;
    while(!instances.empty()){
        EntityInstance current_instance = instances.front();
        current_instance.print();
        instances.pop();
        if(instances.size() >= 1){
            cout<<","<<endl;
        }
    }
    cout<<endl;
    cout<<"]"<<endl;
}
