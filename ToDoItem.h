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
    ToDoItem(string itemName, string description, bool done);
    ~ToDoItem();

    string getName() const{
        return name;
    }

    string getDescription() const {
        return description;
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
