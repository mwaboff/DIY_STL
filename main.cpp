#include <iostream> // strings
#include "Map/map_dynamic_array.h" // MapDA
#include "Map/map_hash_map.h" // MapHM
#include "Map/map_linked_list.h" // MapLL
#include "Set/set_dynamic_array.h" // SetDA
#include "Set/set_linked_list.h" // SetLL
#include "Set/set_hash_map.h" // SetHM
#include "MultiSet/dynamic_array_mset.h" // MS_DA
#include "MultiSet/linked_list_mset.h" // MS_LL
#include "MultiSet/hash_map_mset.h" // MS_HM
#include "MultiMap/dynamic_array_mmap.h"
#include "MultiMap/linked_list_mmap.h"
#include "MultiMap/hash_map_mmap.h"
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>

int main(){
    
    MapDA map_da = MapDA();
    MapLL map_ll = MapLL();
    MapHM map_hm = MapHM();
    
    SetDA set_da = SetDA();
    SetLL set_ll = SetLL();
    SetHM set_hm = SetHM();
    
    MS_DA mset_da = MS_DA();
    MS_LL mset_ll = MS_LL();
    MS_HM mset_hm = MS_HM();
    
    MultiMapDA mmap_da = MultiMapDA();
    MultiMapLL mmap_ll = MultiMapLL();
    MultiMapHM mmap_hm = MultiMapHM();
    
    // R E A D   F R O M   S E T S
    ifstream infile;
    infile.open("sets");
    string line;
    while (getline(infile, line))
    {
        mset_da.insert(line);
        mset_ll.insert(line);
        mset_hm.insert(line);
    }
    infile.close();
    
    // R E A D   F R O M   R E S U L T S
    ifstream otherfile;
    otherfile.open("results");
    while(getline(otherfile, line)){
        int index = line.find(" ");
        string key = line.substr(0, index);
        string number_string = line.substr(index);
        int number = stoi(number_string);
        map_da.set(key, number);
        map_ll.set(key, number);
        map_hm.set(key, number);
    }
    otherfile.close();
    
    // A S S E R T S
    ifstream checkfile;
    checkfile.open("results");
    while(getline(checkfile, line)){
        int index = line.find(" ");
        string key = line.substr(0, index);
        line = key;
        assert(mset_da.count(line) == map_ll[line]);
        assert(mset_ll.count(line) == map_hm[line]);
        assert(mset_hm.count(line) == map_da[line]);
    }
    
    /*
    
    // S T R E S S   T E S T I N G
    
    string str;
    
    cout << "Inserting 10,000 elements" << endl;
    for(unsigned long i = 0; i < 10000; i++){
        string number;
        stringstream strstream;
        strstream << i;
        strstream >> number;
        
        str = "key" + number;
        
        map_da.set(str, i);
        map_ll.set(str, i);
        map_hm.set(str, i);
        
        
        
        mmap_da.set(str, i);
        mmap_ll.set(str, i);
        mmap_hm.set(str, i);
        mmap_da.set(str, i);
        mmap_ll.set(str, i);
        mmap_hm.set(str, i);
        mmap_da.set(str, i);
        mmap_ll.set(str, i);
        mmap_hm.set(str, i);
        
        set_da.insert(str);
        set_ll.insert(str);
        set_hm.insert(str);
        
        mset_da.insert(str);
        mset_ll.insert(str);
        mset_hm.insert(str);
        mset_da.insert(str);
        mset_ll.insert(str);
        mset_hm.insert(str);
        mset_da.insert(str);
        mset_ll.insert(str);
        mset_hm.insert(str);
    }
    
    cout << "Running some tests, and removing those elements" << endl;
    for(long i = 9999; i >= 0; i--){
        string number;
        stringstream strstream;
        strstream << i;
        strstream >> number;
        
        str = "key" + number;
        
        map_da.remove(str);
        map_ll.remove(str);
        map_hm.remove(str);
        
        assert(mmap_da.count(str) == 3);
        assert(mmap_ll.count(str) == 3);
        assert(mmap_hm.count(str) == 3);
        mmap_da.removeAll(str);
        mmap_ll.removeAll(str);
        mmap_hm.removeAll(str);
        assert(mmap_da.count(str) == 0);
        assert(mmap_ll.count(str) == 0);
        assert(mmap_hm.count(str) == 0);
        
        
        assert(set_da.is_in(str) == true);
        assert(set_ll.is_in(str) == true);
        assert(set_hm.is_in(str) == true);
        set_da.remove(str);
        set_ll.remove(str);
        set_hm.remove(str);
        assert(set_da.is_in(str) == false);
        assert(set_ll.is_in(str) == false);
        assert(set_hm.is_in(str) == false);
        
        assert(mset_da.count(str) == 3);
        assert(mset_ll.count(str) == 3);
        assert(mset_hm.count(str) == 3);
        mset_da.removeOne(str);
        mset_ll.removeOne(str);
        mset_hm.removeOne(str);
        assert(mset_da.count(str) == 2);
        assert(mset_ll.count(str) == 2);
        assert(mset_hm.count(str) == 2);
        mset_da.removeAll(str);
        mset_ll.removeAll(str);
        mset_hm.removeAll(str);
        assert(mset_da.count(str) == 0);
        assert(mset_ll.count(str) == 0);
        assert(mset_hm.count(str) == 0);
    }
    
    cout << "Inserting those elements back" << endl;
    for(unsigned long i = 0; i < 10000; i++){
        string number;
        stringstream strstream;
        strstream << i;
        strstream >> number;
        
        str = "key" + number;
        
        map_da.set(str, i);
        map_ll.set(str, i);
        map_hm.set(str, i);
        assert(map_da[str] == i);
        assert(map_ll[str] == i);
        assert(map_hm[str] == i);
        
        mmap_da.set(str, i);
        mmap_ll.set(str, i);
        mmap_hm.set(str, i);
        mmap_da.set(str, i);
        mmap_ll.set(str, i);
        mmap_hm.set(str, i);
        mmap_da.set(str, i);
        mmap_ll.set(str, i);
        mmap_hm.set(str, i);
        
        set_da.insert(str);
        set_ll.insert(str);
        set_hm.insert(str);
        
        mset_da.insert(str);
        mset_ll.insert(str);
        mset_hm.insert(str);
        mset_da.insert(str);
        mset_ll.insert(str);
        mset_hm.insert(str);
        mset_da.insert(str);
        mset_ll.insert(str);
        mset_hm.insert(str);
    }
    
    */
    
    cout << "All tests passed!" << endl;
    
    return 0;
}