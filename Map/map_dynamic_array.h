#ifndef MAP_DYNAMIC_ARRAY_H
#define MAP_DYNAMIC_ARRAY_H
#include <iostream> // strings
#include "../dynamic_array.h" // dyanmic array
#include "../pair.h"
using namespace std;

class MapDA {
  private:
  DynamicArray< Pair<int> > value;
  
  public:
  // constructor
  MapDA();
  
  void set(string, int);
  void remove(string);
  int get(string);
  int& operator[](string key);
  
  // deconstructor
  ~MapDA();
  
};



#endif