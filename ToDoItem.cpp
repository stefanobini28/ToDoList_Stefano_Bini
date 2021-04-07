//
// Created by Stefano on 08/01/2021.
//

#include "ToDoItem.h"
using namespace std;

ToDoItem::ToDoItem(string itemName, string description, bool done)
        :name(std::move(itemName)),
         description(std::move(description)),
         done(done){}

ostream &operator<<(ostream &ostr, const ToDoItem & ToDoItem) {

    cout<< ToDoItem.name <<" ";
    cout<< ToDoItem.description <<" ";
    cout<< ToDoItem.done <<" ";

    return ostr;
}

ToDoItem::~ToDoItem()=default;
