#include <iostream>

class Temp
{
private:
	int x;

public:
	Temp(){}
	//this how synthesized copy constructor looks like we compilere generte it
	//Temp(const Temp& temp): x(temp.x) 
	//{

	//}

	//our copy constructor implementation
	Temp(const Temp& temp) //we can get temp object whether is from const or non-const
	{
		this->x = temp.x;

	}


};

int main()
{

	return 0;
}