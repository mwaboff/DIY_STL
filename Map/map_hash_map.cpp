#include "map_hash_map.h" // header file
#include <iostream> // string
#include <assert.h> // assert
#include <sstream>
using namespace std;

MapHM::MapHM(){
    // do nothing, hash map constructor automatically called
}

void MapHM::set(string str, int i){
    value.Set(str, i);
    return;
}

void MapHM::remove(string str){
    NodeHM<int>* temp = value.Get(str);
    while(temp != 0){ // stop on null pointer
        if(temp->GetKey() == str){ // if we found our key
            value.Remove(temp);
            return;
        }
        temp = temp->GetNext();
    }
    return;
}

int MapHM::get(string str){
    NodeHM<int>* temp = value.Get(str);
    try{
        while(temp != 0){
            if(temp->GetKey() == str){
                return temp->GetData();
            }
            temp = temp->GetNext();
        }
        throw 0;
    } catch (int e){
        cout << "HashMap::get(string) : Key not found" << endl;
        return 0;
    }
}

MapHM::~MapHM(){
    // do nothing, linked list deconstructor called
}

int& MapHM::operator[](string key){
    try{
        NodeHM<int>* temp = value.Get(key);
        while(temp != 0){
            if(temp->GetKey() == key){
                return temp->GetAddress();
            }
            temp = temp->GetNext();
        }
        throw 0;
    } catch (int e){
        cout << "MapHM::operator[] : Key " << key << " not found" << endl;
        cout << "Program will seg fault" << endl;
    }
}


// testing
/*
int main(){
    
    MapHM map = MapHM();
    string str;
    for(unsigned long i = 0; i < 1000000; i++){
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
    map.set("key12345", 1);
    assert(map.get("key12345") == 1);
    assert(map["key100"] == 100);
    map["key100"] = 200;
    assert(map["key100"] == 200);
    cout << "All tests passed!" << endl;
    return 0;
}
*/












