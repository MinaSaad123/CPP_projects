#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
	map<string, size_t> word_count; // empty map from string to size_t
	set<string> exclude = { "The", "But", "And", "Or", "An", "A",
							"the", "but", "and", "or", "an", "a" };

	string word;
	while(cin >> word)
		if (exclude.find(word) == exclude.end())
			++word_count[word]; // fetch and increment the counter for word




	return 0;
}