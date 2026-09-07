#include <iostream>
#include <algorithm>	
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	vector<int> vec; // empty vector
	auto it = back_inserter(vec); // assigning through it adds elements to
	*it = 42; // vec now has one element with value 42

	//this method append ten elements to the container
	fill_n(back_inserter(vec), 10, 10);



	return 0;
}