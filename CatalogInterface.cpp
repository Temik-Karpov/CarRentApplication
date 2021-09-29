#include "CatalogInterface.hpp"
#include <iostream>

CatalogInterface::CatalogInterface()
{
	
}

void CatalogInterface::add(const Car newCar)
{
	data_.pushBack(newCar);
}

void CatalogInterface::remove(std::string & nameCar)
{
	auto iter = data_.find(nameCar);
	data_.removeCar(iter);
}

void CatalogInterface::show(std::string & nameCar)
{
	auto iter = data_.find(nameCar);
	iter->info();	
}

void CatalogInterface::showAll()
{
	data_.show();
}
