#include <iostream>
using namespace std;

int main()
{
	shared_ptr<string> sPtr1 (make_shared<string>()); //point to null.

	if (sPtr1 && sPtr1->empty())
	{
		*sPtr1 = "First string"; //dereference shared_ptr to assign to it
	}


	return 0;
}