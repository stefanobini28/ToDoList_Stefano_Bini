#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include "ToDoItem.h"
#include <sstream>
#include <algorithm>
#include <limits>
#include "List.h"

using namespace std;

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
    //List list <ToDoItem> ToDoList ;
    List *ToDoList= new List();
    do {
        system("pause");
        int action = menu();

        switch (action) {
            case 1:
                ToDoList->Show_List();
                break;
            case 2:
                ToDoList->Add_Element();
                break;
            case 3:
                cout << "Insert the name of the event you want to delete:" << endl;
                cin.ignore(256, '\n');
                cin.getline(name, sizeof(name));
                deleteName = name;
                success=ToDoList->Delete_Element(deleteName);
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
