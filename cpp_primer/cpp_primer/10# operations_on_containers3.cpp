#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	vector<string> svec{ "mina" };
	//Operations to Access Elements in a Sequential Container
	//back() front() subscript and at() return a referenece
	svec.back() = 1;
	//or we can bind using auto
	auto& val = svec.back();

	//at vs subscript[]
	//at when we access wrong index it throws out of range exceptions unlike subscript
	cout << svec[0]; // run-time error: there are no elements in svec!
	cout << svec.at(0); // throws an out_of_range exception


	return 0;
}