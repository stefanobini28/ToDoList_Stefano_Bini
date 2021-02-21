//
// Created by Stefano on 08/01/2021.
//

#ifndef EXAMPLETXTTOMAP_TODOITEM_H
#define EXAMPLETXTTOMAP_TODOITEM_H

#pragma once
//#include "Date.h"
#include <utility>
#include <vector>
using namespace std;
class ToDoItem{
public:
    ToDoItem();
    //ToDoItem(string itemName, int day, int month, int year, string description, bool done);
    ToDoItem(string itemName, /*Date date,*/ string description, bool done);
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
    void setItemDone(bool itemDone) {
        done= itemDone;
    }
    bool getItemDone() const {
        return done;
    }
    //bool setDate(int day, int month,int year);

    //Date getDate() const;

    //void showDate() const;

    friend ostream &operator<<(ostream &ostr, const ToDoItem &);

private:
    string name;
    //Date date;
    string description;
    bool done;
};

#endif //EXAMPLETXTTOLMAP_TODOITEM_H
