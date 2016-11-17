#include <iostream> // strings
#include <assert.h> // assert
#include "../dynamic_array.h"
#include "dynamic_array_mset.h"
#include <fstream> // ifstream
#include <string>
#include <iomanip>
using namespace std;

MS_DA::MS_DA(){
 
}

MS_DA::~MS_DA(){
    
}


void MS_DA::insert(string key){
    value.Push(key);
    return;
}


unsigned long MS_DA::count(string key){
    unsigned long counter = 0;
    for(unsigned long i = 0; i < value.GetSize(); ++i){
        if(value.Get(i) == key){
            ++counter;
        }
    }
    return counter;
}

void MS_DA::removeAll(string key){
    for(unsigned long i = 0; i < value.GetSize(); ++i){
        if(value.Get(i) == key){
            value.Remove(i);
            i--;
        }
    }
    return;
}

string MS_DA::draw_random(){
    unsigned int rand_num = rand() % value.GetSize();
    return value.Get(rand_num);
}

// This sollution is O(n) if you don't count resizes? I'm not sure which is better.
void MS_DA::removeAllEric(string key){
    /*
    string* temp = new string[value.GetAllocatedSize()];
    for(unsigned long i = 0; i < value.GetSize(); i++){
        if(value.Get(i) != key){
            temp.Push(i);
        }
    }
    delete[] value;
    value = temp;
    return;
    */
}

// is_in
bool MS_DA::is_in(string key){
    for(unsigned long i = 0; i < value.GetSize(); i++){
        if(value.Get(i) == key){
            return true;
        }
    }
    return false;
}

void MS_DA::removeOne(string key){
    for(unsigned long i = 0; i < value.GetSize(); i++){
        if(value.Get(i) == key){
            value.Remove(i);
            return;
        }
    }
}

bool MS_DA::is_empty(){
    if(value.GetSize() == 0)
        return true;
}







/*

int main(){
    MS_DA mset = MS_DA();
    
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
    
    /*
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



