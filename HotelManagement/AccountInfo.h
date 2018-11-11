#pragma once
#ifndef ACCOUNT_INFO_H
#define ACCOUNT_INFO_H
#include <string>

class AccountInfo
{
public:
	AccountInfo();
	~AccountInfo();

	std::string get_address() const { return str_address; };
	std::string get_user_name() const{ return str_user_name; };
	std::string get_email() const { return str_email; };
	std::string get_pass() const{ return str_pass; };
	std::string get_other() const{ return str_other; };

	void set_address(std::string& str_ad);
	void set_user(std::string& str_user);
	void set_email(std::string& str_email);
	void set_pass(std::string& str_pass);
	void set_other(std::string& str_other);

	void set_full_info(std::string& str_a,
		std::string &str_u,
		std::string& str_pas,
		std::string& str_e,
		std::string& str_other);

private:
	std::string str_address;
	std::string str_user_name;
	std::string str_email;
	std::string str_pass;
	std::string str_other;
};

#endif // !ACCOUNT_INFO_H