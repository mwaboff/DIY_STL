#include "../linked_list.h"
#include <iostream>
using namespace std;

class SetLL{
    private:
        LinkedList<string> SetLinked;
    public:
        SetLL();
        ~SetLL();
    
    void insert(string key) ;
    bool is_in(string key) ;
    void remove(string key) ;
    bool is_empty() ;
};