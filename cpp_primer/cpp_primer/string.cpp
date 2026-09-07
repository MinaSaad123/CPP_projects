//#include <iostream>
//#include <string>
//
//int main()
//{
//	using std::string;
//
//	string s1;
//	//getline takes the whole line until newline
//	getline(std::cin, s1); //new line isn't stored in string variable.
//	std::cout << s1;
//
//	s1.empty(); //return TRUE if it is not empty.
//	s1.size(); //return the length of string.
//
//	string::size_type x = string("c++").size(); //size_type is companion types
//
//	//adding string literls, string object should be in the left side.
//	string s2 = s1 + ", "; // ok: adding a string and a literal
//	//string s3 = "hello" + ", "; // error: no string operand
//	string s4 = s1 + ", " + "world"; // ok: each + has a string operand
//	//string s5 = "hello" + ", " + s2; // error: can't add string literals
//	
//
//	//subscripting the string.
//	if (!s4.empty())
//	{
//		s4[0] = toupper(s4[0]);
//	}
//
//	//how to use deal with c-style character string when we use a string class in c++.
//	const char* str = s4.c_str();
//
//	return 0;
//}