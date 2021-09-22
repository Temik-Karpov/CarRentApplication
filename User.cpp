#include "User.hpp"
#include <iostream>  
#include <fstream>
#include <string>

int User::numberOfUsers = 0;

User::User()
{
	Login = "";
	Password = "";
}

User::User(std::string& login, std::string& password, int& type) : Login(login), Password(password)
{
	switch (type)
	{
	case 1:
		this->userType = Type::CLIENT;
		break;
	case 2:
		this->userType = Type::ACCOUNTANT;
		break;
	default:
		throw std::invalid_argument("Wrong user type");
		break;
	}
	//написать исключение
}

std::string User::getLogin()
{
	return Login;
}

void User::increaseNumberOfUsers()
{
	numberOfUsers++;
}

bool User::check(User user, const std::string& password)
{
	return (user.getPassword() == password);
}

std::string User::getPassword()
{
	return Password;
}
