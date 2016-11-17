#include "../hash_map.h" // header file
#include "hash_map_mmap.h"
#include "../dynamic_array.h" // header file
#include <iostream> // string
#include <assert.h> // assert
#include <sstream>
using namespace std;

MultiMapHM::MultiMapHM(){
    // do nothing, hash map constructor automatically called
}

void MultiMapHM::set(string str, int i){
    NodeHM< DynamicArray<int>* >* temp = data.Get(str);
    
    while(temp != 0) {
        if(temp->GetKey() == str) {
            temp->GetData()->Push(i);
            return;
        }
        temp = temp->GetNext();
    }
    DynamicArray<int> * temp_array = new DynamicArray<int>();
    temp_array->Push(i);
    data.Set(str, temp_array);
        
    return;
}

void MultiMapHM::removeAll(string str) {
    NodeHM< DynamicArray<int>* >* temp = data.Get(str);
    while(temp != 0){ // stop on null pointer
        if(temp->GetKey() == str){ // if we found our key
            data.Remove(temp);
            return;
        }
        temp = temp->GetNext();
    }
    return;
}

int* MultiMapHM::getAll(string str) {
    NodeHM< DynamicArray<int>* >* temp = data.Get(str);
    if(temp == 0) {
        cout << "Not found" << endl;
        return new int[0];
    }
    while(temp != 0){
        
        /*cout << "curr key = " << temp->GetKey() << " hash = " << data.Hash(temp->GetKey()) << endl;
        cout << "search key = " << str << " hash = " << data.Hash(str) << endl;
        cout << "temp->GetNext() = " << temp->GetNext() << endl;*/
        if(temp->GetKey() == str) {
            int* result = new int[temp->GetData()->GetSize()];
            while(temp != 0){
                if(temp->GetKey() == str){
                    for(int i = 0; i < temp->GetData()->GetSize(); i++) {
                        result[i] = temp->GetData()->Get(i);
                    }
                    return result;
                }
                temp = temp->GetNext();
            }
            return result;
        }
        temp = temp->GetNext();
    }
    
    cout << "Not Found" << endl;
    return new int[0];
   
}

int MultiMapHM::count(string str) {
    NodeHM< DynamicArray<int>* > * temp = data.Get(str);
    while(temp != 0) {
        if(temp->GetKey() == str){
            return temp->GetData()->GetSize();
        }
        temp = temp->GetNext();
    }
    return 0;
}

MultiMapHM::~MultiMapHM(){
    // do nothing, linked list deconstructor called
}


/*
int main() {
    MultiMapHM map = MultiMapHM();
    string str;
    for(int i = 0; i < 1000000; i++){
        string number;
        stringstream strstream;
        strstream << i;
        strstream >> number;
        
        str = "key" + number;
        map.set(str, i);
    }
    
    cout << map.getAll("key333333")[0] << endl;
    cout << map.getAll("key12345")[0] << endl;
    assert(map.getAll("key12345")[0] == 12345);
    assert(map.getAll("key0")[0] == 0);
    map.removeAll("key12345");
    map.removeAll("key12345");
    cout << map.getAll("key12345")[0] << endl;
    assert(map.getAll("key12345")[0] == 0);
    map.set("key12345", 100);
    assert(map.getAll("key12345")[0] == 100);
    cout << "Tests passed" << endl;
    
    return 0;
}
*/











