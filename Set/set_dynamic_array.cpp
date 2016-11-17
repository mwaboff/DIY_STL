#include <iostream> // strings
#include "../dynamic_array.h" // dyanmic array
#include "set_dynamic_array.h"
using namespace std;

SetDA::SetDA(){

}
SetDA::~SetDA(){
    
}

void SetDA::insert(string key){
    SetDynamic.Push(key);
}


bool SetDA::is_in(string key) {
    for(unsigned long i = 0; i < SetDynamic.GetSize(); i++){
        if (SetDynamic.Get(i) == key){
            return true;
        }
    }
    return false;
    
}

void SetDA::remove(string key){
    for(unsigned long i = 0; i < SetDynamic.GetSize(); i++){
        if (SetDynamic.Get(i) == key){
            SetDynamic.Remove(i);
            return;
        }
    }
    return;
}

bool SetDA::is_empty() {
    if(SetDynamic.GetSize() == 0){
        return true;
    }
    return false;
    
}

SetDA SetDA::Union(SetDA other_set){
    if (other_set.SetDynamic.GetSize() < this->SetDynamic.GetSize()){
        SetDA union_set = other_set;
        for(unsigned long i = 0; i < this->SetDynamic.GetSize(); i++){
            string temp = this->SetDynamic.Get(i);
            bool repeat = false;
            for(unsigned long j = 0; i < union_set.SetDynamic.GetSize(); i++){
                if (union_set.SetDynamic.Get(j) == temp){
                    repeat = true;
                    break;
                }
            }
            if(!repeat){
                union_set.SetDynamic.Push(temp);
            }
        }
        return union_set;
    } else {
        SetDA union_set = *this;
        for(unsigned long i = 0; i < other_set.SetDynamic.GetSize(); i++){
            string temp = other_set.SetDynamic.Get(i);
            bool repeat = false;
            for(unsigned long j = 0; i < union_set.SetDynamic.GetSize(); i++){
                if (union_set.SetDynamic.Get(j) == temp){
                    repeat = true;
                    break;
                }
            }
            if(!repeat){
                union_set.SetDynamic.Push(temp);
            }
        }
        return union_set;
    }
}


SetDA SetDA::Intersection(SetDA other_set){
    SetDA intersect;
    
    for(unsigned long i = 0; i < other_set.SetDynamic.GetSize(); i++){
        string temp = other_set.SetDynamic.Get(i);
        bool repeat = false;
        for(unsigned long j = 0; i < this->SetDynamic.GetSize(); i++){
            if(temp == this->SetDynamic.Get(j)){
                repeat = true;
                break;
            }
        }
        if(repeat){
            intersect.SetDynamic.Push(temp);
        }
    }
    
    return intersect;
}







