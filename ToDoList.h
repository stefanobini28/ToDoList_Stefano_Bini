//
// Created by Stefano on 02/02/2021.
//

#ifndef EXAMPLETXTTOMAP_TODOLIST_H
#define EXAMPLETXTTOMAP_TODOLIST_H

#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <exception>
#include "ToDoItem.h"
#include "Date.h"

using namespace std;

class ToDoList {
public:

    string showMap() const;
    void addItem (const string& name, int day, int month, int year, const string& description, bool done);
    bool deleteElement(const string &deleteName);
    bool checkItem(const string& checkName);

    void writeOnFile() const;
    void readFromFile();

private:
    multimap<string,ToDoItem> todomap;
};

#endif //EXAMPLETXTTOMAP_TODOLIST_H
