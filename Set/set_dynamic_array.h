#include "../dynamic_array.h"
#include <iostream>
using namespace std;

class SetDA {
    
    private:
    // Fields
    DynamicArray<string> SetDynamic;
    
    public:
    SetDA();
    ~SetDA();
    
    void insert(string key);
    bool is_in(string key);
    void remove(string key);
    bool is_empty(); 
    
    // extra credit
    SetDA Union(SetDA other_set);
    SetDA Intersection(SetDA other_set);

};
