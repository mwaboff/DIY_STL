#ifndef DYNAMIC_ARRAY_MSET_H
#define DYNAMIC_ARRAY_MSET_H
#include <iostream> // strings
#include <assert.h> // assert
#include "../dynamic_array.h"
using namespace std;

class MS_DA {
    private:
    DynamicArray<string> value;
    
    public:
    MS_DA();
    ~MS_DA();
    void insert(string key);
    bool is_in(string key);
    unsigned long count(string key);
    void removeOne(string key);
    void removeAll(string key);
    bool is_empty();
    
    void removeAllEric(string);
    
    // extra credit
    string draw_random();
};

#endif