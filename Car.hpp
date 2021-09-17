#ifndef CAR_HPP
#define CAR_HPP
#include <string>

class Car
{
private:
	std::string name;
	enum Type
	{
		Sedan,
		Compartment,
		Pikap,
		SUV, 
		Ñonvertible
	};
	double maxSpeed;
	double fuelTankCapacity;
public:

};

#endif // !CAR_HPP
