#include "parser.hpp"
#include <sstream>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <string>
#include "commands.hpp"


CommandType parseAdd(std::istringstream & sstream)
{
	const std::string name = readName(sstream);
	if (sstream.fail())
	{
		return std::bind(&printError, std::placeholders::_1);
	}
	std::string str;
	std::getline(sstream >> std::ws, str);
	if (!str.empty())
	{
		return std::bind(&printError, std::placeholders::_1);
	}

	if (name.empty() || !sstream.eof())
	{
		return std::bind(&printError, std::placeholders::_1);
	}
	else
	{
		return std::bind(&add, std::placeholders::_1, name);
	}

}

/*CommandType parseDelete(std::istringstream & sstream)
{
	const std::string name = readName(sstream);
	if (sstream.fail())
	{
		return std::bind(&printError, std::placeholders::_1);
	}
	std::string data;
	std::getline(sstream >> std::ws, data);

	if (name.empty() || !data.empty())
	{
		return std::bind(&printError, std::placeholders::_1);
	}
	return std::bind(&remove, std::placeholders::_1, name);
}*/

CommandType parseShow(std::istringstream & sstream)
{
	const std::string name = readName(sstream);
	if (sstream.fail())
	{
		return std::bind(&printError, std::placeholders::_1);
	}
	std::string data;
	std::getline(sstream >> std::ws, data);

	if (name.empty() || !data.empty())
	{
		return std::bind(&printError, std::placeholders::_1);
	}

	return std::bind(&show, std::placeholders::_1, name);

}

std::string readName(std::istringstream & sstream)
{
	skipSpaces(sstream);

	if (sstream.peek() != '"')
	{
		return "";
	}

	sstream.get();

	std::string name;
	std::string tmp;

	while (std::getline(sstream, tmp, '"'))
	{
		name += tmp;

		if (name.back() != '\\')
		{
			break;
		}
		name.pop_back();
		name.push_back('"');
	}

	if (!sstream)
	{
		return "";
	}
	return name;

}

CommandType parse(std::istringstream & sstream)
{
	std::string commands;
	sstream >> commands;
	if (sstream.fail())
	{
		return std::bind(&printError, std::placeholders::_1);
	}

	using TypeMap = std::unordered_map<std::string, CommandType(*) (std::istringstream&)>;
	TypeMap command
	{
	  {"add", &parseAdd},
	  {"delete", &parseDelete},
	  {"show", &parseShow},
	};

	TypeMap::iterator iter = command.find(commands);
	if (iter == command.end())
	{
		return std::bind(&printError, std::placeholders::_1);
	}
	else
	{
		return iter->second(sstream);
	}

}

void skipSpaces(std::istringstream & sstream)
{
	while (!sstream.eof() && (sstream.peek() == ' ' || sstream.peek() == '\t'))
	{
		sstream.get();
	}
}
