//
// Created by Stefano on 02/02/2021.
//

#ifndef EXAMPLETXTTOMAP_MAP_H
#define EXAMPLETXTTOMAP_MAP_H

#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <fstream>
#include <string>
#include <vector>
#include "ToDoItem.h"
#include "Date.h"

using namespace std;

class Map {
public:
    Map();
    ~Map();

    ToDoItem item;
    Date date;

    void showMap() const ;
    void addItem (const string& name, int day, int month, int year, const string& description, bool done);
    bool deleteElement(const string &deleteName);
    bool checkItem(const string& checkName);

    void writeOnFile() const;
    void readFromFile();

private:
    multimap<string,ToDoItem> todomap;
    multimap<string,ToDoItem>::iterator iterator;
};

#endif //EXAMPLETXTTOMAP_MAP_H

