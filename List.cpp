//
// Created by betty on 08/01/2021.
//

#include <iostream>
#include "List.h"
using namespace std;

ListItem::ListItem():next(nullptr),day(0),month(0),year(0), identifier(1){}

ListItem::ListItem(string itemName, int day, int month, int year, string description, string done, ListItem *next)
            : name(std::move(itemName)), day(day), month(month), year(year), description(std::move(description)),
              done(std::move(done)),next(next) {}

ListItem::~ListItem()=default;