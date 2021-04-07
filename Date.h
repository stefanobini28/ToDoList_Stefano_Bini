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
#include <stdexcept>
#include <sstream>
#include <exception>

using namespace std;

class Date
{
public:
    Date(int Year, int Month, int Day);

    string printDate() const;
    static bool dateValidation(int Year, int Month, int Day);

    void setDay(int itemYear, int itemMonth, int itemDay);
    void setMonth(int itemYear, int itemMonth);
    void setYear(int itemYear);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

private:
    int year{};
    int month{};
    int day{};
};
#endif //EXAMPLETXTTOMAP_DATE_H
