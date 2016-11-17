#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <iostream>

using namespace std;

// NodeHM holds a hashable string, and a DataType
// if you want to store strings and nothing else, there is a constructor for strings
template <class DataType>
class NodeHM {
    private:
        // Fields
        string key; // hashable string 
        DataType data; // data to be stored, can also be the string
        NodeHM<DataType>* next;
        NodeHM<DataType>* prev;
    
    public:
        // Constructor
        NodeHM(string, DataType);
        
        // Setters
        void SetNext(NodeHM*);
        void SetPrev(NodeHM*);
        
        // Getters
        NodeHM* GetNext();
        NodeHM* GetPrev();
        string GetKey();
        DataType GetData();
        
        DataType& GetAddress();
};

template <class DataType>
class HashMap{
    private:
        // Fields
        NodeHM<DataType>** array; // Points to an array of NodeHM*
        unsigned long real_size; // how many nodes are within our hash map, not counting null ptrs
        unsigned long array_size = 10000;
        
    public:
        // Constructor
        HashMap(); // allocate all memory, but do not have any values in yet
        
        // Setter
        void NewArray(); // a helper for set, resizes hash map when we start to fill up
        void Set(string, DataType); // find index by hashing string, insert datatype
        // insert by making a new NodeHM, and pointing to it, make sure new NodeHM points to a NodeHM aswell
        
        // Getter
        NodeHM<DataType>* Get(string); // return the NodeHM that has given string
                           // will hash the string, and search through linked list for string
        NodeHM<DataType>* Get(unsigned long); // return node* at index
        
        bool Exists(string); // returns true if key exists with string as key.
        
        void Remove(NodeHM<DataType>* &node);
        
        bool IsEmpty(); // return true if hash map is empty
        
        unsigned long GetSize();
        
        unsigned long GetArraySize();
        
        unsigned long Hash(string); // hashes a string into a short int, the int is within the bounds of array
        
        ~HashMap(); // has to free up all the NodeHMs, and the array
        
};

#endif