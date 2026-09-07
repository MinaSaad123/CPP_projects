#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>	
#include <vector>
#include <list>
using namespace std;

int main()
{
	//there are three types of iterators
	//insert iterator
	//reverse iterators
	//stream iterator
	//move iterator

	//[reverse iterator]
	vector<string> svec{
		"mina" , "saad", "nazeer"
	};

	//we can use reverse iterators to arrange in the opposite  direction
	sort(svec.rbegin(), svec.rend());

	//[NOTE] there is not reverse iterators in stream or forward_list.

	return 0;
}