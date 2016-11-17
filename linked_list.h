#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "pair.h"

using namespace std;

// We have to keep these base Data Structures as simple as possible
// So for now, LinkedList just has to be able to hold data using NodeLLs,
// and be able to add new data to the already existing LinkedList


// A NodeLL contains a value of type "DataType" and a pointer to another NodeLL.
// If we encounter a null pointer, then NodeLL does not point to another NodeLL.
template <class DataType>
class NodeLL {
  private: 
    // Fields
    DataType value;
    NodeLL<DataType>* prev;
    NodeLL<DataType>* next;

  public: 
    // Constructor
    NodeLL(DataType); // Make a NodeLL with value of DataType, will not point to any other NodeLL
    
    // Public Functions
    void SetNext(NodeLL*);
    void SetPrev(NodeLL*);
    
    NodeLL* GetNext();
    NodeLL* GetPrev();
    
    DataType GetValue();
    
    DataType& GetAddress();
    
}; 

// A linked list is just a chain of NodeLLs
// The chain has a start and an end, and can be traced either forwards or backwards
// Other NodeLLs can be added to the chain also, either at the start or end
template <class DataType>
class LinkedList { 
  private: 
    // Fields
    NodeLL<DataType>* first;
    NodeLL<DataType>* last;
    unsigned long real_size;

  public: 
    // Constructor
    LinkedList(); // Default constructor, contains no NodeLLs
    
    // Public Functions
    NodeLL<DataType>* GetFirst();
    NodeLL<DataType>* GetLast();
    
    void SetFirst(NodeLL<DataType>*);
    void SetLast(NodeLL<DataType>*);
    
    void Append(DataType); // Add a new NodeLL containing some value of type DataType
                           // Add to the END of the list
    
    void Prepend(DataType); // Add a new NodeLL containing some value of type DataType
                            // Add to the BEGINNING of the list
                            
    void Remove(NodeLL<DataType>*);
    
    unsigned long GetSize();
    
    ~LinkedList(); // Deconstructor, free all memory
    
}; 

#endif