#include <iostream>
#include <algorithm>	
#include <vector>
#include <list>
#include <numeric>
using namespace std;

int main()
{
	//eliminating the duplicates with the sorting and unique.
	vector<int> ivec{ 1, 3, 1, 4, 5, 3, 5 };

	sort(ivec.begin(), ivec.end());
	auto end_unique = unique(ivec.begin(), ivec.end());
	ivec.erase(end_unique, ivec.end());
	//================================================================

	vector<string> svec{ "mina", "saad", "nazeer" };
	//sort depending on the length then alphaptical order if the length is equal.
	stable_sort(svec.begin(), svec.end());

	return 0;
}