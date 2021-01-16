#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include "List.h"
#include <sstream>
#include <algorithm>

using namespace std;

ListItem *item, *item2, *item3;
ListItem *start_ptr = nullptr;

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

int ordered_insert(int day, int month, int year){
    int position=1;
    bool pos_found= false;
    if(start_ptr != nullptr){
        item3=start_ptr;
        while(item3 != nullptr && !pos_found) {
            if(item3->year < year){
                item3=item3->next;
                position++;
            } else if(item3->year == year){
                if(item3->month < month){
                    item3=item3->next;
                    position++;
                } else if(item3->month == month) {
                    if(item3->day <= day) {
                        item3 = item3->next;
                        position++;
                    } else
                        pos_found=true;
                } else
                    pos_found=true;
            } else
                pos_found=true;
        }
    }
    return position;
}

void add_element () {
    bool validDate= false;
    int year=0, month=0, day=0, position;
    item= new ListItem;

    char nome[20];

    cout << "Enter name[max 20 caratteri]:";
    cin.ignore(256,'\n');
    cin.getline(nome,sizeof(nome));
    string complete_name(nome);
    item->name=complete_name;

    while(!validDate){
        day=0,month=0,year=0;
        cout << "Enter the day of this event:";
        cin >> day;
        cout << "Enter the month of this event:";
        cin >> month;
        cout << "Enter the year of this event:";
        cin >> year;
        validDate = dateValidation(year, month, day);
    }
    item->day = day;
    item->month = month;
    item->year = year;

    item->done="UNDONE"; //inizializzazione (un evento inserito non è stato completato )

    char desc[100];
    cout << "Enter description[max 100 caratteri]:";
    cin.ignore(256,'\n');
    cin.getline(desc,sizeof(desc));
    string phrase(desc);
    item->description=phrase;

    position=ordered_insert(day,month,year);
    if (start_ptr == nullptr) {  //inserimento a lista vuota
        start_ptr = item;
        item->setIdentifier(1);
        item->next= nullptr;
    } else {
        item2 = start_ptr;
        if (position==1){
            start_ptr=item;
            item->next=item2;
        } else {
            int i = 1;
            while (i < position - 1) {
                item2 = item2->next;
                i++;
            }
            item->next = item2->next;
            item2->next = item;
            item->setIdentifier(position);

            item = item->next;
            while (item != nullptr) {
                position++;
                item->setIdentifier(position);
                item = item->next;
            }
        }
    }
}

bool delete_element(const string& deleteName) {
    bool success=false;
    if (start_ptr == nullptr)    //lista vuota, impossibile eliminare
        cout << "The list is empty!" << endl;
    else {
        item = start_ptr;
        if(item->next == nullptr){     //lista con un solo elemento
            if (item->name==deleteName) {
                start_ptr = nullptr;
                delete item;
                success=true;
            }
        } else {   //la lista ha almeno di 2 elementi, partendo dall'inizio
            if (item->name == deleteName) {  //partiamo dal primo elemento della lista
                start_ptr = item->next;
                delete item;
                success=true;
                return success;
            }                    //altrimenti scorriamo tutti gli elementi a partire dal secondo
            item2=start_ptr;  //(per inizializzare il secondo puntatore occorre questa sezione)
            item=item->next;

            while (item != nullptr) {
                if (item->name == deleteName) {
                    item2->next = item->next; // può anche essere NULL
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

    if (file.fail()) {
        cout << "Unable to open the file!!" << endl;
    } else if (file.eof()) {
        cout << "File is empty" << endl;
        cout << "Note that program will halt" << endl; // error prompt
    } else {
        string input;
        cout << "" << endl;
        while (getline(file, input)) {       // prelevo dal file una riga alla volta per poterla elaborare
            vector<string> ToDoItems = split_line(input, ' '); //divido la riga in ogni singola parola che la compone
            item = new ListItem;

            int index = 0, n = 0;
            string name, desc, component, space = " ";
            while (ToDoItems[index + n] != "|") {            //la prima parte di ogni riga contiene il nome (composto da 1 o piu parole) dell'evento
                component = ToDoItems[index + n];
                name.append(component);
                name.append(space);
                n++;
            }
            name.pop_back();
            item->name = name;

            item->day = stoi(ToDoItems[n + 1]);    // gli indici pari sono saltati poiche contengono solo caratteri di divisione ( "|" )
            item->month = stoi(ToDoItems[n + 3]);
            item->year = stoi(ToDoItems[n + 5]);
            item->done = ToDoItems[n + 7];

            index = n + 9;
            n = 0;
            while (index + n < ToDoItems.size()) {  //le ultime righe contengono la descrizione dell'evento
                component = ToDoItems[index + n];
                desc.append(component);
                desc.append(space);
                n++;
            }
            desc.pop_back();
            item->description = desc;

            int id = 1;
            if (start_ptr == nullptr) {   //controllo se la lista in memoria è vuota
                start_ptr = item;
                item->next = nullptr;
                item->setIdentifier(1);
            } else {
                item2 = start_ptr;        // sappiamo ora che non è sicuramente NULL - lista non vuota
                while (item2->next != nullptr) {
                    item2 = item2->next;
                    id++;
                }
                item->setIdentifier(id+1);          //inserimento in fondo alla lista
                item2->next = item;
                item->next = nullptr;
            }
        }
    }
    cout<<""<<endl;
    file.close();
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
