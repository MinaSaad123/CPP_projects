#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	//insert
	vector<string> svec1, svec2;
	svec1.insert(svec1.begin(), "hello"); //equalivant to push_back("hello");
	svec1.insert(svec1.end(), 10, "hello");
	svec2.insert(svec2.end(), svec1.end() - 2, svec1.end()); //take the last two elements in the end of vec2
	svec2.insert(svec2.end(), { "mina", "saad", "nazeer" }); //we can use initializer list
	
	//Using the Return from insert
	list<string> lst; string word;
	auto iter = lst.begin();
	while (cin >> word)
		iter = lst.insert(iter, word); // same as calling push_front
	//=======================================================================================================

	//emplace--> construct an object in in container memory directory.

	return 0;
}