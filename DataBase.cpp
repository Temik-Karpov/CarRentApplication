#include "DataBase.hpp"
#include <iostream>
#include <fstream>

bool DataBase::search(std::string login)
{
	for (auto i = data_.begin(); i != data_.end(); i++)
	{
		if (i->getLogin() == login)
		{
			return true;
		}
	}
	return false;
}

User DataBase::find(std::string login)
{
	for (auto i = data_.begin(); i != data_.end(); i++)
	{
		if (i->getLogin() == login)
		{
			return *i;
		}
	}
}

DataBase::DataBase()
{
}

void DataBase::registration()
{
	std::cout << "Welcome!\n";
	std::cout << "Login: ";
	std::string login, password;
	std::cin >> login;
	std::cout << "\nPassword: ";
	std::cin >> password;
	if (!search(login))
	{
		std::cout << "NEW!!\n\n";
		User newUser(login, password);
		data_.push_back(newUser);
		User::numberOfUsers++;
		std::ofstream file("listOfMembers.txt");
		file << "Login: " << newUser.getLogin() << "\n\n";
		file.close();
	}
	else
	{
		if (User::check(find(login), password))
		{
			std::cout << "OLD!!\n\n";
		}
		else
		{
			std::cout << "WRONG!!\n\n";
		}
	}
}

