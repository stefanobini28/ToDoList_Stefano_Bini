//
// Created by Stefano on 08/01/2021.
//

#ifndef EXAMPLETXTTOLIST_TODOITEM_H
#define EXAMPLETXTTOLIST_TODOITEM_H

#pragma once
#include "Date.h"
#include <utility>
using namespace std;
class ToDoItem{
public:
    ToDoItem();
    //ToDoItem(string itemName, int day, int month, int year, string description, bool done);
    ToDoItem(string itemName, Date date, string description, bool done);
    ~ToDoItem();

    Date date;

    void setName(string itemName) {
        name= std::move(itemName);
    }
    string getName(){
        return name;
    }
    void setdDescription(string itemDescription) {
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
    bool setDate(int day, int month,int year);

    Date getDate() const;

    friend ostream &operator<<(ostream &ostr, const ToDoItem &);

private:
    string name;
    //int day, month, year;
    string description;
    bool done;
};

#endif //EXAMPLETXTTOLIST_TODOITEM_H
