#include "hash_map.h"
#include "dynamic_array.h"
#include <iostream>

using namespace std;

// ========================== N o d e ======================================== //

// Constructor
template<class DataType>
NodeHM<DataType>::NodeHM(string aKey, DataType aData){
    key = aKey;
    data = aData;
    next = 0;
    prev = 0;
}

// SetNext
template<class DataType>
void NodeHM<DataType>::SetNext(NodeHM<DataType>* NodeHM){
    next = NodeHM;
    return;
}

// SetPrev
template<class DataType>
void NodeHM<DataType>::SetPrev(NodeHM<DataType>* NodeHM){
    prev = NodeHM;
    return;
}

// GetNext
template<class DataType>
NodeHM<DataType>* NodeHM<DataType>::GetNext(){
    return next;
}

// GetPrev
template<class DataType>
NodeHM<DataType>* NodeHM<DataType>::GetPrev(){
    return prev;
}

// GetKey
template<class DataType>
string NodeHM<DataType>::GetKey(){
    return key;
}

// GetData
template<class DataType>
DataType NodeHM<DataType>::GetData(){
    return data;
}

template<class DataType>
DataType& NodeHM<DataType>::GetAddress(){
    return data;
}


// ========================== H a s h   M a p ================================ //

// Constructor
template<class DataType>
HashMap<DataType>::HashMap(){
    array = new NodeHM<DataType>* [array_size];
    real_size = 0;
    
}

// Helper for set : resize when hash map starts to get full
template<class DataType>
void HashMap<DataType>::NewArray(){
    //cout << "Inside NewArray()" << endl;
    unsigned long old_size = array_size;
    array_size *= 2;
    NodeHM<DataType>** temp_array = new NodeHM<DataType>*[array_size];
    
    // Loop through the old array, move everything to new array
    for(unsigned long i = 0; i < old_size; i++){
        NodeHM<DataType>* tempPointer = array[i]; // grab first pointer at each index
        while(tempPointer != 0){ // go through list
            NodeHM<DataType>* temp_next_holder = tempPointer->GetNext();
            unsigned long index = Hash(tempPointer->GetKey()); // hash the pointer with new hash
            NodeHM<DataType>* temp = temp_array[index];
            temp_array[index] = tempPointer;
            tempPointer->SetNext(temp);
            tempPointer->SetPrev(0);
            if(temp != 0){
                temp->SetPrev(tempPointer);
            }
            tempPointer = temp_next_holder;
        }
    }
    
    /*
    // now free up memory
    NodeHM<DataType>* temp;
    NodeHM<DataType>* next;
    for(unsigned long i = 0; i < old_size; i++){
        temp = array[i];
        while(temp != 0){
            next = temp->GetNext();
            delete temp;
            temp = next;
        }
    }
    */
    delete[] array;
    array = temp_array;
    return;
}

// Set
template<class DataType>
void HashMap<DataType>::Set(string aKey, DataType aData){
    NodeHM<DataType>* newNodeHM = new NodeHM<DataType>(aKey, aData);
    
    
    if(real_size >= array_size){
        // << "bro we need to resize this array" << endl;
        NewArray();
    }
    
    unsigned long index = Hash(aKey);
    NodeHM<DataType>* temp = array[index];
    //cout << "Inserting " << aKey << "at location " << index << endl;
    array[index] = newNodeHM;
    newNodeHM->SetNext(temp);
    if(temp != 0){
        temp->SetPrev(newNodeHM);
    }
    real_size++;
    return;
}

// Get
template<class DataType>
NodeHM<DataType>* HashMap<DataType>::Get(string aKey){
    unsigned long hash = Hash(aKey);
    NodeHM<DataType>* temp = array[hash];
    return temp;
    
}

template<class DataType>
bool HashMap<DataType>::Exists(string aKey) {
    /*NodeHM<DataType>* curr_node = Get(aKey);
    while(curr_node) {
        if(curr_node->GetKey() == aKey) {
            return true;
        }
        curr_node = curr_node->GetNext();
    }
    return false;*/
    return Get(aKey) != 0;
}

template<class DataType>
void HashMap<DataType>::Remove(NodeHM<DataType>* &node){
    if(node->GetPrev() == 0 && node->GetNext() == 0){ // if node is the only node in list
        array[Hash(node->GetKey())] = 0;
        delete node;
        real_size--;
        return;
    } else if(node->GetPrev() == 0){ // If node is first in the list
        node->GetNext()->SetPrev(0);
        array[Hash(node->GetKey())] = node->GetNext();
        delete node;
        real_size--;
        return;
    } else if(node->GetNext() == 0){ // If node is the last in the list
        node->GetPrev()->SetNext(0);
        delete node;
        real_size--;
        return;
        
    } else { // if node is somewhere in the middle of the list
        node->GetPrev()->SetNext(node->GetNext());
        node->GetNext()->SetPrev(node->GetPrev());
        delete node;
        real_size--;
        return;
    }
}

// Deconstructor
template<class DataType>
HashMap<DataType>::~HashMap(){
    NodeHM<DataType>* temp;
    NodeHM<DataType>* next;
    for(unsigned long i = 0; i < array_size; i++){
        temp = array[i];
        while(temp != 0){
            next = temp->GetNext();
            delete temp;
            temp = next;
        }
    }
    delete[] array;
}

template<class DataType>
unsigned long HashMap<DataType>::GetSize(){
    return real_size;
}

template<class DataType>
unsigned long HashMap<DataType>::GetArraySize(){
    return array_size;
}

template<class DataType>
NodeHM<DataType>* HashMap<DataType>::Get(unsigned long i){
    return array[i];
}

unsigned long MurmurHash2 ( const void * key, int len, unsigned int seed )
{
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.

	const unsigned long m = 0x5bd1e995;
	const int r = 24;

	// Initialize the hash to a 'random' value

	unsigned int h = seed ^ len;

	// Mix 4 bytes at a time into the hash

	const unsigned char * data = (const unsigned char *)key;

	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m; 
		k ^= k >> r; 
		k *= m; 
		
		h *= m; 
		h ^= k;

		data += 4;
		len -= 4;
	}
	
	// Handle the last few bytes of the input array

	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};

	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
} 

// Hash
template<class DataType>
unsigned long HashMap<DataType>::Hash(string aKey){

    /*
    unsigned long hash = 1738;
    for(unsigned long i = 0; i < aKey.length(); i++){
        hash += (hash << 3);
        hash += aKey[i];
        hash *= hash | aKey[i];
        hash *= 37;
        hash ^= 'M';
        hash ^= 'I';
        hash ^= 'K';
        hash ^= 'E';
    }
    return hash % array_size;
    */
    
    return MurmurHash2(&*aKey.begin(), aKey.length(), 1337) % array_size;
}

template<class DataType>
bool HashMap<DataType>::IsEmpty(){
    /*
    for(unsigned long i = 0; i < array_size; i++){
        if(array[i] != 0){
            return false;
        }
    }
    return true;
    */
    return real_size == 0;
}

template class HashMap<string>;
template class HashMap<int>;
template class HashMap< DynamicArray<int> >;
template class HashMap< DynamicArray<int>* >;
template class NodeHM<string>;
template class NodeHM<int>;
template class NodeHM< DynamicArray<int> >;
template class NodeHM< DynamicArray<int>* >;

/*

int main(){
    /*cout << Hash("shrek is love") << endl;
    cout << Hash("stop nerfing udyr") << endl;
    cout << Hash("a") << endl;
    cout << Hash("b") << endl;
    cout << Hash("b1") << endl;
    
    HashMap<string> hashstring = HashMap<string>();
    HashMap<int> hashint = HashMap<int>();
    hashstring.Set("shrek is life");
    hashstring.Set("queso con queso");
    hashstring.Set("andy con queso");
    hashstring.Set("Novochips");
    
    cout << hashstring.Exists("shrek is life") << endl;
    
    cout << hashstring.Get("shrek is life") << endl;
    cout << hashstring.Get("andy con queso") << endl;
    
    hashint.Set("key1", 0);
    hashint.Set("key2", 1);
    hashint.Set("key3", 2);
    
    
    return 0;
}

*/


