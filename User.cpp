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

User::User(std::string & login, std::string & password) : Login(login), Password(password)
{
	//написать исключение
}

std::string User::getLogin()
{
	return Login;
}

bool User::check(User user, std::string password)
{
	return (user.getPassword() == password);
}

std::string User::getPassword()
{
	return Password;
}
