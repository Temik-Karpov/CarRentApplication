#ifndef USER_HPP
#define USER_HPP
#include <string>

class User
{
private:
	std::string Login;
	std::string Password;
	enum Type
	{
		CLIENT,
		ACCOUNTANT
	};
	Type userType;
	std::string getPassword();
	static int numberOfUsers;
public:
	User();
	User(std::string&, std::string&, int&);
	~User() = default;
	std::string getLogin();
	static void increaseNumberOfUsers();
	static bool check(User, const std::string&);
};
#endif // !USER_HPP

