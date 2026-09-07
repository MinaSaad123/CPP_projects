//#include <iostream>
//
//int main()
//{
//	// reference base type should match the object base type you want him to bind to, except two cases
//	const int cval = 5;
//	double val = 5.12;
//	const int& rval = cval; //cannot change the object's value the reference bind to.
//	//int &rval2 = cval;    //compilation error cuz val is const int and we try to assign it to non-const reference.
//
//	//first exception is we can bind a const reference to a plain object
//	//example 1:
//	const double& ref1 = val;
//	//example 2:
//	const int& ref2 = val; //is an unnamed temporary object and for abbreviation we call it temporary
//	//this line is equal to
//	//const int temp = val; const int & ref2 = temp;
//	//the reference binds to temporary should be const cuz if you change it, it will be a problem(temporary object is a value stores in ram as a result of an expression).
//
//	return 0;
//}