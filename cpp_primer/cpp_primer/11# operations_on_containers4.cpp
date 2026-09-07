#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	list<string> slst{ "mina", "saad", "nazeer" }	;
	
	//erase operations on sequentional containers
	slst.pop_back();
	slst.pop_front();
	slst.erase(slst.begin());
	slst.erase(slst.begin(), slst.end()); // that equal slst.clear();
	

	return 0;
}