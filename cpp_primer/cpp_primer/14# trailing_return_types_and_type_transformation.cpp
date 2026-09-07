#include <iostream>
#include <vector>
using namespace std;

// a trailing return lets us declare the return type after the parameter list is seen
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
	// process the range
	return *beg; // return a reference to an element from the range
}
int main() {

	vector<int> vi = { 1,2,3,4,5 };
	auto& i = fcn(vi.begin(), vi.end()); // fcn should return int&

	return 0;
}
