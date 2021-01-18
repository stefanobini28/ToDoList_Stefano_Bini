//
// Created by stefano on 08/01/2021.
//

#ifndef EXAMPLETXTTOLIST_LIST_H
#define EXAMPLETXTTOLIST_LIST_H

#include<list>
using namespace std;
class ListItem{
public:
    ListItem();
    ListItem(string itemName, int day, int month, int year, string description, string done, ListItem *next,
             int identifier);
    ~ListItem();
    string name;
    int day, month, year;
    string description;
    string done;

    ListItem *next;

    void setIdentifier(int i) {
        identifier = i;
    }
    int getIdentifier() const {
        return identifier;
    }
private:
    int identifier;
};

#endif //EXAMPLETXTTOLIST_LIST_H
