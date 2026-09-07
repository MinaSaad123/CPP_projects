#include <iostream>

int glVal = 3;

int main()
{
	/*
	* wide char 'L'
	* unicode char 'u, U'
	* utf-8 char 'u8'
	*/

	/* in terms:)
	* unicode character is universal standards for representing text. 
	* utf-8 character is a varaible-length encoding that stores the unicode character in 1-4 bytes.
	* wide character is a programming language-level data type used to store character in wider form than a single byte.
	*         on windows it is 16-bits.
	*		  on linux it is 32-bits.
	*/
	const char32_t* val1 = U"Mina Saad";
	const char16_t* val2 = u"Mina Saad";
	const wchar_t* val3 = L"Mina Saad";
	const char* val4 = u8"Mina Saad";

	std::cout << "unicode character:" << sizeof(char32_t) << " " << sizeof(char16_t) << std::endl;
	std::cout << "wide character:" << sizeof(wchar_t) << std::endl;
	std::cout << "utf-8 character:" << sizeof(char) << std::endl;
}