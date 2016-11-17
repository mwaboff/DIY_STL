#include "../hash_map.h"
#include <iostream>
using namespace std;
#include "set_hash_map.h"

SetHM::SetHM(){
    
}
SetHM::~SetHM(){
    
}

void SetHM::insert(string key){
    SetHash.Set(key, key);
}

bool SetHM::is_in(string key){
    NodeHM<string>* temp = SetHash.Get(key);
    while(temp != 0){
        if(temp->GetKey() == key){
            return true;
        }
        temp = temp->GetNext();
    }
    return false;
}

void SetHM::remove(string key){
    NodeHM<string>* temp = SetHash.Get(key);
    while(temp != 0){
        if(temp->GetKey() == key){
            SetHash.Remove(temp);
            return;
        }
        temp = temp->GetNext();
    }
    return;
}

bool SetHM::is_empty(){
    
        return SetHash.IsEmpty();
        
} 