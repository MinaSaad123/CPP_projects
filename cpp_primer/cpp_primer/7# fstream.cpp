#include <iostream>
#include <fstream>

int main()
{
	std::ofstream out("example.txt");
	
	if (out)
	{
		std::cout << "the file is opened\n";
	}

	out.close();

	return 0;
}