//
// Created by Stefano on 13/02/2021.
//

#include "Date.h"
#include <iostream>
#include <sstream>

using namespace std;

Date::Date()
{
    year = 2021;//default year value
    month = 1;//default month value
    day = 1;//default day value
}

Date::Date(int Year, int Month, int Day) {
    this->year = Year;
    this->month = Month;
    this->day = Day;

}
bool Date::dateValidation(int Year, int Month, int Day) {
    int currMonthDays;
    if (Year >= 2021 && Year <= 9999) {
        if (Month >= 1 && Month <= 12) {
            if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
                currMonthDays = 30;
            else if (Month != 2)
                currMonthDays = 31;
            else if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
                currMonthDays = 29;
            else
                currMonthDays = 28;

            if (Day >= 1 && Day <= currMonthDays) {
                return true;
            }else {
                std::cout << "Wrong day value insert" << std::endl;
                return false;
            }
        } else {
            std::cout << "Wrong month value insert" << std::endl;
            return false;
        }
    } else {
        std::cout << "Wrong year value insert" << std::endl;
        return false;
    }
}

string Date::printDate() const {
    string sdate;
    stringstream ss;
    ss << year << "/" << month << "/" << day ;
    ss>> sdate;
    return sdate;
}

void Date::setDay(int itemDay) {
    day = itemDay;
}

int Date::getDay() const {
    return day;
}
void Date::setMonth(int itemMonth) {
    month = itemMonth;
}

int Date::getMonth() const {
    return month;
}
void Date::setYear(int itemYear) {
    year = itemYear;
}

int Date::getYear() const {
    return year;
}

bool Date::setDate(int iyear, int imonth, int iday) {
    {
        bool validDate=Date::dateValidation(iyear,imonth,iday);
        if(!validDate){
            return false;
        } else {
            setYear(iyear);
            setMonth(imonth);
            setDay(iday);
            return true;
        }
    }
}

Date Date::getDate() const {
    return {getYear(), getMonth(),getDay()};
}
