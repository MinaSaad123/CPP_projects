#include <iostream>

bool lengthCompare(const std::string&, const std::string&)
{
	return true;
}
//===================================================================================
//std::string::size_type sumLength(const std::string&, const std::string&);
//std::string::size_type largerLength(const std::string&, const std::string&);
//decltype(sumLength)* getFcn(const std::string&); //we can use decltype to return function data type and add to it pointer to indicate it is pointer to function
int main()
{
	bool (*pf)(const std::string&, const std::string&);
	pf = lengthCompare; // pf now points to the function named lengthCompare
	pf = &lengthCompare; // equivalent assignment: address-of operator is optional

	bool b2 = (*pf)("hello", "goodbye"); // equivalent call
	bool b3 = lengthCompare("hello", "goodbye"); // equivalent call
	//===============================================================================
	return 0;
}