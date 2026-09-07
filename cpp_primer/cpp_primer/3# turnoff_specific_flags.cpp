#include <iostream>

int main()
{
	std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);

}