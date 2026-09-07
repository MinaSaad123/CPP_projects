#include <iostream>
#include <algorithm>	
#include <vector>
#include <list>
#include <numeric>
using namespace std;

int main()
{
	int a1[] = { 0,1,2,3,4,5,6,7,8,9 };
	int a2[sizeof(a1) / sizeof(*a1)]; // a2 has the same size as a1
	// ret points just past the last element copied into a2
	auto ret = copy(begin(a1), end(a1), a2); // copy a1 into a2

	//
	list<int> ilst{ 1,3,35 };
	vector<int> ivec;

	//replace every 1 within the range with 40
	replace(ilst.begin(), ilst.end(), 1, 40);

	//replace every 1 within the first range with 40 and copy that in vector without changing the list valuesa
	replace_copy(ilst.begin(), ilst.end(), back_inserter(ivec), 1, 40);
	


	return 0;
}