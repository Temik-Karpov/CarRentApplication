#ifndef CAR_CATALOG_HPP
#define CAR_CATALOG_HPP
#include "Car.hpp"
#include <list>

class CarCatalog
{
private:
	std::list<Car> catalog_;
public:
	CarCatalog();
	~CarCatalog() = default;
	void addCar(Car);
	void deleteCar(Car);
	void changeCar();
	void showCar();
};
#endif // !CAR_CATALOG_HPP
