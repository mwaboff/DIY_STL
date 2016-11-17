#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

using namespace std;

// A dynamic array has to allocate memory to hold values, and resize when needed
// Very similar, but maybe a little bit simpler, than our SuperArray
template <class DataType>
class DynamicArray { 
  private: 
    // Fields
    DataType* value;
    unsigned long real_size;
    unsigned long allocated_size;
    
    const static unsigned long START_SIZE = 1;
    
    // Private Functions
    void Resize(); // Double the allocated memory, move all elements over, free old memory

  public: 
    // Constructor
    DynamicArray(); // allocate START_SIZE memory
    
    // Public Functions
    unsigned long GetSize();
    unsigned long GetAllocatedSize();
    
    void Push(DataType); // resize if needed
    
    DataType Get(unsigned long);
                                
    void Set(unsigned long, DataType);
    
    void Remove(unsigned long index); // Removes a value in the DynamicArray (indicated by the index) and
                                      // shifts the array over by one
                                    
    DataType& GetAddress(unsigned long);
                                      
    // Destructor
    ~DynamicArray(); // free up memory
    
}; 

#endif