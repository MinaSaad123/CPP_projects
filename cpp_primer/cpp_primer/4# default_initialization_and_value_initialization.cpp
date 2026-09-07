#include <iostream>
using namespace std;

int main()
{
	//default initialization with new operator.
	
	//[class type]
	//default initialzation and value initialzation will not differ.
	string* ps1 = new string; // default initialized to the empty string
	string* ps = new string(); // value initialized to the empty string

	//[built-in type]
	//default initialzation will be garabage.
	//value initialization will be assign to zero.
	int* pi1 = new int; // default initialized; *pi1 is undefined
	int* pi2 = new int(); // value initialized to 0; *pi2 is 0
	
	return 0;
}