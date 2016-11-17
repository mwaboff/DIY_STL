#ifndef HASH_MAP_MSET_H
#define HASH_MAP_MSET_H
#include <iostream> // strings
#include <assert.h> // assert
#include "../hash_map.h"
using namespace std;

class MS_HM {
    private:
    HashMap<string> value;
    
    public:
    MS_HM();
    ~MS_HM();
    void insert(string key);
    bool is_in(string key);
    unsigned long count(string key);
    void removeOne(string key);
    void removeAll(string key);
    bool is_empty();
    
    // extra credit
    string draw_random();
};

#endif