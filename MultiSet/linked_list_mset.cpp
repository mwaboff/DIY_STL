#include <iostream>
#include <assert.h>
#include <fstream> // ifstream
#include <string>
#include <iomanip>
#include "../linked_list.h"
#include "linked_list_mset.h"
using namespace std;

MS_LL::MS_LL(){

}

MS_LL::~MS_LL(){
 
}
 
void MS_LL::insert(string key){
    value.Append(key);
    return;
}
    
bool MS_LL::is_in(string key){
    NodeLL<string>* temp = value.GetFirst();
    while(temp != 0){
        if(temp->GetValue() == key){
        return true;
        }
        temp = temp->GetNext();
    }
    return false;
}
    
unsigned long MS_LL::count(string key){
   NodeLL<string>* temp = value.GetFirst();
   unsigned long counter = 0;
    while(temp != 0){
        if(temp->GetValue() == key){
       ++counter;
        }
        temp = temp->GetNext();
    }
    return counter;
}
    
void MS_LL::removeOne(string key){
    NodeLL<string>* temp = value.GetFirst();
    while(temp != 0){
        if(temp->GetValue() == key){
            value.Remove(temp);
            return;
        }
        temp = temp->GetNext();
    }
    return;
}
    
void MS_LL::removeAll(string key){
   NodeLL<string>* temp = value.GetFirst();
    while(temp != 0){
        if(temp->GetValue() == key){
            value.Remove(temp);
        }
        temp = temp->GetNext();
    }
    return;  
}
    
bool MS_LL::is_empty(){
    if(value.GetFirst() == 0){
        return true;
    }
   return false; 
}

string MS_LL::draw_random(){
    unsigned long random_number = rand() % value.GetSize();
    
    NodeLL<string>* temp = value.GetFirst();
    while(temp != 0){
        random_number--;
        if(random_number == 0){
            return temp->GetValue();
        }
        temp = temp->GetNext();
    }
    
    cout << "Error in MS_LL::draw_random() ran out of values" << endl;
}

/*
int main(){
    MS_LL mset = MS_LL();
    
    assert(mset.is_empty() == true);
    
    mset.insert("Edwin was here");
    mset.insert("Anita");
    mset.insert("Cheeseburger");
    mset.insert("Edwin was here");
    mset.insert("Penguin of d00m");
    mset.insert("Big Poppa");
    mset.insert("Big Poppa");
    
    assert(mset.is_empty() == false);
    assert(mset.is_in("Edwin was here") == true);
    assert(mset.is_in("Cheeseburger") == true);
    assert(mset.is_in("Ca$h Money") == false);
    
    assert(mset.count("Cheeseburger") == 1);
    assert(mset.count("Edwin was here") == 2);
    assert(mset.count("Ca$h Money") == 0);
    
    mset.removeOne("Edwin was here");
    assert(mset.count("Edwin was here") == 1);
    
    mset.removeAll("Edwin was here");
    assert(mset.count("Edwin was here") == 0);
    
    mset.removeAll("Big Poppa");
    assert(mset.is_in("Big Poppa") == false);
    assert(mset.count("Big Poppa") == 0);
    
    mset.removeAll("Penguin of d00m");
    mset.removeAll("Edwin was here");
    mset.removeAll("Anita");
    mset.removeAll("Cheeseburger");
    
    assert(mset.is_empty() == true);
    
    ifstream file;
    file.open ("MobyDick.txt");
    string word;
    while (file >> word)
    {
        int length = word.length();
	
	for (int i = 0; i < length; i++)
		if (ispunct(word[i]))
			word.erase(i, 1);

	for (int i = 0; i < length; i++)
		word[i] = tolower(word[i]);

		for (int i = 0; i < length; i++)
		if (word[i] == ' ')
			word.erase(i, 1);
        mset.insert(word);
    }
    file.close();
    
    cout << "Ishmael appears " << mset.count("ishmael") << " times." << endl;
    
    return 0;
}
*/