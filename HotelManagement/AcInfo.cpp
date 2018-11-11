#include "stdafx.h"
#include "AcInfo.h"


AcInfomation::AcInfomation()
{
	str_user_name = "";
	str_pass = "";
	str_email = "";
	str_path_stored_ = "";
}


AcInfomation::~AcInfomation()
{
}

void AcInfomation::set_user(std::string& str_user)
{
	this->str_user_name = str_user;
}

void AcInfomation::set_email(std::string& str_email)
{
	this->str_email = str_email;
}

void AcInfomation::set_pass(std::string& str_pass)
{
	this->str_pass = str_pass;
}

void AcInfomation::set_path(std::string& str_path)
{
	this->str_path_stored_ = str_path;
}



