#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "ToDoItem.h"
#include <sstream>
#include <algorithm>
#include <limits>
#include "Map.h"

using namespace std;

void addItem(Map newMap) {
    bool validDate = false;
    int year = 0, month = 0, day = 0;
    string name,description;
    char nome[20];


        cout << "Enter name[max 20 caratteri]:";
        cin.ignore(256, '\n');
        cin.getline(nome, sizeof(nome) + 1);
        string completeName(nome);
        name = completeName;

        /*cin.clear();
        cin.ignore(256, '\n');*/

    while (!validDate) {
        year = 0, month = 0, day = 0;
        cout << "Enter the day of this event:";
        cin >> day;
        while (true) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You have entered wrong input format,please retry:" << endl;
                cin >> day;
            }
            if (!cin.fail())
                break;
        }
        cout << "Enter the month of this event:";
        cin >> month;
        while (true) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You have entered wrong input format,please retry:" << endl;
                cin >> month;
            }
            if (!cin.fail())
                break;
        }
        cout << "Enter the year of this event:";
        cin >> year;
        while (true) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You have entered wrong input format,please retry:" << endl;
                cin >> year;
            }
            if (!cin.fail())
                break;
        }
        validDate=Date::dateValidation(day,month,year);
    }
    char desc[100];
    cout << "Enter description[max 100 caratteri]:";
    cin.ignore(256, '\n');
    cin.getline(desc, sizeof(desc) + 1);
    string descr(desc);
    description = descr;

    bool result=newMap.addItem(/*name,day,month,year,description,false*/);
    if(result){
        cout<<"yeyy";
    }
}

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
    cout << "\t Welcome to the ToDo List" << endl;
    std::cout<<" "<<std::endl;
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

int main() {
    bool execute = true, success;
    string deleteName, checkname;
    char name[20];

    cout << "Welcome to To-Do list program!\n" << endl;
    cout << "Loading data from the external file..."<< endl;
    //ReadFromFile();

    Map newMap;

    do {
        system("pause");
        int action = menu();

        switch (action) {
            case 1:
                newMap.showMap();
                //Map::showMap() const;
                break;
            case 2:
                addItem(newMap);
                break;
            case 3:
                cout << "Insert the name of the event you want to delete:" << endl;
                cin.ignore(256, '\n');
                cin.getline(name, sizeof(name));
                deleteName = name;
                //success=todomap->deleteElement(deleteName);
                //success=todomap.deleteElement(deleteName);
                if (success)
                    cout << "The element has been deleted successfully" << endl;
                else
                    cout << "can't found the element, please retry" << endl;
                break;
            case 4:
                cout << "write here the name of the event you want to change [DONE <-> UNDONE]:" << endl;
                cin.ignore(256, '\n');
                cin.getline(name, sizeof(name));
                checkname = name;
                //success=ToDoList->Check_Item(checkname);
                if (success)
                    cout << "The element has been changed successfully" << endl;
                else
                    cout << "can't found the element, please retry" << endl;
                break;
            case 5:
                cout << "Have a nice day!" << endl;
                //WriteOnFile();
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
