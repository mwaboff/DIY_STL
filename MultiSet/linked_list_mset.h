#ifndef LINKED_LIST_MSET_H
#define LINKED_LIST_MSET_H
#include <iostream> // strings
#include <assert.h> // assert
#include "../linked_list.h"
using namespace std;

class MS_LL {
    private:
    LinkedList<string> value;
    
    public:
    MS_LL();
    ~MS_LL();
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