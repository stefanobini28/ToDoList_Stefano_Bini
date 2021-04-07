//
// Created by Stefano on 13/02/2021.
//

#include "Date.h"

using namespace std;

Date::Date(int Year, int Month, int Day) {
    try {
        setDay(Year,Month,Day);
        setMonth(Year,Month);
        setYear(Year);
    }catch(exception &alert){
        throw logic_error(alert.what());
    }
}

string Date::printDate() const {
    string sdate;
    stringstream ss;
    ss << year << "/" << month << "/" << day;
    ss>> sdate;
    return sdate;
}

void Date::setDay(int itemYear, int itemMonth, int itemDay) {
    int currMonthDays;
    if(itemYear >= 2021 && itemYear <= 9999) {
        if (itemMonth >= 1 && itemMonth <= 12) {
            if (itemMonth == 4 || itemMonth == 6 || itemMonth == 9 || itemMonth == 11)
                currMonthDays = 30;
            else if (itemMonth != 2)
                currMonthDays = 31;
            else if ((itemYear % 4 == 0 && itemYear % 100 != 0) || itemYear % 400 == 0)
                currMonthDays = 29;
            else
                currMonthDays = 28;

            if (itemDay >= 1 && itemDay <= currMonthDays)
                day = itemDay;
            else
                throw invalid_argument("wrong day value");
        }
        else
           throw invalid_argument("wrong month value");
    }
    else
       throw invalid_argument("wrong year value");
}

void Date::setMonth(int itemYear, int itemMonth) {
    if(itemYear >= 2021 && itemYear <= 9999) {
        if (itemMonth >= 1 && itemMonth <= 12) {
            month = itemMonth;
        }
        else
          throw invalid_argument("wrong month value");
    }
    else
       throw invalid_argument("wrong year value");
}

void Date::setYear(int itemYear) {
    if(itemYear >= 2021 && itemYear <= 9999)
        year = itemYear;
    else
        throw invalid_argument("wrong year value");
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
                throw invalid_argument("Wrong day value insert");
            }
        } else {
            throw invalid_argument("Wrong month value insert");
        }
    } else {
        throw invalid_argument("Wrong year value insert");
    }
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}
