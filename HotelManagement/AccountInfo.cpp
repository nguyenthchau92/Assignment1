#include "stdafx.h"
#include "AccountInfo.h"

AccountInfo::AccountInfo()
{
}


AccountInfo::~AccountInfo()
{
}

void AccountInfo::set_address(std::string& str_ad)
{
	this->str_address = str_ad;
}

void AccountInfo::set_user(std::string& str_user)
{
	this->str_user_name = str_user;
}

void AccountInfo::set_email(std::string& str_email)
{
	this->str_email = str_email;
}

void AccountInfo::set_pass(std::string& str_pass)
{
	this->str_pass = str_pass;
}

void AccountInfo::set_other(std::string& str_other)
{
	this->str_other = str_other;
}

void AccountInfo::set_full_info(std::string& str_a,
	std::string &str_u,
	std::string& str_pas,
	std::string& str_e,
	std::string& str_o)
{
	this->str_address = str_a;
	this->str_email = str_e;
	this->str_other = str_o;
	this->str_pass = str_pas;
	this->str_user_name = str_u;
}
