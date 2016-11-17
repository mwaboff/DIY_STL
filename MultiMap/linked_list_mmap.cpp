#include "../linked_list.h" // header file
#include "linked_list_mmap.h"
#include "../pair.h"
#include <iostream> // string
#include <assert.h> // assert
#include <stdlib.h> // malloc/free
#include <sstream>
using namespace std;

// =========== M u l t i M a p   W i t h   L i n k e d   L i s t ============ //

MultiMapLL::MultiMapLL() {
    // the dynamic array already calls default constructor
}

void MultiMapLL::set(string str, int i) {
    NodeLL< Pair< DynamicArray<int>* >* > * curr_node = data.GetFirst();
    while(curr_node != 0) {
        if(curr_node->GetValue()->GetKey() == str) {
            curr_node->GetValue()->GetData()->Push(i);
            return;
        }
        curr_node = curr_node->GetNext();
    }
    
    DynamicArray<int> * newList = new DynamicArray<int>();
    newList->Push(i);
    
    Pair< DynamicArray<int>* > * newPair = new Pair< DynamicArray<int>* >(str, newList);
    data.Append(newPair);
    return;
}

void MultiMapLL::removeAll(string str) {
    NodeLL< Pair< DynamicArray<int>* >* > * curr_node = data.GetFirst();
    while(curr_node != 0) {
        if(curr_node->GetValue()->GetKey() == str) {
            data.Remove(curr_node);
            return;
        }
        curr_node = curr_node->GetNext();
    }
    return;
}

int* MultiMapLL::getAll(string str) {
    DynamicArray<int> * dynamic_result;
    int* result;
    NodeLL< Pair< DynamicArray<int>* >* > * curr_node = data.GetFirst();
    
    while(curr_node != 0) {
        if(curr_node->GetValue()->GetKey() == str) {
            dynamic_result = curr_node->GetValue()->GetData();
            
            result = new int[dynamic_result->GetSize()];
            for(int i = 0; i < dynamic_result->GetSize(); i++) {
                result[i] = dynamic_result->Get(i);
            }
            return result;
        }
        curr_node = curr_node->GetNext();
    }
    return new int[0];
}

int MultiMapLL::count(string str) {
    int count = 0;
    NodeLL< Pair< DynamicArray<int>* >* > * curr_node = data.GetFirst();
    
    while(curr_node != 0) {
        if(curr_node->GetValue()->GetKey() == str) {
            return curr_node->GetValue()->GetData()->GetSize();
        }
        curr_node = curr_node->GetNext();
    }
    
    return 0;
}

MultiMapLL::~MultiMapLL() {
    // do nothing, the deconstructor for dynamic array automatically called
}

/*
int main() {
    MultiMapLL map = MultiMapLL();
    string str;
    for(int i = 0; i < 50000; i++){
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