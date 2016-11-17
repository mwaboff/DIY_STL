#ifndef PAIR_H
#define PAIR_H

#include <iostream>

using namespace std;

template<class DataType>
class Pair {
    private:
    // fields
    string key;
    DataType data;
    
    public:
    Pair(){
        string key;
    }
    
    Pair(string str, DataType i){
        key = str;
        data = i;
    }
    
    void SetKey(string str){
        key = str;
        return;
    }
    
    void SetData(DataType i){
        data = i;
        return;
    }
    
    string GetKey(){
        return key;
    }
    
    DataType GetData(){
        return data;
    }
    
    DataType& GetAddress(){
        return data;
    }

    
};

#endif