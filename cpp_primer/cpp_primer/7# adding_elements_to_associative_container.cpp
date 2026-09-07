#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;


int main()
{
	//adding to [set]
	vector<int> ivec = { 2,4,6,8,2,4,6,8 }; // ivec has eight elements
	set<int> set2; // empty set
	set2.insert(ivec.cbegin(), ivec.cend()); // set2 has four elements
	set2.insert({ 1,3,5,7,1,3,5,7 }); // set2 now has eight elements

	//adding to [map]
	map<string, int> word_count;
	string word;
	while (cin >> word)
		++word_count[word];

	//methods to insert.
	word_count.insert({ word, 1 });
	word_count.insert(make_pair(word, 1));
	word_count.insert(pair<string, size_t>(word, 1));
	word_count.insert(map<string, size_t>::value_type(word, 1));
	//if element is already exist in the map then it will return pair<iterator pointer to pair, false
	//that doesnt not applied to multimap.
	return 0;
}