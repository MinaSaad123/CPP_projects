#include  <iostream>
#include <vector>
using namespace std;

int main()
{
	//make_shared<t>(args) function.
	//shared_ptr<t> ptr2(ptr1) to construct an object from ptr1.
	//p = q is special to shared_ptr cuz assignment in unique_ptr is deleted.
	//p.unique() return if the use_count is one.
	//p.use_count() to return the value of use_count variable.
	auto p6 = make_shared<vector<string>>();

	shared_ptr<int> p2(new int(42)); // p2 points to an int with value 42


	return 0;
}