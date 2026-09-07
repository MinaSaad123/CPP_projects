#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::vector<int> vi(30);
	std::allocator<int> alloc;

	// allocate twice as many elements as vi holds
	auto p = alloc.allocate(vi.size() * 2);
	 
	//trigger move not copy.
	auto q = uninitialized_copy(make_move_iterator(vi.begin()), make_move_iterator(vi.end()), p);
	// initialize the remaining elements to 42
	

	return 0;
}