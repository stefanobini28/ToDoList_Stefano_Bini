//
// Created by Stefano on 13/02/2021.
//

#ifndef EXAMPLETXTTOMAP_DATE_H
#define EXAMPLETXTTOMAP_DATE_H

#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Date
{
public:
    Date();

    string printDate() const;
    static bool dateValidation(int Year, int Month, int Day);

    void setDay(int itemDay);
    void setMonth(int itemMonth);
    void setYear(int itemYear);

    bool setDate(int year, int month, int day);

private:
    int year;
    int month;
    int day;
};
#endif //EXAMPLETXTTOMAP_DATE_H
