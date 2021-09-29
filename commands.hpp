#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include "CatalogInterface.hpp"

void add(CatalogInterface& data, const std::string newCar);
void remove(CatalogInterface& data, const std::string car);
void show(CatalogInterface& data, const std::string car);
void printError(CatalogInterface& data);

#endif // !COMMANDS_HPP

