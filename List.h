//
// Created by betty on 07/01/2021.
//

#ifndef EXAMPLETXTTOLIST_LIST_H
#define EXAMPLETXTTOLIST_LIST_H

#include<list>
using namespace std;
//#include "global.h"
//#include "edgelist.h"
//struct ListNode {
class ListItem{
public:
    ListItem();
    ListItem(string itemName, int day, int month, int year, string description, string done, ListItem *next);
    ~ListItem();
    string name;
    //int date [3] {day, month, year};
    int day, month, year;
    string description;
    string done;

    ListItem *next;

// Setter
    void setIdentifier(int i) {
        identifier = i;
    }
    // Getter
    int getIdentifier() const {
        return identifier;
    }
private:
    int identifier{};
};

#endif //EXAMPLETXTTOLIST_LIST_H
