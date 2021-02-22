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
            if(it.second.getItemDone() == 0)
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
                size_t pos=0;
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
                return success;
            }
        }
    }
    return success;
}
