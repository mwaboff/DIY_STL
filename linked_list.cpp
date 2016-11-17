#include "linked_list.h"
#include "dynamic_array.h"
#include "pair.h"
#include <iostream>

using namespace std;


// =============================== N O D E ================================== //

// Constructor

template<class DataType>
NodeLL<DataType>::NodeLL(DataType data) {
    value = data;
    next = 0;
    prev = 0;
}

// SetNext
template<class DataType>
void NodeLL<DataType>::SetNext(NodeLL<DataType>* NodeLLPtr){
    next = NodeLLPtr;
    return;
}

// SetPrev
template<class DataType>
void NodeLL<DataType>::SetPrev(NodeLL<DataType>* NodeLLPtr){
    prev = NodeLLPtr;
    return;
}

// GetNext
template<class DataType>
NodeLL<DataType>* NodeLL<DataType>::GetNext(){
    return next;
}

// GetPrev
template<class DataType>
NodeLL<DataType>* NodeLL<DataType>::GetPrev(){
    return prev;
}

//GetValue
template<class DataType>
DataType NodeLL<DataType>::GetValue(){
    return value;
}

template<class DataType>
DataType& NodeLL<DataType>::GetAddress(){
    return value;
}


// ========================== L i n k e d = L i s t ========================= //

// Constructor
template<class DataType>
LinkedList<DataType>::LinkedList(){
    first = 0;
    last = 0;
    real_size = 0;
}

// Public Functions

// SetFirst
template<class DataType>
void LinkedList<DataType>::SetFirst(NodeLL<DataType>* NodeLLPtr){
    first = NodeLLPtr;
}

// SetLast
template<class DataType>
void LinkedList<DataType>::SetLast(NodeLL<DataType>* NodeLLPtr){
    last = NodeLLPtr;
}

// GetFirst
template<class DataType>
NodeLL<DataType>* LinkedList<DataType>::GetFirst(){
    return first;
    
}

// GetLast
template<class DataType>
NodeLL<DataType>* LinkedList<DataType>::GetLast(){
    return last;
}

// Append
template<class DataType>
void LinkedList<DataType>::Append(DataType data){
    NodeLL<DataType>* newNodeLL = new NodeLL<DataType>(data);
    
    // Base Case
    if (first == 0){
        first = newNodeLL;
        last = newNodeLL;
        return;
    }
    NodeLL<DataType>* temp = last;
    last = newNodeLL;
    newNodeLL->SetPrev(temp);
    temp->SetNext(newNodeLL);
    real_size++;
    return;
}

// Prepend
template<class DataType>
void LinkedList<DataType>::Prepend(DataType data){
    NodeLL<DataType>* newNodeLL = new NodeLL<DataType>(data);
    // Base Case
    if (first == 0){
        first = newNodeLL;
        last = newNodeLL;
        return;
    }
    
    NodeLL<DataType>* temp = first;
    first = newNodeLL;
    newNodeLL->SetNext(temp);
    temp->SetPrev(newNodeLL);
    real_size++;
    return;
    
}

// Deconstructor
template<class DataType>
LinkedList<DataType>::~LinkedList(){
    NodeLL<DataType>* temp1 = first;
    if(temp1 == 0){
        return;
    }
    NodeLL<DataType>* temp2 = temp1->GetNext();
    while(temp2 != 0){
        delete temp1;
        temp1 = temp2;
        temp2 = temp1->GetNext();
    }
    delete temp1;
}

// Remove
template<class DataType>
void LinkedList<DataType>::Remove(NodeLL<DataType>* node){
    
    if(node->GetPrev() == 0 && node->GetNext() == 0){ // if NodeLL is the only one in the list
        first = 0;
        last = 0;
        delete node;
    } else if(node->GetPrev() == 0){ // if NodeLL is first in list
    
        first = node->GetNext();
        if(first != 0){ // if our new first NodeLL is not null
            first->SetPrev(0);
        }
        delete node;
    } else if(node->GetNext() == 0){ // if NodeLL is last in list
    
        last = node->GetPrev();
        if(last != 0){ // if our new last NodeLL is not null
            last->SetNext(0);
        }
        delete node;
    } else { // if NodeLL is somewhere in the middle of list
        
        node->GetPrev()->SetNext(node->GetNext());
        node->GetNext()->SetPrev(node->GetPrev());
        delete node;
    }
    real_size--;
    return;
}

template<class DataType>
unsigned long LinkedList<DataType>::GetSize(){
    return real_size;
}

template class LinkedList<string>;
template class LinkedList<int>;
template class LinkedList< Pair<int> >;
template class LinkedList< Pair< LinkedList<int> > >;
template class LinkedList<Pair<LinkedList<int> >* >;
template class LinkedList<Pair<LinkedList<int>* >* >;
template class LinkedList<Pair<DynamicArray<int>* >* >;
template class NodeLL<string>;
template class NodeLL<int>;
template class NodeLL< Pair<int> >;
template class NodeLL< Pair< LinkedList<int> > >;
template class NodeLL< Pair<LinkedList<int> >* >;
template class NodeLL< Pair<LinkedList<int>* >* >;
template class NodeLL< Pair<DynamicArray<int>* >* >;


// Testing
/*

int main(){
    
    LinkedList<string> list = LinkedList<string>();
    list.Append("Doggo");
    list.Append("Edwin likes Doggo");
    list.Prepend("Turtle");
    list.Prepend("Doggy");
    list.Append("Doggy likes Turtle");
    list.Prepend("Doggy is Doggo's son");
    list.Append("Doggo says <Don't talk to me or my son ever again>");


    
    
    return 0;
}
*/
