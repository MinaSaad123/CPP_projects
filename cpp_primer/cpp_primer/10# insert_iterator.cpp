#include <iostream>
#include <iterator>
#include <algorithm>	
#include <vector>
#include <list>
using namespace std;

int main()
{
	//there are three types of iterators in iterator library
	//insert iterator
	//reverse iterators
	//stream iterator
	//move iterator

	//[insert iterator]
	//back_inserter -> use push_back.
	//front_inserter -> use push_front.
	//inserter -> use insert.
	//[NOTE] with limitation that we cannot use iterators if the corrsponding container operation is not exist.
	
	//operations on insert iterator
	//inserter
	vector<int> ivec{ 1,2,3,4 };
	auto it = inserter(ivec, ivec.end());
	*it = 5;
	/* you can consider it equal to
	 * it = insert(it, 5);
	 * it++;
	 */

	//front_inserter
	list<int> lst = { 1,2,3,4 };
	list<int> lst2, lst3; // empty lists
	// after copy completes, 1st2 contains 4 3 2 1
	copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
	// after copy completes, 1st3 contains 1 2 3 4
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));


	return 0;
}