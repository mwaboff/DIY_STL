#include <iostream> // strings
#include <assert.h> // assert
#include <fstream> // ifstream
#include <string>
#include <iomanip>
#include "../hash_map.h"
#include "hash_map_mset.h"
using namespace std;

MS_HM::MS_HM(){

}

MS_HM::~MS_HM(){

}

void MS_HM::insert(string key){
    value.Set(key, key);
    return;
}

bool MS_HM::is_in(string key){
    NodeHM<string>* temp = value.Get(key);
    while(temp != 0){
        if(temp->GetData() == key){
            return true;
        }
        temp = temp->GetNext();
    }
    return false;
}

unsigned long MS_HM::count(string key){
    NodeHM<string>* temp = value.Get(key);
   unsigned long counter = 0;
    while(temp != 0){
        if(temp->GetData() == key){
         ++counter;
        }
        temp = temp->GetNext();
    }
    return counter;
}

void MS_HM::removeOne(string key){
    NodeHM<string>* temp = value.Get(key);
    while(temp != 0){
        if(temp->GetData() == key){
            value.Remove(temp);
            return;
        }
        temp = temp->GetNext();
    }
    return;
}

void MS_HM::removeAll(string key){
    NodeHM<string>* temp = value.Get(key);
    while(temp != 0){
        if(temp->GetData() == key){
            value.Remove(temp);
        }
        temp = temp->GetNext();
    }
    return;
}

bool MS_HM::is_empty(){
    bool result = value.IsEmpty();
    return result;
}

string MS_HM::draw_random(){
    unsigned long random_number = rand() % value.GetSize();
    for(unsigned long i = 0; i < value.GetArraySize(); i++){
        NodeHM<string>* temp = value.Get(i);
        while(temp != 0){
            random_number--;
            if(random_number == 0){
                return temp->GetData();
            }
            temp = temp->GetNext();
        }
    }
    
    cout << "Error in MS_HM::draw_random(), nothing found" << endl;
}


/*
int main(){
    MS_HM mset = MS_HM();
    
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