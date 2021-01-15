#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include "List.h"
#include <sstream>
#include <algorithm>

using namespace std;

ListItem *item, *item2;
ListItem *start_ptr =nullptr;

int InputChoice(const std::string& action) {
    int choice;
    if (action=="list"){
        choice = 1;
    }
    else if (action=="add"){
        choice = 2;
    }
    else if (action=="remove") {
        choice = 3;
    }
    else if (action=="check") {
        choice = 4;
    }
    else if (action=="exit") {
        choice = 5;
    }
    else
        choice = 0;
    return choice;
}

int menu() {
    string action;
    int actionCase;
    cout << "\t Welcome to the ToDo List\n" << endl;
    std::cout<<""<<std::endl;
    std::cout<<"Digit  'list'   to see the complete list of Todo things"<<std::endl;
    std::cout<<"Digit  'add'    to insert a new event"<<std::endl;
    std::cout<<"Digit 'remove'  to remove an event from the list"<<std::endl;
    std::cout<<"Digit 'check'   to indicate as 'done/undone' a list event "<<std::endl;
    std::cout<<"Digit  'exit'   to end the program"<<std::endl;
    std::cin>>action;
    transform(action.begin(), action.end(), action.begin(), ::tolower); //convertire l'ingresso in lettere minuscole
    cout << endl;

    actionCase = InputChoice(action);
    return actionCase;
}

bool check_Item(const string& checkName){
    bool success= false;
    item=start_ptr;
    while(item != nullptr) {
        if(item->name==checkName){
            if(item->done=="UNDONE")
                item->done="DONE";
            else
                item->done="UNDONE";
            success=true;
            return success;
        }
        item=item->next;
    }
    return success;
}

bool dateValidation(int year, int month, int day) {
    int currMonthDays;
    if(year>=2021 && year<=9999) {
        if(month>=1 && month<=12) {
            if(month==4||month==6||month==9||month==11)
                currMonthDays=30;
            else if(month!=2)
                currMonthDays=31;
            else if((year%4==0 && year%100!=0)||year%400==0)
                currMonthDays=29;
            else
                currMonthDays=28;

            if(day>=1 && day<=currMonthDays) {
                return true;
            } else{
                std::cout<<"Wrong day value insert"<< std::endl;
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

void add_element () {
    bool validDate= false;
    int year=0, month=0, day=0;
    item= new ListItem;

    char nome[20];

    cout << "Enter name[max 20 caratteri]:";
    cin.ignore(256,'\n');
    cin.getline(nome,sizeof(nome));
    string complete_name(nome);
    item->name=complete_name;

    while(!validDate){
        cout << "Enter the day of this event:";
        cin >> day;//Node->day;
        cout << "Enter the month of this event:";
        cin >> month;//Node->month;
        cout << "Enter the year of this event:";
        cin >> year; //Node->year;
        validDate = dateValidation(year, month, day);
    }
    item->day = day;
    item->month = month;
    item->year = year;
    item->done="UNDONE";
    char desc[100];

    cout << "Enter description[max 100 caratteri]:";
    cin.ignore(256,'\n');
    cin.getline(desc,sizeof(desc));
    string phrase(desc);
    item->description=phrase;

    int i=1;
    if (start_ptr == nullptr) {
        start_ptr = item;
        //i=1;
        item->setIdentifier(i);
    }
    else {
        //i=1;
        item2 = start_ptr; // We know this is not NULL - list not empty!
        while(item2->next != nullptr) {
            item2 = item2->next;
            i++;
        }
        item->setIdentifier(i);
        item2->next= item;
        item->next=nullptr;
    }
}

bool delete_element(const string& deleteName) {
    bool success=false;
    if (start_ptr == nullptr)
        cout << "The list is empty!" << endl;
    else {
        item = start_ptr;
        if(item->next == nullptr){
            if (item->name==deleteName) {
                start_ptr = nullptr;
                delete item;
                success=true;
            }
        } else {   //la lista ha più di 2 elementi, partendo dall'inizio
            if (item->name == deleteName) {  //partiamo dal primo elemento della lista
                start_ptr = item->next;
                delete item;
                success=true;
                return success;
            }                    //altrimenti scorriamo tutti gli elementi a partire dal secondo
            item2=start_ptr;
            item=item->next;
            while (item != nullptr) {
                if (item->name == deleteName) {
                    item2->next = item->next; // Could be NULL
                    delete item;
                    success = true;
                    return success;
                } else{
                    item2 = item;
                    item = item->next;
                }
            }
        }
    }
    return success;
}

void show_list () {

    int counter=1;
    item=start_ptr;

    if (start_ptr == nullptr)
        cout << "The list is empty!" << endl;
    else {
        if(item->next == nullptr) {
            cout <<""<<counter<<") "<<item->name<<" | "<<item->day<<"/"<<item->month<<"/"<<item->year<<" | "<<item->done<<" | "<<item->description<<""<<endl;
        }
        else {
            cout << "Ecco la lista di tutto gli elementi inseriti:" << endl;
            cout << "" << endl;
            while (item != nullptr){
                cout <<""<<counter<<") "<<item->name<<" | "<<item->day<<"/"<<item->month<<"/"<<item->year<<" | "<<item->done<<" | "<<item->description<<""<<endl;
                item = item->next;
                counter++;
            }
            cout << "" << endl;
        }
    }
}

void WriteOnFile() {
    ListItem *FinalList;
    ofstream write_File;
    write_File.open("ToDoList.txt");

    FinalList=start_ptr;
    if (start_ptr != nullptr) {
        while(FinalList != nullptr){
            write_File << FinalList->name << " | ";
            write_File << FinalList->day << "  | ";
            write_File << FinalList->month << " | ";
            write_File << FinalList->year << " | ";
            write_File << FinalList->done << " | ";
            write_File << FinalList->description << endl;

            FinalList=FinalList->next;
        }
    }
    write_File.close();
}

vector<string> split_line(const string& str, const char& ch) {
    string next;
    vector<string> result;

    for (char it : str) {//for (const_iterator it = str.begin(); it != str.end(); it++)
        if (it == ch) {
            if (!next.empty()) {
                result.push_back(next);
                next.clear();
            }
        } else {
            next += it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}

void ReadFromFile() {
    ifstream file("ToDoList.txt");
    string input;//, item;

    while (getline(file, input)) {

        vector<string> ToDoItems = split_line(input, ' ');
        cout << "" << endl;
        for (auto & ToDoItem : ToDoItems) { //scorre ToDoItems Parola per parola
            cout <<  ToDoItem << " " ;
        }
        item=new ListItem;

        int index=0,n=0;
        string name,desc,s,space=" ";
        while(ToDoItems[index+n]!="|") {
            s=ToDoItems[index+n];
            name.append(s);
            name.append(space);
            n++;
        }
        name.pop_back();
        item->name = name;

        item->day = stoi(ToDoItems[n+1]);
        item->month = stoi(ToDoItems[n+3]);
        item->year = stoi(ToDoItems[n+5]);
        item->done = ToDoItems[n+7];

        index=n+9;
        n=0;
        while(index+n < ToDoItems.size()) {
            s=ToDoItems[index+n];
            desc.append(s);
            desc.append(space);
            n++;
        }
        desc.pop_back();
        item->description= desc;

        int id = 1;
        if (start_ptr == nullptr) {
            start_ptr = item;
            item->next=nullptr;
            item->setIdentifier(1);
        } else {
            item2 = start_ptr; // We know this is not NULL - list not empty!
            while (item2->next != nullptr) {
                item2 = item2->next;
                id++;
            }
            item->setIdentifier(id);
            item2->next = item;
            item->next = nullptr;
        }
    }
    cout<<""<<endl;
    file.close();
}

int main() {
    bool execute = true, success;
    string deleteName,checkname;
    char name[20];

    cout << "Welcome to To-Do list program!\n" << endl;
    cout << "Loading data from the external file...";

    ReadFromFile();
    do {
        system("pause");
        int action = menu();

        switch(action) {
            case 1:
                show_list();
                break;
            case 2:
                add_element();
                break;
            case 3:
                cout<<"Insert the name of the event you want to delete:"<<endl;
                cin.ignore(256,'\n');
                cin.getline(name,sizeof(name));
                deleteName=name;
                success=delete_element(deleteName);
                if(success)
                    cout<<"The element has been deleted successfully"<<endl;
                else
                    cout<<"can't found the element, please retry"<<endl;
                break;
            case 4:
                cout << "write here the name of the event you want to change [DONE <-> UNDONE]:" << endl;
                cin.ignore(256,'\n');
                cin.getline(name,sizeof(name));
                checkname=name;
                success=check_Item(checkname);
                if(success)
                    cout<<"The element has been changed successfully"<<endl;
                else
                    cout<<"can't found the element, please retry"<<endl;
                break;
            case 5:
                cout << "Have a nice day!" << endl;
                WriteOnFile();
                execute = false;
                break;
            default:
                cout << "Input was not recognized. Try again or "
                     << "\nenter 'exit' to end the program." << endl;
                execute = true;
        }
    } while (execute);
    return 0;
}