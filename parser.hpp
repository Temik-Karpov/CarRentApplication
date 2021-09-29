#ifndef PARSER_HPP
#define PARSER_HPP
#include <functional>
#include <unordered_map>
#include <string>
#include "CatalogInterface.hpp"

using CommandType = std::function<void(CatalogInterface& data)>;
CommandType parseAdd(std::istringstream& sstream);
CommandType parseDelete(std::istringstream& sstream);
CommandType parseShow(std::istringstream& sstream);
std::string readName(std::istringstream& sstream);
CommandType parse(std::istringstream& sstream);

void skipSpaces(std::istringstream& sstream);

#endif // !PARSER_HPP

