#ifndef USER_HPP
#define USER_HPP
#include <string>

class User
{
private:
	std::string Login;
	std::string Password;
	std::string getPassword();
public:
	User();
	User(std::string&, std::string&);
	~User() = default;
	static int numberOfUsers;
	std::string getLogin();
	static bool check(User, std::string);
};
#endif // !USER_HPP

