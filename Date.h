//
// Created by betty on 13/02/2021.
//

#ifndef EXAMPLETXTTOLIST_DATE_H
#define EXAMPLETXTTOLIST_DATE_H

class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int day, int month, int year);

    void printdate() const;
    static bool dateValidation(int Day, int Month, int Year);

    void setDay(int itemDay);
    int getDay() const;
    void setMonth(int itemMonth);
    int getMonth() const;
    void setYear(int itemYear);
    int getYear() const;

};

#endif //EXAMPLETXTTOLIST_DATE_H
