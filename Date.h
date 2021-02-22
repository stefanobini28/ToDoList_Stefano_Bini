//
// Created by Stefano on 13/02/2021.
//

#ifndef EXAMPLETXTTOMAP_DATE_H
#define EXAMPLETXTTOMAP_DATE_H

#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Date
{
public:
    Date();
    Date(int year, int month, int day);

    string printDate() const;
    static bool dateValidation(int Year, int Month, int Day);

    void setDay(int itemDay);
    int getDay() const;
    void setMonth(int itemMonth);
    int getMonth() const;
    void setYear(int itemYear);
    int getYear() const;

    bool setDate(int year, int month, int day);

    Date getDate() const;

private:
    int year;
    int month;
    int day;
};
#endif //EXAMPLETXTTOMAP_DATE_H
