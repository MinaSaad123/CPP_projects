#include <iostream> //input output stream

int main()
{
	//iostate 
	//1.convey information about the state of a stream
	//2.is used as a collection of bits.

	//input and output library define a four constexpr value of std::iostate
	//1.badbit: it is usualy to use stream once badbit is set
	//2.failbit: is set to indicate there is a problem in reading such reading a character instead of integer
	//3.goodbit: which guarantee to indicate no failure is happened
	//4.eofbit: indicates that we are at the end of file.


	int i;

	//case 1:
	//std::cin >> i;
	//if (std::cin.rdstate() == std::ios::goodbit) //(std::cin.good())
	//{
	//	std::cout << "the stream is good\n";
	//}

	////case 2:
	//std::cin >> i;
	// 
	//if (std::cin.rdstate() == std::ios::failbit) //equal (std::cin.fail())
	//{
	//	std::cout << std::endl << "failbit";
	//}

	////case 3:
	//while (std::cin >> i)
	//	;
	////[NOTE] Reaching end-of-file sets both eofbit and failbit
	//if (std::cin.rdstate() == (std::ios::eofbit | std::ios::failbit))
	//{
	//	std::cout << "\neof";
	//}

	////or
	//if (std::cin.eof())
	//{
	//	std::cout << "\neof";
	//}


	return 0;
}