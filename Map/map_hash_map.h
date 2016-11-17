#ifndef MAP_HASH_MAP_H
#define MAP_HASH_MAP_H

#include <iostream> // strings
#include "../hash_map.h" // hash map
using namespace std;

class MapHM {
  private:
  HashMap<int> value;
  
  public:
  // constructor
  MapHM();
  
  void set(string, int);
  void remove(string);
  int get(string);
  int& operator[](string key);
  
  ~MapHM();
};

#endif