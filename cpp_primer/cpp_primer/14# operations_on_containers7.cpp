#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	//after adding or removing iterators-reference-pointers can be invalid
	
	//vector
	//reallocation : makes i-r-p invalid
	//	if no reallocation then:)
	//		before the insertion is valid but after is invalid. 
	//When erasing :
	//Iterators to removed elements ? invalid
	//	Iterators before erase point ? valid
	//	Iterators after erase point ? invalid
	//	The end() iterator ? always invalid


	//end() is fast cuz we need to use it a lot of time cuz iterator returned from end after insertion or delation could be invalid.
	return 0;
}