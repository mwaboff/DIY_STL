#ifndef DYNAMIC_ARRAY_MMAP_H
#define DYNAMIC_ARRAY_MMAP_H
#include <iostream> // strings
#include "../dynamic_array.h" // dyanmic array
#include "../pair.h"
using namespace std;

class MultiMapDA {
  private:
    DynamicArray< Pair<int> > data;
  
  public:
    // constructor
    MultiMapDA();
  
    void set(string, int);
    void removeAll(string);
    int* getAll(string);
    int count(string);
    
    // deconstructor
    ~MultiMapDA();
};

#endif