#include <iostream>
#include <set>
#include <map>
using namespace std;

//class sales_data
class Sales_data
{
public:
	int data;
	
	Sales_data() { ; }
};

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.data < rhs.data;
}

int main()
{
	//compareIsbn is actually a function which is should pass to bookstore.
	multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	
	return 0;
}