//
// Created by Stefano on 02/02/2021.
//

#include <string>
#include "Map.h"

using namespace std;

Map::Map() = default;

Map::~Map() = default;

void Map::showMap() const {
    if(todomap.empty()){
            cout<<"sorry, list is actually empty"<<endl;
    }else{
    int num=1;
        cout<<"List elements are the following:"<<endl;
        for(const auto & it : todomap) {
            cout << num << ") " << it.first/*.printDate() */<< "" << it.second << endl;
            num++;
        }
    }
}

bool Map::addItem(){//const string& name,int day,int month, int year, const string& description, bool done) {

    /*bool go=date.setDate(day,month,year);
    if (go){
        item.setName(name);
        item.setDescription(description);
        item.setItemDone(done);
    //orderedInsert(item);
    }*/
    
    if (todomap.empty()) {
        iterator = todomap.insert(pair<int, ToDoItem>{1, ToDoItem{"stefano", "ciao", static_cast<bool>("false")}});
    } else{
        todomap.insert(iterator,pair<int, ToDoItem>{2, ToDoItem{"stefano2", "ciao2", static_cast<bool>("false")}});
    }
    return true;
}

bool Map::deleteElement(const string& deleteName) {
    bool success = false;
    if (todomap.empty()) {
        cout << "The list is empty!" << endl;
    } else {
        for (auto it = todomap.begin(); it != todomap.end(); it++) {
            if((*it).second.getName()/*getName()*/ == deleteName){
                todomap.erase(it);
                success = true;
                return success;
            }
        }
    }
    return success;
}
