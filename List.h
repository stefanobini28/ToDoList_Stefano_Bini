//
// Created by Stefano on 02/02/2021.
//


#ifndef EXAMPLETXTTOLIST_LIST_H
#define EXAMPLETXTTOLIST_LIST_H

#pragma once
#include <iostream>
#include <list>
#include "ToDoItem.h"
#include "Date.h"
using namespace std;

class List {
public:
    ToDoItem Item;
    list<ToDoItem> ToDoList;
    List();
    ~List();
    //~list<ToDoItem> ToDoList;

    //void PushBack(string itemName, int day, int month, int year, string description, bool done);
    void Show_List();
    void Add_Element();
    bool Delete_Element(const string& deleteName);
    void ordered_insert(ToDoItem Item);

private:
    //ToDoItem Item;
};

#endif //EXAMPLETXTTOLIST_LIST_H
