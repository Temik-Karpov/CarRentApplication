#ifndef DATA_BASE_HPP
#define DATA_BASE_HPP
#include<list>
#include "User.hpp"

class DataBase
{
private:
	std::list<User> data_;
	bool search(const std::string login);
	User find(const std::string login);
public:
	DataBase();
	~DataBase() = default;
	int registration();
};
#endif // !DATA_BASE_HPP

