//
// Created by Stefano on 02/02/2021.
//

#include <string>
#include "Map.h"

using namespace std;

Map::Map() = default;

Map::~Map() = default;

void Map::showMap() const {
    if(todomap.empty()){
        cout<<"sorry, list is actually empty"<<endl;
    }
    else{
        int num=1;
        string done;
        cout<<"List elements are the following:"<<endl;
        for(const auto & it : todomap) {
            if(it.second.getItemDone() == 0) //controllo per trasformare i valori 0\1 in false\true
                done="False";
            else
                done="True";

            cout << num << ") " << it.first<< " Name: " << it.second.getName()<< " Description: "<< it.second.getDescription() << " Done: "<< done << endl;
            num++;
        }
    }
}

void Map::addItem(const string& name,int day,int month, int year, const string& description, bool done) {

    date.setDate(year,month,day);
    string sdate=date.printDate();

    item.setName(name);
    item.setDescription(description);
    item.setItemDone(done);

    if (todomap.empty()) {
        iterator = todomap.insert(pair<string, ToDoItem>{sdate, ToDoItem{item.getName(), item.getDescription(), item.getItemDone()}});
    } else{
        todomap.insert(iterator,pair<string, ToDoItem>{sdate, ToDoItem{item.getName(), item.getDescription(), item.getItemDone()}});
    }
}


bool Map::deleteElement(const string& deleteName) {
    bool success = false;
    if (todomap.empty()) {
        cout << "The map is empty!" << endl;
    } else {
        for(const auto & it : todomap) {
            if(it.second.getName() == deleteName){
                todomap.erase(it.first);
                success = true;
                return success;
            }
        }
    }
    return success;
}

bool Map::checkItem(const string& checkName){
    bool success = false,done;
    int i=0;
    string sdate, name, desc,result;
    string array[3];
    if (todomap.empty()) {
        cout << "The map is empty!" << endl;
    } else {
        for(const auto & it : todomap) {
            if(it.second.getName() == checkName){
                sdate=it.first;

                string delimiter = "/";
                size_t pos;
                while ((pos = sdate.find(delimiter)) != std::string::npos) {
                    array[i] = sdate.substr(0, pos);
                    i++;
                    sdate.erase(0, pos + delimiter.length());
                }

                name=it.second.getName();
                desc=it.second.getDescription();
                if(it.second.getItemDone() == 0){
                    done=true;
                }else
                    done=false;

                todomap.erase(it.first);
                addItem(name,stoi(array[1]),std::stoi(array[1]),std::stoi(array[0]),desc,done);
                success = true;
                //return success;
            }
        }
    }
    return success;
}

void Map::writeOnFile() const {
    string done;
    ofstream writeFile;
    writeFile.open("ToDoMap.txt");

    if(!todomap.empty()) {
        for(const auto & it : todomap) {
            writeFile << it.first << " | ";
            writeFile << it.second.getName() << " | ";
            writeFile << it.second.getDescription() << "  | ";
            if(it.second.getItemDone() == 0)
                done="UNDONE";
            else
                done="DONE";
            writeFile << done << endl;
        }
    }
    else
        cout <<"todomap empty";
    writeFile.close();
}

void Map::readFromFile(){
    string sdate,sdone;
    bool ddone;
    ifstream file("ToDoMap.txt");

    if (file.fail()) {
        cout << "Unable to open the file!!" << endl;
    } else if (file.eof()) {
        cout << "File is empty" << endl;
    } else {
        string input;
        cout << "" << endl;

        while (getline(file, input)) {       // prelevo dal file una riga alla volta per poterla elaborare

            string next;
            vector<string> toDoItems;
            char ch= ' ';
            for (char it : input) {
                if (it == ch) {
                    if (!next.empty()) {
                        toDoItems.push_back(next);
                        next.clear();
                    }
                } else {
                    next += it;
                }
            }
            if (!next.empty())
                toDoItems.push_back(next);
            for(const auto& its:toDoItems)
                cout << its <<" ";
            cout<<endl;

            int index = 0, n=0,i=0;

            string name, desc, component, space = " ";
            while (toDoItems[index + n] != "|") {            //la prima parte di ogni riga contiene il nome (composto da 1 o piu parole) dell'evento
                component = toDoItems[index + n];
                name.append(component);
                name.append(space);
                n++;
            }
            name.pop_back();

            string array[3];
            sdate=toDoItems[index+n+1];
            sdate.append(space);
            string delimiter = "/";
            string delimiter2 = " ";
            size_t pos;
            while ((pos = sdate.find(delimiter)) != std::string::npos) {
                array[i] = sdate.substr(0, pos);
                i++;
                sdate.erase(0, pos + delimiter.length());
            }
            array[i] = sdate.substr(0);

            sdone = toDoItems[n + 3];
            if(sdone == "UNDONE")
                ddone=false;
            else
                ddone=true;

            index = n + 5;
            n = 0;
            while (index + n < toDoItems.size()) {  //le ultime righe contengono la descrizione dell'evento
                component = toDoItems[index + n];
                desc.append(component);
                desc.append(space);
                n++;
            }
            desc.pop_back();

            addItem(name,std::stoi(array[2]),std::stoi(array[1]),std::stoi(array[0]),desc,ddone);
        }
    }
    cout<<""<<endl;
    file.close();
}
