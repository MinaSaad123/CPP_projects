#include <iostream>
#include <string>

int main()
{
	//direct initialization
	std::string str1("string");
	std::string str2(str1);
	std::string str3(10, 'c');

	//copy initialization
	std::string str4 = str1;
	std::string s5 = std::string(10, 'c'); // copy initialization; s8 is cccccccccc


	//there are three restriction in using initialization.
	//first one
	class Example
	{
		int x = 0;      // okay
		int y{ 0 };     // okay
		// int z(0);    // not allowed inside class
	};

	//second one : copy initialization takes one initializer.
	//string s = "hi", "bye"; // error: too many initializers

	//third one : list initializer should be enclosed in curly brackets not round.
	//vector<string> v2("a", "an", "the"); // error

	//cannot jump cross initialization
	switch (10)
	{
	case true:
		// this switch statement is illegal because these initializations might be bypassed
		//std::string file_name; // error: control bypasses an implicitly initialized variable
		//int ival = 0; // error: control bypasses an explicitly initializedvvariable
		int jval; // ok: because jval is not initialized
		break;
	case false:
		// ok: jval is in scope but is uninitialized
	}

	// . . .
	goto end;
	//int ix = 10; // error: goto bypasses an initialized variable definition
end:
	// error: code here could use ix but the goto bypassed its declaration
	//ix = 42;

	return 0;
}