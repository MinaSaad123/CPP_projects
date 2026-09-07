#include <iostream>
#include <algorithm>	
#include <vector>
#include <list>
#include <numeric>
using namespace std;

int main()
{
	vector<string> svec{ "mina", "saad", "nazeer" };

	//lambda expressions
	//[captures list] (parameters) -> return type {  return val;}
	auto f = [] { return 42; }; //we can omit the paranetheses with parameters with the return type

	//if generic algorithm his predictors takes only one parameter but we need two parameters then we can solve this problem with lambda
	// get an iterator to the first element whose size() is >= sz
	int sz = 5;

	auto wc = find_if(svec.begin(), svec.end(), 
		[sz](const string& a)
			{ return a.size() >= sz; });

	for_each(wc, svec.end(), [](const string& str1) { std::cout << str1; });
	//[NOTE] lambda can use static local variables and global variables directly without the need to be in the capture list

	//types of capturing
	//[implicit, explicit]
	//in implicit you make the compiler infer the value or reference you use [=] capture by value [&] capture by reference
	//explicit capture specific value [x] or reference [&x]

	//capture value only you take you cannot change it except using with mutable keyword
	auto f = [sz]() mutable { return ++sz; };

	return 0;
}