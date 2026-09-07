#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		//subscript here doesnt means that it is a index it denotes the mapping and the return from it is reference to size_t
		++word_count[word];
	}

	for (const auto& w : word_count) // for each element in the map
		// print the results
		cout << w.first << " occurs " << w.second
			 << ((w.second > 1) ? " times" : " time") << endl;
	return 0;
}