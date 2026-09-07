#include <iostream>

int main()
{
	//comma as seperator
	switch (1)
	{
	//case 1,2,3,4,5: //it gives CE
		std::cout << "it works";
	}

	// comma as operator
	switch (1)
	{
	case (1, 2, 3, 4, 5):
		std::cout << "it works";
	}
	return 0;
}