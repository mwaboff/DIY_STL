#ifndef MAP_LINKED_LIST_H
#define MAP_LINKED_LIST_H

#include <iostream> // strings
#include "../pair.h" // pair
#include "../linked_list.h" // linked list
using namespace std;

class MapLL {
  private:
  LinkedList< Pair<int> > value;
  
  public:
  // constructor
  MapLL();
  
  void set(string, int);
  void remove(string);
  int get(string);
  int& operator[](string key);
  
  ~MapLL();
};


#endif