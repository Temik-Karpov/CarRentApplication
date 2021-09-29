#include "carCatalog.hpp"
#include <iostream>

bool CarCatalog::empty() const
{
	if (catalog_.begin() == catalog_.end())
	{
		return true;
	}
	return false;
}

void CarCatalog::pushBack(const Car newCar)
{
	catalog_.push_back(newCar);
}

void CarCatalog::changeCar(const iterator)
{

}

CarCatalog::iterator CarCatalog::removeCar(const iterator iter)
{
	return catalog_.erase(iter);
}

CarCatalog::iterator CarCatalog::find(std::string & nameCar)
{
	for (auto i = catalog_.begin(); i != catalog_.end(); i++)
	{
		if (i->getName() == nameCar)
		{
			return i;
		}
	}
}

void CarCatalog::show()
{
	for (auto i = catalog_.begin(); i != catalog_.end(); i++)
	{
		i->info();
	}
}
