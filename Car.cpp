#include "Car.hpp"

Car::Car()
{
	name_ = "";
	maxSpeed_ = 0;
	fuelTankCapacity_ = 0;
}

Car::Car(std::string name, Type type, double speed, double fuel) : name_(name), carType_(type), maxSpeed_(speed), fuelTankCapacity_(fuel)
{
	//исключение
}

