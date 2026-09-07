#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;


int main()
{

	map<string, int> word_count;
	string word;
	while (cin >> word)
		++word_count[word];

		//dereferencing and subscripting an itertor yields the same 
		//except in the map, dereferencing an iterator yields a pair and subscripting yields an reference to the value
		cout << word_count["Anna"]; // fetch the element indexed by Anna; prints 1
		++word_count["Anna"]; // fetch the element and add 1 to it
		cout << word_count["Anna"]; // fetch the element and print it; prints 2



	return 0;
}