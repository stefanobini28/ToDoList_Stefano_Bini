//
// Created by Stefano on 08/01/2021.
//

#ifndef EXAMPLETXTTOMAP_TODOITEM_H
#define EXAMPLETXTTOMAP_TODOITEM_H

#pragma once
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class ToDoItem{
public:
    ToDoItem();
    ToDoItem(string itemName, string description, bool done);
    ~ToDoItem();

    void setName(string itemName) {
        name= std::move(itemName);
    }
    string getName() const{
        return name;
    }
    void setDescription(string itemDescription) {
        description= std::move(itemDescription);
    }
    string getDescription() const {
        return description;
    }
    void setItemDone(bool itemDone){
        done= itemDone;
    }
    bool getItemDone() const {
        return done;
    }
    friend ostream &operator<<(ostream &ostr, const ToDoItem &);

private:
    string name;
    string description;
    bool done;
};

#endif //EXAMPLETXTTOMAP_TODOITEM_H
