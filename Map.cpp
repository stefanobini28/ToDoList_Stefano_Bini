//
// Created by Stefano on 02/02/2021.
//

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

            cout << num << ") " << it.first<< " | Name: " << it.second.getName()<< " | Description: "<< it.second.getDescription() << " | Done: "<< done << endl;
            num++;
        }
    }
}

void Map::addItem(const string& name,int day,int month, int year, const string& description, bool done) {
    date.setDate(year,month,day);
    string strdate=date.printDate();

    item.setName(name);
    item.setDescription(description);
    item.setItemDone(done);

    if (todomap.empty()) {
        iterator = todomap.insert(pair<string, ToDoItem>{strdate, ToDoItem{item.getName(), item.getDescription(), item.getItemDone()}});
    } else{
        todomap.insert(iterator,pair<string, ToDoItem>{strdate, ToDoItem{item.getName(), item.getDescription(), item.getItemDone()}});
    }
}

bool Map::deleteElement(const string& deleteName) {
    bool success = false;
    if (todomap.empty()) {
        cout << "The map is empty!" << endl;
        multimap<string,ToDoItem>::iterator it;
    } else {
        for(auto it=todomap.begin();it!=todomap.end();it++){
            if(it->second.getName() == deleteName){
                todomap.erase(it);
                success = true;
                return success;
            }
        }
    }
    return success;
}

bool Map::checkItem(const string& checkName) {
    bool success = false, done, first;
    int i = 0;
    string strdate, name, desc, result, array[3], delimiter = "/";
    if (todomap.empty()) {
        cout << "The map is empty!" << endl;
    } else {
        for(auto it=todomap.begin();it!=todomap.end();it++){
                if (it->second.getName() == checkName) {
                    strdate = it->first;

                    size_t pos;
                    while ((pos = strdate.find(delimiter)) != std::string::npos) {
                        array[i] = strdate.substr(0, pos);
                        i++;
                        strdate.erase(0, pos + delimiter.length());
                    }
                    array[i] = strdate.substr(0, pos);

                    name = it->second.getName();
                    desc = it->second.getDescription();
                    if (it->second.getItemDone() == 0) {
                        done = true;
                    } else
                        done = false;

                    if (it==todomap.begin()){
                        first =true;
                    }else
                        first = false;
                    todomap.erase(it);

                    date.setDate(stoi(array[0]), std::stoi(array[1]), std::stoi(array[2]));
                    strdate=date.printDate();

                    item.setName(name);
                    item.setDescription(desc);
                    item.setItemDone(done);

                    if (todomap.empty() || first) {
                        iterator = todomap.insert(pair<string, ToDoItem>{strdate, ToDoItem{item.getName(), item.getDescription(), item.getItemDone()}});
                    } else{
                        todomap.insert(iterator,pair<string, ToDoItem>{strdate, ToDoItem{item.getName(), item.getDescription(), item.getItemDone()}});
                    }
                    success = true;
                    return success;
                }
            }
        }
    return success;
}

void Map::writeOnFile() const {
    string done;
    ofstream writeFile;
    writeFile.open("ToDoList.txt");

    if(!todomap.empty()) {
        for(const auto & it : todomap){
            writeFile << it.first << " | ";
            writeFile << it.second.getName() << " | ";
            if(it.second.getItemDone() == 0)
                done="UNDONE";
            else
                done="DONE";
            writeFile << done << " | ";
            writeFile << it.second.getDescription() << endl;
        }
    }
    else
        cout <<"todomap empty";
    writeFile.close();
}

void Map::readFromFile(){
    string strdate,strdone;
    bool newdone;
    ifstream file("ToDoList.txt");

    if (file.fail()) {
        cout << "Unable to open the file!!" << endl;
    } else if (file.eof()) {
        cout << "File is empty" << endl;
    } else {
        vector<string> toDoItems;
        char ch= ' ';
        int index, n, i;
        string name, desc, component,next, input, space = " ", delimiter = "/", array[3];

        cout << "" << endl;

        while (getline(file, input)) {      // preleva dal file una riga alla volta per poterla elaborare
            name.clear(),desc.clear(),next.clear();
            index = 0, n=0,i=0;
            toDoItems.clear();
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

            strdate=toDoItems[index];  //il primo elemento di ogni riga contiene la data di ogni evento
            strdate.append(space);
            size_t pos;

            while ((pos = strdate.find(delimiter)) != std::string::npos) {  //suddivido la data nelle sue 3 componenti
                array[i] = strdate.substr(0, pos);
                i++;
                strdate.erase(0, pos + delimiter.length());
            }
            array[i] = strdate.substr(0);

            while (toDoItems[index + n + 2] != "|") {     //il secondo elemento di ogni riga contiene il nome (composto da 1 o piu parole) dell'evento
                component = toDoItems[index + n + 2];
                name.append(component);
                name.append(space);
                n++;
            }
            name.pop_back();

            strdone = toDoItems[n + 3];
            if(strdone == "UNDONE")
                newdone=false;
            else
                newdone=true;

            index = n + 5;
            n = 0;
            while (index + n < toDoItems.size()) {  //le ultime righe contengono la descrizione dell'evento
                component = toDoItems[index + n];
                desc.append(component);
                desc.append(space);
                n++;
            }
            desc.pop_back();
            //aggiunta dell'elemento nella lista locale
            addItem(name,std::stoi(array[2]),std::stoi(array[1]),std::stoi(array[0]),desc,newdone);
        }
    }
    cout<<""<<endl;
    file.close();
}
