#ifndef CAR_CATALOG_HPP
#define CAR_CATALOG_HPP
#include "Car.hpp"
#include <list>

class CarCatalog
{
private:
	std::list<Car> catalog_;
public:
	using iterator = std::list<Car>::iterator;
	bool empty() const;
	void pushBack(const Car);
	void changeCar(const iterator);
	iterator removeCar(const iterator iter);
	iterator find(std::string& nameCar);
	void show();
};
#endif // !CAR_CATALOG_HPP
