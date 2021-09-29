#ifndef CATALOG_INTERFACE_HPP
#define CATALOG_INTERFACE_HPP
#include "carCatalog.hpp"

class CatalogInterface
{
private:
	CarCatalog data_;
public:
	CatalogInterface();
	void add(const Car);
	void remove(std::string& nameCar);
	void show(std::string& nameCar);
	void showAll();
};
#endif // !CATALOG_INTERFACE_HPP
