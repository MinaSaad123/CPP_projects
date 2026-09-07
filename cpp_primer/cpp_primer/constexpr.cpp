//#include <iostream>
//int Gval = 0;
//int getSize()
//{
//	return 4;
//}
//
//constexpr int getSize_v2()
//{
//	return 4;
//}
//int main()
//{
//	//what is the meaning of constant expression?
//	//is an expression whose value cannot change and that can be evaluated at compile time
//	
//	int val1 = 12; //is not constant expression.
//	const int val2 = 12; // is constant expression.
//	const int val3 = getSize(); // not constant expression cuz the value is evaluated at the runtime.
//	//so that constant expression is known throughout the types and initializers.
//
//	//because the initializer could be complex so we cannot for certain know if it is constant or not ,so c++ provide a constexpr
//	constexpr int val4 = getSize_v2(); //constant expression cuz the function is constexpr specifier.
//	//constexpr int* val = &val1; //it's not constant expression cuz val1 address isn't constant.
//	constexpr int* val5 = &Gval; // const expression cuz global variables address is fixed
//	//despite of appearance, constexpr imposes a top-level const.
//	
//	
//	return 0;
//}