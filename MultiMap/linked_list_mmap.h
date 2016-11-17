#ifndef LINKED_LIST_MMAP_H
#define LINKED_LIST_MMAP_H
#include <iostream> // strings
#include "../dynamic_array.h" // dyanmic array
#include "../pair.h"
using namespace std;

class MultiMapLL {
  private:
    LinkedList< Pair< DynamicArray<int>* >* > data;
  
  public:
    // constructor
    MultiMapLL();
  
    void set(string, int);
    void removeAll(string);
    int* getAll(string);
    int count(string);
    
    // deconstructor
    ~MultiMapLL();
};

#endif