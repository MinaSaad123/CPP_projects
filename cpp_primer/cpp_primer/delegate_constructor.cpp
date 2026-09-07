#include <iostream>

class Sales_data
{
public:
	std::string bookNo;
	unsigned units_sold;
	double revenue;

	// nondelegating constructor initializes members from corresponding arguments
	Sales_data(std::string s, unsigned cnt, double price) :
		bookNo(s), units_sold(cnt), revenue(cnt* price)
	{
	}
	// remaining constructors all delegate to another constructor
	Sales_data() : Sales_data("", 0, 0) {}
	Sales_data(std::string s) : Sales_data(s, 0, 0) {}
};

int main()
{

	return 0;
}
