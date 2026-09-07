#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::vector<int> vi(30);
	std::allocator<int> alloc;

	// allocate twice as many elements as vi holds
	auto p = alloc.allocate(vi.size() * 2);
	// construct elements starting at p as copies of elements in vi
	auto q = uninitialized_copy(vi.begin(), vi.end(), p);
	// initialize the remaining elements to 42
	uninitialized_fill_n(q, vi.size(), 42);
	return 0;
}