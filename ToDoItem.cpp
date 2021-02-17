//
// Created by Stefano on 08/01/2021.
//

#include <iostream>
#include "ToDoItem.h"
using namespace std;


ToDoItem::ToDoItem():date(0,0,0),done(false) {}

ToDoItem::ToDoItem(string itemName, Date ddate, string description, bool done)
        :name(std::move(itemName)),
         date (ddate),
         description(std::move(description)),
         done(false){}

bool ToDoItem::setDate(int day, int month, int year) {
    {
        bool validDate=date.dateValidation(day,month,year);
        if(!validDate){
            return false;
        } else {
            date.setDay(day);
            date.setMonth(month);
            date.setYear(year);
            return true;
        }
    }
}

Date ToDoItem::getDate() const {
    this->date.printdate();
        return date;
}

ostream &operator<<(ostream &ostr, const ToDoItem & ToDoItem) {

    cout<< ToDoItem.name <<" ";
    /*cout<<*/ ToDoItem.getDate() /*<<" "*/;
    cout<< ToDoItem.description <<" ";
    cout<< ToDoItem.done <<" ";

    return ostr;
}

/*ToDoItem::ToDoItem():day(0),month(0),year(0),done(false) {}

ToDoItem::ToDoItem(string itemName, int day, int month, int year, string description, bool done)
        :name(std::move(itemName)),
         day(day),
         month(month),
         year(year),
         description(std::move(description)),
         done(false){}*/

ToDoItem::~ToDoItem()=default;