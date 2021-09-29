#include "DataBase.hpp"
#include <iostream>
#include <fstream>
#include <execution>

bool DataBase::search(const std::string login)
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

User DataBase::find(const std::string login)
{
	for (auto i = data_.begin(); i != data_.end(); i++)
	{
		if (i->getLogin() == login)
		{
			return *i;
		}
	}
	throw std::runtime_error("DataBase error");
}

DataBase::DataBase()
{
}

int DataBase::registration() 
{
	int type;
	std::cout << "Welcome!\n";
	std::cout << "Login: ";
	std::string login, password;
	std::cin >> login;
	std::cout << "\nPassword: ";
	std::cin >> password;
	if (!search(login))
	{
		std::cout << "\nYou are 1) QUEST \n\t2) ACCOUNTANT\n";
		std::cin >> type;
		User newUser(login, password, type);
		data_.push_back(newUser);
		User::increaseNumberOfUsers();
		std::cout << "NEW!!\n\n";
		/*std::ofstream file("listOfMembers.txt");
		file << "Login: " << newUser.getLogin() << "\n\n";
		file.close();*/
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
	switch (type)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	}
}

