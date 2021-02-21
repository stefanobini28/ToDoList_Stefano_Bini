//
// Created by Stefano on 08/01/2021.
//

#include <iostream>
#include "ToDoItem.h"
using namespace std;


ToDoItem::ToDoItem():done(false) {}

ToDoItem::ToDoItem(string itemName, /*Date ddate,*/ string description, bool done)
        :name(std::move(itemName)),
         //date (ddate),
         description(std::move(description)),
         done(false){}

ostream &operator<<(ostream &ostr, const ToDoItem & ToDoItem) {

    cout<< ToDoItem.name <<" ";
    //cout<< ToDoItem.date.printDate() <<" ";
    cout<< ToDoItem.description <<" ";
    cout<< ToDoItem.done <<" ";

    return ostr;
}

ToDoItem::~ToDoItem()=default;
