
#include <deque>
#include <utility>
#include "EntitySet.hpp"
#include "EntityInstance.hpp"

EntitySet::EntitySet(){
    for(auto subArray: outputGPAMatrix){
        for(int i = 0; i<8; i++){
            subArray[i] = 0;
        }
    }
};

void EntitySet::addEntity(EntityInstance &entityInstance){
    instances.push_back(entityInstance);
}


void EntitySet::print(){
    cout<<"["<<endl;
    while(!instances.empty()){
        EntityInstance current_instance = instances.front();
        current_instance.print();
        instances.pop_front();
        if(instances.size() >= 1){
            cout<<","<<endl;
        }
    }
    cout<<endl;
    cout<<"]"<<endl;
}

bool EntitySet::isMember(EntityInstance &other){
    for(auto instance: instances){
        if(other.ID() == instance.ID()){
            return true;
        }
    }
    return false;
}

EntityInstance EntitySet::instanceWithID(string ID){
    EntityInstance instance1;
    int count = 0;
    for(auto instance: instances){
        EntityInstance instance1 = instance;
        if(instance.ID() == ID){
            // cout<<"inputting these ID's"<<instance.ID()<<"    "<<ID<<endl;
            instances.erase(instances.begin()+count);
            return instance1;
        }
        count++;
    }
    return instance1;
}

// void EntitySet::deleteInstanceWithID(string ID){
//     for(int i = 0; i < instances.size(); i++){
//         EntityInstance instance1 = instances[i];
//         if(instance1.ID() == ID){
//             instances.erase(instances.begin()+i);
//             break;
//     }
// }
// }

void EntitySet::commonElements(EntitySet &entity){
    pair<EntityInstance, EntityInstance> InstancePairs;
    for(auto instance: instances){
        // cout<<"looping"<<endl;
        if(entity.isMember(instance)){
            EntityInstance otherInst = entity.instanceWithID(instance.ID());
            InstancePairs = make_pair(instance, otherInst);
            // cout<<"Pushing back a pair"<<endl;
            commonElementsVector.push_back(InstancePairs);
            // entity.deleteInstanceWithID(instance.ID());

        }
        // inputArrayGenerator();
        // arrayPrint();
    }
    inputArrayGenerator();
    arrayPrint();
}

void EntitySet::arrayPrint(){
    cout<<"["<<endl;
    int count = 0;
    for(auto subArray: outputGPAMatrix){
        cout<<"   [";
        for(int j = 0; j <  8; j++){
            cout<<subArray[j];
            if(j < 7 ){
                cout<<",  ";
            }
        }
        count++;
        cout<<"]";
        if(count <= 7){
            cout<<","<<endl;
        }
        else{
            cout<<endl;
        }
    }
    cout<<"]"<<endl;

}

void EntitySet::inputArrayGenerator(){
    int row = 0;
    int column = 0;
    for(auto commonElement: commonElementsVector){
        row = getGpaBand(commonElement.second.gpa());
        column = getGpaBand(commonElement.first.gpa());
        outputGPAMatrix[row][column]++;
        
    }
}

int EntitySet::getGpaBand(double gpa){
                if(gpa > 3.67){
                    return 0;
                }
                else if(gpa > 3.3){
                    return 1;
                }
                else if(gpa > 3.0){
                    return 2;
                }
                else if(gpa > 2.67){
                    return 3;
                }
                else if(gpa > 2.3){
                    return 4;
                }
                else if(gpa > 2.0){
                    return 5;
                }
                else if(gpa > 1.67){
                    return 6;
                }
                else if(gpa >= 0.0){
                    return 7;
                }
               return 0;
}







