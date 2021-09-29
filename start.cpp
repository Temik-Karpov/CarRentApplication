#include <iostream>
#include <string>
#include <sstream>
#include "DataBase.hpp"
#include "parser.hpp"

void start()
{
	DataBase d1;
	int t = d1.registration();
	CatalogInterface c1;
	std::string str;
	while (std::getline(std::cin, str))
	{
		std::istringstream sstream(str);
		CommandType command = parse(sstream);
		command(c1);
	}

	if (!std::cin.eof())
	{
		throw std::runtime_error("Incorrect input");
	}

}