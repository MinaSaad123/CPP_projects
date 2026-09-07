#include <iostream>

int main()
{
	//sizeof expr
	int i = 0;
	int* ptr = &i;

	sizeof i;
	sizeof *ptr; //it doesn't makes a problem

	//sizeof (type)
	sizeof(int);

	return 0;
}