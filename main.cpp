#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include "ToDoList.h"

#if defined(_WIN32)
    #define PAUSE "pause"
#elif defined(unix) || defined (__unix__) || defined(__unix)
    #define PAUSE "read -p 'Press Enter to Continue...' var"
#endif

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
    std::cout<<"Digit 'check'   to set as 'done/undone' a list event from opposite (undone/done) "<<std::endl;
    std::cout<<"Digit  'exit'   to end the program"<<std::endl;
    std::cin>>action;
    transform(action.begin(), action.end(), action.begin(), ::tolower); //converte l'ingresso in lettere minuscole
    cout << endl;

    actionCase = InputChoice(action);
    return actionCase;
}

int main() {
    int year = 0, month = 0, day = 0;
    char nome[20], desc[100];
    bool execute = true, success, validDate;
    string name, deleteName, checkName, description;
    ToDoList newMap;

    cout << "Welcome to To-Do list program!" << endl;
    cout << "Loading data from the external file..."<< endl;
    newMap.readFromFile();  //lettura da file di testo della lista salvata in precedenza

    do {
        system(PAUSE);
        int action = menu();
        cin.ignore(256, '\n');

        switch (action) {
            case 1:
                newMap.showMap(); //mostra la lista aggiornata degli eventi
                break;
            case 2:
                validDate = false;
                cout << "Enter name[max 20 characters]:";
                cin.getline(nome, sizeof(nome) + 1);
                name = nome;

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
                            cin >> day;
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
                            cin >> day;
                        }
                        if (!cin.fail())
                            break;
                    }
                    try {
                        validDate = Date::dateValidation(year, month, day);
                    }catch (exception & alert){
                        cerr << alert.what() << endl;
                    };
                }
                cout << "Enter description[max 100 characters]:";
                cin.ignore(256, '\n');
                cin.getline(desc, sizeof(desc) + 1);
                description = desc;
                newMap.addItem(name,day,month,year,description,false); //aggiunta di un elemento d parte dell'utente
                break;
            case 3:{
                cout << "Insert the name of the event you want to delete:" << endl;
                do {
                    cin.getline(nome, sizeof(nome) + 1);
                    deleteName = nome;
                    success = newMap.deleteElement(deleteName);//rimuovere un evento dalla lista
                    if(deleteName == "back")
                        break;
                    if (success){
                        cout << "The element has been deleted successfully" << endl;
                    } else {
                        cout << "can't find the element, please retry or digit 'back' to go to the main menu" << endl;
                    }
                } while (!success);
                break;
            }
            case 4: {
                cout << "write here the name of the event you want to change [DONE <-> UNDONE]:" << endl;
                do {
                    cin.getline(nome, sizeof(nome) + 1);
                    checkName = nome;
                    if(checkName == "back")
                        break;
                    success = newMap.checkItem(checkName);  //contrassegnare un evento della todolist come fatto/non fatto
                    if (success) {
                        cout << "The element has been changed successfully" << endl;
                    } else {
                        cout << "can't find the element, please retry or digit 'back' to go to the main menu" << endl;
                    }
                } while (!success);
                break;
            }
            case 5:
                cout << "Have a nice day!" << endl;
                newMap.writeOnFile();   //scrittura sul file di testo della lista aggiornata
                execute = false;
                break;
            default:
                cout << "Input was not recognized. Try again or "
                     << "\nenter 'exit' to end the program." << endl;
                execute = true;
                break;
        }
    } while (execute);
    return 0;
}
