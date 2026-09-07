#include <iostream>
#include <algorithm>	
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	//read-only algorithms like (find-find_if-cout-accumulate) takes one sequence
	//we can use find to search in build-in-array cuz iterators acts like a pointers, also can iterate in container regardless what is it's type
	vector<int> vec1(10, 0);
	vector<string> vec2(10, "mina");

	//find
	int val = 10;
	auto result = find(vec1.cbegin(), vec1.cend(), val);
	std::cout << "the value" << val << (result == vec1.cend()) ? "is not present" : "is present";
	
	//accumulate
	int result2 = accumulate(vec1.cbegin(), vec1.cend(), 0);
	//[NOTE] accumulate's third argument should always be the same type of the container type.
	string sum = accumulate(vec2.cbegin(), vec2.cend(), string("")); //we cannot do that with const char* cuz it has no + operator.

	//read-only algorithms like equal take two sequences
	//equal assume that the two sequences are at least as large at the first sequence
	const char* str1 = "mina";
	string str2 = "mina saad";
	bool condition = equal(str1, str1 + strlen(str1), str2.begin());

	return 0;
}