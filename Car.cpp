#include "Car.hpp"
#include <exception>
#include <iostream>

Car::Car()
{
	name_ = "";
	maxSpeed_ = 0;
	fuelTankCapacity_ = 0;
}

Car::Car(std::string name, Type type, double speed, double fuel) : name_(name), carType_(type), maxSpeed_(speed), fuelTankCapacity_(fuel)
{
	if ((maxSpeed_ <= 0) || (fuelTankCapacity_ <= 0))
	{
		throw std::invalid_argument("Wrong car argument");
	}
}

void Car::info()
{
	std::cout << "Name: " << name_;
	std::cout << "\n\tType: " << carType_;
	std::cout << "\n\tMaxSpeed: " << maxSpeed_;
	std::cout << "\n\tFuel tank capacity: " << fuelTankCapacity_;
}

std::string Car::getName()
{
	return name_;
}


