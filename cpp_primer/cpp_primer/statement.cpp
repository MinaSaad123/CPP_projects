#include <iostream>

int main()
{
	//statement is in c++ like most languages end with semicolon
	int ival = 0;
	ival + 5; // rather useless expression statement
	std::cout << ival; // useful expression statement

	//null statement.
	; // is useful when the language needs a statement BUT the program not.
	// read until we hit end-of-file or find an input equal to sought
	char s, sought = 'A';
	while (std::cin >> s && s != sought)  
		; //null statement (null statement should be commented), if null statement is not in good situation then we call it extraneous null statement.
	
	//compound statement
	//are used when the language requires a single statement but the logic of our program needs more than one.For example, the body of a while

	return 0;
}