//
// Created by betty on 13/02/2021.
//

#ifndef EXAMPLETXTTOMAP_DATE_H
#define EXAMPLETXTTOMAP_DATE_H

#include <algorithm>
#include <string>
#include<utility>
#include <vector>
using namespace std;

class Date
{
public:
    Date();
    Date(int day, int month, int year);

    string printDate() const;
    static bool dateValidation(int Day, int Month, int Year);

    void setDay(int itemDay);
    int getDay() const;
    void setMonth(int itemMonth);
    int getMonth() const;
    void setYear(int itemYear);
    int getYear() const;

    bool setDate(int day, int month, int year);

    Date getDate() const;

private:
    int month;
    int day;
    int year;
};

#endif //EXAMPLETXTTOMAP_DATE_H
