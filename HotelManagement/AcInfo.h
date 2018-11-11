#pragma once
#ifndef AC_INFO_H
#define AC_INFO_H
#include <string>



class AcInfomation
{
public:
	AcInfomation();
	~AcInfomation();

	std::string get_user_name() const{ return str_user_name; };
	std::string get_email() const { return str_email; };
	std::string get_pass() const{ return str_pass; };
	std::string get_path() const{ return str_path_stored_; };

	void set_user(std::string& str_user);
	void set_email(std::string& str_email);
	void set_pass(std::string& str_pass);
	void set_path(std::string& str_path_stored_);

private:
	std::string str_user_name;
	std::string str_email;
	std::string str_pass;
	std::string str_path_stored_;
	;
};

#endif // !AC_INFO_H