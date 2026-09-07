#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;

int main()
{
	//forward list has special operations cuz it can't go back
	forward_list<string> flst{ "mina", "saad", "nazeer" };

	flst.emplace_after(flst.before_begin());
	flst.emplace_after(flst.begin());


	return 0;
}