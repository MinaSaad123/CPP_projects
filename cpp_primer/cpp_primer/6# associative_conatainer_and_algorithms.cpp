#include <iostream>
#include <set>
#include <map>
using namespace std;


int main()
{
	//cuz the returned iterator key_type is const we cannot use with reorder and write algorithms
	//we can use read algorithms with the associative container but it is a bad idea cuz read algorithms search by sequence and associative container can find the element faster.
	return 0;
}