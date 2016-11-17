all: stl_world

#puts everything in place
stl_world:  main.o dynamic_array.o hash_map.o linked_list.o set_dynamic_array.o set_hash_map.o set_linked_list.o dynamic_array_mset.o hash_map_mset.o linked_list_mset.o map_dynamic_array.o map_hash_map.o map_linked_list.o dynamic_array_mmap.o linked_list_mmap.o hash_map_mmap.o
	g++ main.o dynamic_array.o hash_map.o linked_list.o set_dynamic_array.o set_hash_map.o set_linked_list.o dynamic_array_mset.o hash_map_mset.o linked_list_mset.o map_dynamic_array.o map_hash_map.o map_linked_list.o dynamic_array_mmap.o linked_list_mmap.o hash_map_mmap.o -o stl_world -std=c++11

#main
main.o: main.cpp
	g++ -c main.cpp -std=c++11

#templates
dynamic_array.o: dynamic_array.cpp
	g++ -c dynamic_array.cpp -std=c++11

hash_map.o: hash_map.cpp
	g++ -c hash_map.cpp -std=c++11

linked_list.o: linked_list.cpp
	g++ -c linked_list.cpp -std=c++11

#set
set_dynamic_array.o: Set/set_dynamic_array.cpp
	g++ -c Set/set_dynamic_array.cpp -std=c++11

set_linked_list.o: Set/set_linked_list.cpp
	g++ -c Set/set_linked_list.cpp -std=c++11

set_hash_map.o: Set/set_hash_map.cpp
	g++ -c Set/set_hash_map.cpp -std=c++11

#multiset
dynamic_array_mset.o: MultiSet/dynamic_array_mset.cpp
	g++ -c MultiSet/dynamic_array_mset.cpp -std=c++11

hash_map_mset.o: MultiSet/hash_map_mset.cpp
	g++ -c MultiSet/hash_map_mset.cpp -std=c++11

linked_list_mset.o: MultiSet/linked_list_mset.cpp
	g++ -c MultiSet/linked_list_mset.cpp -std=c++11

#map
map_dynamic_array.o: Map/map_dynamic_array.cpp
	g++ -c Map/map_dynamic_array.cpp -std=c++11

map_linked_list.o: Map/map_linked_list.cpp
	g++ -c Map/map_linked_list.cpp -std=c++11

map_hash_map.o: Map/map_hash_map.cpp
	g++ -c Map/map_hash_map.cpp -std=c++11

#multimap
dynamic_array_mmap.o: MultiMap/dynamic_array_mmap.cpp
	g++ -c MultiMap/dynamic_array_mmap.cpp -std=c++11
	
hash_map_mmap.o: MultiMap/hash_map_mmap.cpp
	g++ -c MultiMap/hash_map_mmap.cpp -std=c++11

linked_list_mmap.o: MultiMap/linked_list_mmap.cpp
	g++ -c MultiMap/linked_list_mmap.cpp -std=c++11

#variables
%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

#cleans the project
clean:
	rm *.o stl_world