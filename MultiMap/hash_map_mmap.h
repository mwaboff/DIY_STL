#ifndef HASH_MAP_MMAP_H
#define HASH_MAP_MMAP_H

#include <iostream> // strings
#include "../hash_map.h" // hash map
#include "../dynamic_array.h"
using namespace std;

class MultiMapHM {
  private:
  HashMap< DynamicArray<int>* > data;
  
  public:
  // constructor
  MultiMapHM();
  
  void set(string, int);
  void removeAll(string);
  int* getAll(string);
  int count(string);
  
  ~MultiMapHM();
};

#endif