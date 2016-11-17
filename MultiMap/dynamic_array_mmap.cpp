#include "../dynamic_array.h" // header file
#include "dynamic_array_mmap.h"
#include "../pair.h"
#include <iostream> // string
#include <assert.h> // assert
#include <stdlib.h> // malloc/free
#include <sstream>
using namespace std;

// ========== M u l t i M a p   W i t h   D y n a m i c A r r a y =========== //

MultiMapDA::MultiMapDA() {
    // the dynamic array already calls default constructor
}

void MultiMapDA::set(string str, int i) {
    Pair<int> newpair = Pair<int>(str, i);
    data.Push(newpair);
    return;
}

void MultiMapDA::removeAll(string str) {
    for(unsigned long i = 0; i < data.GetSize(); i++) {
        if (data.Get(i).GetKey() == str){
            data.Remove(i);
            i--;
        }
    }
    return;
}

int* MultiMapDA::getAll(string str) {
    int* result = new int[data.GetSize()];
    int count = 0;
    for(unsigned long i = 0; i < data.GetSize(); i++) {
        //cout << "Checking i = " << i << "; data[i] = \"" << data.Get(i).GetKey() << endl;
        if(data.Get(i).GetKey() == str) {
            cout << "matched" << endl;
            result[count] = data.Get(i).GetData();
            count++;
        }
    }
    return result;
}

int MultiMapDA::count(string str) {
    int count = 0;
    
    for(unsigned long i = 0; i < data.GetSize(); i++) {
        if(data.Get(i).GetKey() == str) {
            count++;
        }
    }
    
    return count;
}

MultiMapDA::~MultiMapDA() {
    // do nothing, the deconstructor for dynamic array automatically called
}

/*int main() {
    MultiMapDA map = MultiMapDA();
    map.set("apple", 1);
    map.set("apple", 2);
    map.set("apple", 3);
    map.set("banana", 11);
    map.set("banana", 22);
    map.getAll("apple");
    cout << map.getAll("apple")[2] << endl;
    cout << "count of apple = " << map.count("apple") << endl;
    cout << "--" << endl;
    map.removeAll("apple");
    cout << map.getAll("apple")[0] << endl;
    cout << "count of apple = " << map.count("apple") << endl;
    cout << "--" << endl;
    cout << map.getAll("banana")[1] << endl;
    return 0;
}*/

/*
int main() {
    MultiMapDA map = MultiMapDA();
    string str;
    for(int i = 0; i < 50000; i++){
        string number;
        stringstream strstream;
        strstream << i;
        strstream >> number;
        
        str = "key" + number;
        map.set(str, i);
    }
    
    cout << map.getAll("key333")[0] << endl;
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