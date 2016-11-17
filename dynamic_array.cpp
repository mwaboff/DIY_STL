#include "dynamic_array.h"
#include "pair.h"
#include <iostream> // strings
#include <assert.h> // assert
using namespace std;

// ======================= D y n a m i c = A r r a y ======================== //


// Constructor
template<class DataType>
DynamicArray<DataType>::DynamicArray(){
    value = new DataType [START_SIZE];
    allocated_size = START_SIZE;
    real_size = 0;
}


// Resize
template<class DataType>
void DynamicArray<DataType>::Resize(){
    allocated_size *= 2;
    DataType* temp = new DataType[allocated_size];
    for(unsigned long i = 0; i < real_size; ++i){
        temp[i] = value[i];
    }
    delete[] value;
    value = temp;
    return;
}

// GetSize
template<class DataType>
unsigned long DynamicArray<DataType>::GetSize(){
    return real_size;
}

// GetAllocatedSize
template<class DataType>
unsigned long DynamicArray<DataType>::GetAllocatedSize(){
    return allocated_size;
}

// Push
template<class DataType>
void DynamicArray<DataType>::Push(DataType data){
    if(real_size == allocated_size){
        Resize();
    }
    value[real_size] = data;
    ++real_size;
    return;
}

// Get
template<class DataType>
DataType DynamicArray<DataType>::Get(unsigned long index){
    try{
        if(index > (real_size - 1)){
            throw 0;
        }
        return value[index];
    } catch (int e){
        cout << "DynamicArray::Get : Index out of Range" << endl;
    }
}

// Set
template<class DataType>
void DynamicArray<DataType>::Set(unsigned long index, DataType data){
    try{
        if(index > (real_size - 1)){
            throw 0;
        }
        value[index] = data;
        return;
    } catch (int e){
        cout << "DynamicArray::Set : Index out of Range" << endl;
    }
    
}

template<class DataType>
void DynamicArray<DataType>::Remove(unsigned long index){
    try{
        if(index >= real_size) throw 0;
        
        for(; index < real_size - 1; index++){
            value[index] = value[index + 1];
        }
        real_size--;
        return;
    } catch (int e) {
        cout << "DyanmicArray::Remove : Index out of Range" << endl;
    }
}

template<class DataType>
DataType& DynamicArray<DataType>::GetAddress(unsigned long index){
    return value[index];
}

// Deconstructor
// again, use new/delete
template<class DataType>
DynamicArray<DataType>::~DynamicArray(){
    delete[] value;
    real_size = 0;
    allocated_size = 0;
}

template class DynamicArray<string>;
template class DynamicArray< Pair<int> >;
template class DynamicArray< Pair<int>* >;
template class DynamicArray<int>;

/*
// Testing
int main(){
    DynamicArray<string> da = DynamicArray<string>();
    string str;
    for(unsigned long i = 0; i < 10000000; i++){
        str = "hello is it me you're looking for?";
        da.Push(str);
    }
    return 0;
}
*/
