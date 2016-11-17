#include "../linked_list.h"
#include <iostream>
#include "set_linked_list.h"
using namespace std;

SetLL::SetLL(){
    
}
SetLL::~SetLL(){
    
}

void SetLL::insert(string key) {
    SetLinked.Append(key);
}


bool SetLL::is_in(string key) {
    NodeLL<string>* temp = SetLinked.GetFirst();
    while(temp != 0){
        if(temp->GetValue() == key){
            return true;
        }
        temp = temp->GetNext();
    }
    return false;
}


void SetLL::remove(string key) {
    NodeLL<string>* temp = SetLinked.GetFirst();
    while(temp != 0){
        if(temp->GetValue() == key){
            SetLinked.Remove(temp);
            return;
        }
        temp = temp->GetNext();
    }
    return;
}


bool SetLL::is_empty() {
     if(SetLinked.GetFirst() == 0){
        return true;
    }
    return false;
}