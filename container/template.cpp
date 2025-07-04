/*
 * template.cpp
 *
 *  Created on: Jul 3, 2025
 *      Author: Hp-Victus
 */

#include <iostream>
#include "container.hpp"

int main()
{
	Container<int> obj1;
	int a = 10;
	int b = 10;

	obj1.add(b);
	obj1.add(a);
	cout << "obj1 int " << obj1 << "\n";

	Container<double> obj2;
	int c = 10;
	int d = 10;

	obj2.add(c);
	obj2.add(d);
	cout << "obj1 double " << obj2 << "\n";

	return 0;
}


