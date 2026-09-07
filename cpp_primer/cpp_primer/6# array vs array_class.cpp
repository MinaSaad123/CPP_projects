#include <iostream>
#include <list>
#include <vector>
#include <forward_list>
#include <deque>
#include <array>
using namespace std;

int main()
{
	int digs[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//int cpy[10] = digs; // error: no copy or assignment for built-in arrays
	
	array<int, 10> digits = { 0,1,2,3,4,5,6,7,8,9 };
	array<int, 10> copy = digits; // ok: so long as array types match

	return 0;
}