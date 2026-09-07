#include <iostream>	
#include <stdexcept>

int main()
{
	//terminate is a library function guarantee that if not define any try or no appropriate catch then this function is called and program exit.
	try
	{
		throw std::runtime_error("crash");

	} catch (std::overflow_error err)
	{
		//do anything.
	}

	//types of error
	//exception: is the most generall type
	//runtime_error: problem that can be detected only in runtime.
	//range_error: result generated outside the range.
	//overflow_error: computation that overflow.
	//underflow_error: computation that underflow.
	//logic_error: error in the logic of the program.
	//domain_error: argument is not in the specfic range. like takes square root of negative numeber.
	//invalid_argument: inappropriate argument.
	//length_error: attempt to create an object larger than maximum size.
	//out_of_range: used a value outside the valid range.
	//new header define bad_alloc exception.
	//type_info define bad_cast exception.
	return 0;
}