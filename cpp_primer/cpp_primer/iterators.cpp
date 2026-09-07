//#include <iostream>
//#include <iterator>
//#include <vector>
//
//int main()
//{
//	std::string s {std::string("Mina Saad") };
//
//	auto Sit = s.begin();
//	auto Eit = s.end();
//
//	//If the container is empty, the iterators returned by begin and end are equal —they are both off - the - end iterators
//	if (Eit == Sit)
//	{
//		std::cout << "empty";
//	}
//	std::vector<int> v;
//	std::vector<int>::size_type t = v.size();
//
//	//we use with const string and vector a const_iterator only.
//	std::vector<int>::const_iterator it1 = v.end(); // it3 can read but not write elements
//	std::vector<int>::iterator it2 = v.end();
//
//	//makes the iterator points to the middle element.
//	auto it3 = v.begin() + v.size() / 2;
//
//	auto it4 = s.begin() + (Eit - Sit) / 2;
//
//	//cend and cbegin returns always const iterator.
//	auto it5 = s.cbegin();
//
//
//	return 0;
//}