//#include <iostream>
//#include <string>
//#include <cctype>
//#include <iterator>
//#include <vector>
//
//int main()
//{
//	using std::string;
//
//	string s = string("init");
//
//	//The body of a range for must not change the size of the sequence over which it is iterating
//	for (auto str : s)
//	{
//		if (islower(str))
//		{
//			std::cout << "true \n";
//		}
//	}
//
//	//there is a range constructor in vector 
//	int int_array[20] = { 1, 2, 3, 4, 5 };
//	std::vector<int> v(std::begin(int_array), std::end(int_array));
//
//	return 0;
//}