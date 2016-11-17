#include "../hash_map.h"
#include <iostream>
using namespace std;


class SetHM{
    private:
        HashMap<string> SetHash;
    public:
        SetHM();
        ~SetHM();

    void insert(string key); 
    bool is_in(string key); 
    void remove(string key); 
    bool is_empty(); 
};