#include <iostream>

class Sales_data 
{

public:
    Sales_data() = default;
    Sales_data(const std::string& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p* n) 
    {
    }
    Sales_data(const std::string& s) : bookNo(s) {}
    //[NOTE] explicit is useful with constructor that takes one argument cuz implicit conversation is done when there is a one argument
    //explicit Sales_data(std::istream& is); // <-- explicit constructor //comment cuz there is not defination

    //Sales_data& combine(const Sales_data&); //comment cuz there is not defination
    std::string isbn() const { return bookNo; }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};



int main()
{
    //Sales_data item1(std::cin);  // direct initialization doesn't convert.
    //Sales_data item2 = std::cin; //copy initialization trigger implicity conversation

	return 0;
}