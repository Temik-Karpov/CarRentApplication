#include <iostream>  
#include <fstream>
#include <string>
#include <exception>

void start();

int main()
{
	try
	{
		start();
	}
	catch (const std::runtime_error& error)
	{
		std::cerr << error.what();
		return 1;
	}
	catch (const std::out_of_range& error)
	{
		std::cerr << error.what();
		return 1;
	}
	return 0;
}