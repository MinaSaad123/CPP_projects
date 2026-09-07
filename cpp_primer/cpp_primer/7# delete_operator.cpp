#include <iostream>
using namespace std;

int main()
{
	int i, * pi1 = &i, * pi2 = nullptr;
	double* pd = new double(33), * pd2 = pd;
	//delete i; // error: i is not a pointer
	//delete pi1; // undefined: pi1 refers to a local
	delete pd; // ok
	//delete pd2; // undefined: the memory pointed to by pd2 was already freed
	delete pi2; // ok: it is always ok to delete a null pointer
	return 0;
}