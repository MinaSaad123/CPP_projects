#include <iostream>
#include <set>
#include <map>
using namespace std;


int main()
{
	//value_type = pair<const key_type, mapped_type>
	//mapped_type is associated with the map only.
	//in set value_type is key_type

	set<string>::value_type v1; // v1 is a string
	set<string>::key_type v2; // v2 is a string
	map<string, int>::value_type v3; // v3 is a pair<const string, int>
	map<string, int>::key_type v4; // v4 is a string
	map<string, int>::mapped_type v5; // v5 is an int

	//iterator returned from map is value_type pair.
	//iterator returned from set is a value_type "const key_type"

	return 0;
}