#include "map_linked_list.h" // header file
#include <iostream> // string
#include <assert.h> // assert
#include "../pair.h" // pair
#include <sstream>
using namespace std;

MapLL::MapLL(){
    // do nothing, linked list constructor automatically called
}

void MapLL::set(string str, int i){
    Pair<int> newpair = Pair<int>(str, i);
    value.Append(newpair);
}

void MapLL::remove(string str){
    NodeLL< Pair<int> >* temp = value.GetFirst();
    while(temp != 0){ // stop on null pointer
    
        if(temp->GetValue().GetKey() == str){ // if we found our key
            string tempStr = temp->GetValue().GetKey();
            value.Remove(temp);
            return;
        }
        temp = temp->GetNext();
    }
    return;
}

int MapLL::get(string str){
    NodeLL< Pair<int> >* temp = value.GetFirst();
    try{
        while(temp != 0){ // while temp is not null
            if (temp->GetValue().GetKey() == str){ // check if keys are equal
                return temp->GetValue().GetData(); // if they are, return data
            }
            temp = temp->GetNext();
        }
        throw 0;
    } catch (int e){
        cout << "MapLL::get(string) : Key Not Found" << endl;
        return 0;
    }
}


MapLL::~MapLL(){
    // do nothing, linked list deconstructor called
}

int& MapLL::operator[](string key){
    NodeLL< Pair<int> >* temp = value.GetFirst();
    while(temp != 0){
        if(temp->GetValue().GetKey() == key){
            return temp->GetAddress().GetAddress();
        }
        temp = temp->GetNext();
    }
}

/*
// testing
int main(){
    
    MapLL map = MapLL();
    string str;
    for(unsigned long i = 0; i < 10000000; i++){
        string number;
        stringstream strstream;
        strstream << i;
        strstream >> number;
        
        str = "key" + number;
        map.set(str, i);
    }

    assert(map.get("key12345") == 12345);
    map.remove("key12345");
    assert(map.get("key12345") == 0);
    assert(map.get("key12345") == 1);
    return 0;
}
*/











