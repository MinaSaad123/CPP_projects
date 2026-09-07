#include <iostream>

int main()
{
	//convert pointer to bool
	char c = 'a';
	char* cp = &c;
	if (cp)
	while (*cp);

	//convert plain to const
	int i;
	const int& j = i; // convert a nonconst to a reference to const int
	const int* p = &i; // convert address of a nonconst to the address of a const
	// int& r = j, * q = p; // error: conversion from const to nonconst not allowed
	
	return 0;
}