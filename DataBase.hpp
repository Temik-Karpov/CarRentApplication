#ifndef DATA_BASE_HPP
#define DATA_BASE_HPP
#include<list>
#include "User.hpp"

class DataBase
{
private:
	std::list<User> data_;
	bool search(std::string login);
	User find(std::string login);
public:
	DataBase();
	~DataBase() = default;
	void registration();
};
#endif // !DATA_BASE_HPP

