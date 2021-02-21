//
// Created by Stefano on 02/02/2021.
//

#ifndef EXAMPLETXTTOMAP_MAP_H
#define EXAMPLETXTTOMAP_MAP_H

#pragma once
#include <iostream>
#include "ToDoItem.h"
#include "Date.h"
#include <map>
#include <algorithm>
#include<utility>
#include <vector>
using namespace std;

class Map {
public:
    Map();
    ToDoItem item;
    /*typedef multimap<int,ToDoItem> map;
    map todomap;
    */

    Date date;
    multimap</*Date*/int,ToDoItem>::iterator iterator;
    ~Map();

    void showMap() const ;
    bool addItem (/*const string& name, int day, int month, int year, const string& description, bool done*/) ;
    //bool setDate(int day,int month, int year);
    bool deleteElement(const string& deleteName);
    //void orderedInsert(const ToDoItem& Item);

private:
    multimap</*Date*/int,ToDoItem> todomap;
    //ToDoItem Item;
};

#endif //EXAMPLETXTTOMAP_MAP_H
