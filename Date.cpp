//
// Created by betty on 13/02/2021.
//

#include "Date.h" //includes the Date header file
#include <iostream>

using namespace std;

//default constructor with default values
Date::Date()
{
    month = 1;//default month value
    day = 1;//default day value
    year = 2021;//default year value
}
//postcondition: a Date with a month, day and year has been created

//precondition: Date will check if any of the conditions have been violated

Date::Date(int Day, int Month, int Year) {
    this->month = Month;
    this->day = Day;
    this->year = Year;
}
bool Date::dateValidation(int Day, int Month, int Year) {
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

void Date::printdate() const {
    cout << day << "/" << month << "/" << year<<" ";
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


