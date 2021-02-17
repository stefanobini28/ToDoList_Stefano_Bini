//
// Created by Stefano on 02/02/2021.
//

#include <string>
//#include <utility>
#include "List.h"
#include <list>
#include <limits>
using namespace std;

List::List() = default;

List::~List() = default;

list <ToDoItem> ToDoList;

void List::Show_List() {
    if(ToDoList.empty()){
        cout<<"sorry, list is actually empty"<<endl;
    }else{
    int num=1;
        /*for(auto it=ToDoList.begin(); it!=ToDoList.end();it++){*/
        cout<<"List elements are the following:"<<endl;
        for(const auto& it:ToDoList) {
            cout << num << ") " << it << endl;
            num++;
        }
    }
}

void List::Add_Element() {
    bool validDate= false;
    int year=0, month=0, day=0, position;
    //Item = new ToDoItem;

    char nome[20];

    cout << "Enter name[max 20 caratteri]:";
    cin.ignore(256,'\n');
    cin.getline(nome, sizeof(nome)+1);
    string complete_name(nome);
    //item->name=complete_name;

    cin.clear();
    cin.ignore(256,'\n');
    while(!validDate){
        day=0,month=0,year=0;

        cout << "Enter the day of this event:";
        cin >> day;
        while(true)
        {
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"You have entered wrong input format"<<endl;
                cin>>day;
            }
            if(!cin.fail())
                break;
        }

        cout << "Enter the month of this event:";
        cin >> month;
        while(true)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"You have entered wrong input format"<<endl;
                cin>>month;
            }
            if(!cin.fail())
                break;
        }

        cout << "Enter the year of this event:";
        cin >> year;
        while(true)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"You have entered wrong input format"<<endl;
                cin>>year;
            }
            if(!cin.fail())
                break;
        }
        validDate = Item.setDate(day,month,year);
    }

    //item->done="UNDONE"; //inizializzazione (un evento inserito non è stato completato )
    bool done = false;

    char desc[100];
    cout << "Enter description[max 100 caratteri]:";
    cin.ignore(256,'\n');
    cin.getline(desc,sizeof(desc)+1);
    string phrase(desc);
    //item->description=phrase;

    //position=ordered_insert(day,month,year); //Not now

    //Item=(complete_name,day,month,year,phrase,done);

    Item.setName(complete_name);
    //Item.setDate(day,month,year);
    Item.setdDescription(phrase);
    Item.setItemDone(done);

    //ordered_insert(Item);
    ToDoList.push_back(Item);
}

bool List::Delete_Element(const string& deleteName) {
    bool success = false;
    if (ToDoList.empty()) {
        cout << "The list is empty!" << endl;
    } else {
        for (auto it = ToDoList.begin(); it != ToDoList.end(); it++) {
            if((*it).getName() == deleteName){
                ToDoList.erase(it);
                success = true;
                return success;
            }
        }
    }
    return success;
}

void List::ordered_insert(ToDoItem Item) {
    Date date = Item.getDate();
    int day = date.getDay();
    int month = date.getMonth();
    int year = date.getYear();

    for (auto it = ToDoList.begin(); it != ToDoList.end(); it++) {
        Date current_date = (*it).getDate();
        int current_day = current_date.getDay();
        int current_month = current_date.getMonth();
        int current_year = current_date.getYear();

        if (current_year > year) {
            ToDoList.insert(it,Item);
            exit;
            break;
        } else if (current_year == year && current_month > month){
            ToDoList.insert(it,Item);
            exit;
            break;
        } else if (current_year == year && current_month == month && current_day >= day){
            ToDoList.insert(it,Item);
            exit;
            break;
        }
    }
    ToDoList.push_back(Item);
}
