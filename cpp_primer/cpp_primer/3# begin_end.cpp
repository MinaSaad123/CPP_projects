#include <iostream>
#include <list>
int main()
{
	std::list<std::string> a = { "Milton", "Shakespeare", "Austen" };
	// type is explicitly specified
	std::list<std::string>::iterator it1 = a.begin();
	std::list<std::string>::const_iterator it2 = a.begin();

	const std::string str1;
	//even begin return iterator but if str1 is const object not plain then the return is const_iterator
	auto iter3 = str1.begin(); 
	
	return 0;
}