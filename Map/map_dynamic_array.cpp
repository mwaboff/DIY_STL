#include <iostream> // strings
#include "../dynamic_array.h" // dyanmic array
#include "map_dynamic_array.h"
#include "../pair.h"
#include <sstream>
#include <assert.h>
using namespace std;

MapDA::MapDA(){
    // the dynamic array already calls default constructor
}

void MapDA::set(string str, int i){
    Pair<int> newpair = Pair<int>(str, i);
    value.Push(newpair);
    return;
}

void MapDA::remove(string str){
    for(unsigned long i = 0; i < value.GetSize(); i++){
        if (value.Get(i).GetKey() == str){
            value.Remove(i);
            return;
        }
    }
    // if key not found, assume was already removed
    return;
}

int MapDA::get(string str){
    try{
        for(unsigned long i = 0; i < value.GetSize(); i++){
            if (value.Get(i).GetKey() == str){
                return value.Get(i).GetData();
            }
        }
        throw 0;
    } catch (int e){
        cout << "MapDA::get(string) : Key Not Found" << endl;
        return 0;
    }
    
}


int& MapDA::operator[](string key){
    for(unsigned long i = 0; i < value.GetSize(); i++){
        if (value.Get(i).GetKey() == key){
            return value.GetAddress(i).GetAddress();
        }
    }
}


MapDA::~MapDA(){
    // do nothing, the deconstructor for dynamic array automatically called
}

/*
// Testing
int main(){
    MapDA map = MapDA();
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
    assert(map.get("key0") == 0);
    map.remove("key12345");
    map.remove("key12345");
    assert(map.get("key12345") == 0);
    map.set("key12345", 100);
    assert(map.get("key12345") == 100);
    
    cout << "All tests have passed!" << endl;
    
    
    return 0;
}
*/
