#ifndef CAR_HPP
#define CAR_HPP
#include <string>

class Car
{
private:
	std::string name_;
	enum Type
	{
		Sedan,
		Compartment,
		Pikap,
		SUV, 
		Ñonvertible
	};
	Type carType_;
	double maxSpeed_;
	double fuelTankCapacity_;
public:
	Car();
	Car(std::string, Type, double, double);
	~Car() = default;
};

#endif // !CAR_HPP
