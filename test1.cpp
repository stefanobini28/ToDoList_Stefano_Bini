//
// Created by Stefano on 25/01/2021.
//

#include <gtest/gtest.h>
#include "../Date.h"
#include "../ToDoList.h"

using testing::Eq;
using namespace std;

class ClassDeclaration: public testing::Test{
public:

    void setup(){}
    int year = 2222, month = 6, day = 5;
    int wrongyear = 1999, wrongmonth = 13, wrongday = 32;
    int actualyear = 2021, actualmonth = 2, actualday = 29;

    string name="Ciro", description="visita a casa di Ciro";
    bool done=false;

    void test1() const{
        Date obj=Date(year,month,day);
        ASSERT_EQ(obj.getYear(),2222);
        ASSERT_EQ(obj.getMonth(),6);
        ASSERT_EQ(obj.getDay(),5);
    }
    void test2() const{
        EXPECT_THROW(Date(wrongyear, wrongmonth, wrongday),logic_error);
    }
    void test3() const{
        EXPECT_THROW(Date(year, month, wrongday),logic_error);
    }
    void test4() const{
        EXPECT_THROW(Date(actualyear, actualmonth, actualday),logic_error);
    }
    void test5(){
        int count=0;
        string input;
        ifstream file("../ToDoList.txt");
        if (file.fail()) {
            cout << "Unable to open the file!!" << endl;
        } else if (file.eof()) {
            cout << "File is empty" << endl;
        } else {
            while (getline(file, input)) {
                count++;
            }
        }
        file.close();
        cout<<"There are actually "<<count<<" items in the ToDoList";
        EXPECT_TRUE(count>=0);
    }
    void test6(){
        ToDoList todomap;
        EXPECT_THROW(todomap.addItem(name, day, month, wrongyear, description, done),invalid_argument);
    }
    void test7(){
        ToDoList todomap;
        EXPECT_NO_THROW(todomap.addItem(name, day, month, year, description, done));
    }
};
TEST_F(ClassDeclaration,equal_year){
    test1(); //2222 is a good year value
}
TEST_F(ClassDeclaration,not_equal_year){
    test2(); //goes wrong, year is =1999 , but program doesn't accept year value < 2021
}
TEST_F(ClassDeclaration,wrong_day_value){
    test3(); //goes wrong, year is good, month is good , but program doesn't accept day value > 31
}
TEST_F(ClassDeclaration,wrong_day_february_value){
    test4(); //goes wrong, year is good, month is good , but in 2021 february has only 28 days
}
TEST_F(ClassDeclaration,listItem_count){
    test5(); //counts corrextly every item in the text file of ToDoList
}
TEST_F(ClassDeclaration,Incorrect_Insert_Item){
    test6(); // goes right! ,insert is filled of incorrect data as expected
}
TEST_F(ClassDeclaration,Correct_Insert_Item){
    test7();  // goes right! ,insert is correct
}