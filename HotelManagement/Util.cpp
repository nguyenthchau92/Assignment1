#include "stdafx.h"
#include <fstream>
#include <string>
#include "Util.h"

std::string BasicUtil::GetTempPathFolder()
{
	std::wstring temp_path;
	wchar_t wchar_path[MAX_PATH];
	if (GetTempPathW(MAX_PATH, wchar_path))
		temp_path = wchar_path;

	std::string str(temp_path.begin(), temp_path.end());
	return str;
}

std::string BasicUtil::GetLocalPathFolder()
{
	char char_path[MAX_PATH] = { 0x00 };
	SHGetSpecialFolderPathA(NULL, char_path, CSIDL_LOCAL_APPDATA, FALSE);
	std::string str(char_path);
	return str;
}

void BasicUtil::WriteFile(const std::string& filePath, std::vector<std::string>& data_list)
{
	char* pFileName = ConvertStringToChar(filePath);
	std::fstream data_file;
	data_file.open(pFileName, std::ios::out | std::ios::app);
	for (int i = 0; i < data_list.size(); i++)
	{
		char* ch = ConvertStringToChar(data_list.at(i));
		data_file << ch << "\n";
	}
	data_file.close();
}

std::vector<std::string> BasicUtil::ReadFileAc(const std::string& filePath)
{
	std::vector<std::string> data_list;
	char input[MAX_PATH] = { 0x00 };
	char* fileName = ConvertStringToChar(filePath);
	std::fstream data_file; 
	data_file.open(fileName, std::ios::in);
	if (data_file)
	{
		while (!data_file.eof())
		{
			data_file.getline(input, MAX_PATH);
			std::string str(input);
			data_list.push_back(str);
		}
		data_file.close();
	}

	return data_list;
}

char* BasicUtil::ConvertStringToChar(const std::string& str)
{
	int length = str.length();
	char* ch_arr = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		ch_arr[i] = str[i];
	}
	ch_arr[length] = '\0';
	return ch_arr;

}

bool BasicUtil::CreateFolder(std::string& path_folder)
{
	bool ret = 0;
	_TCHAR PATH[MAX_PATH];
	int length = path_folder.length();
	for (int i = 0; i < length; i++)
	{
		PATH[i] = (_TCHAR)path_folder.at(i);
	}

	PATH[length] = '\0';
	ret = CreateDirectory(PATH, NULL);
	return ret;
}

std::string BasicUtil::CreatePathFileForAccount()
{
	//Write file
	std::string str_local_path = GetLocalPathFolder();
	str_local_path += "\\ACManagement";
	if (!DirectoryExist((const char*)str_local_path.c_str()))
	{
		CreateFolder(str_local_path);
	}
	
	std::string str_file = "\\ACM.acc";
	str_local_path += str_file;
	return str_local_path;
}

std::string BasicUtil::CreatePathfileAccountInfo(const std::string& str_file)
{
	std::string str_local_path = GetLocalPathFolder();
	str_local_path += "\\ACManagement";
	CreateFolder(str_local_path);
	str_local_path += str_file;
	return str_local_path;
}

BOOL BasicUtil::DirectoryExist(const char* dirName)
{
	DWORD attribs = ::GetFileAttributesA(dirName);
	if (attribs == INVALID_FILE_ATTRIBUTES)
	{
		return false;
	}
	return (attribs & FILE_ATTRIBUTE_DIRECTORY);

}

unsigned int BasicUtil::SplitString(const std::string &str_input,
	std::vector<std::string> &ret_list, char ch)
{
	unsigned int pos = str_input.find(ch);
	unsigned int init_pos = 0;
	ret_list.clear();

	while (pos != std::string::npos)
	{
		std::string str_sub = str_input.substr(init_pos, pos - init_pos + 1);
		int idx = str_sub.find(ch);
		str_sub.erase(str_sub.begin() + idx);
		ret_list.push_back(str_sub);
		init_pos = pos + 1;
		pos = str_input.find(ch, init_pos);
	}

	int idex = min(pos, str_input.size());
	std::string last_sub = str_input.substr(init_pos, idex - init_pos + 1);
	ret_list.push_back(last_sub);
	return ret_list.size();
}


void BasicUtil::ExecuteQuery(CDatabase database, CString query)
{
	database.ExecuteSQL(query);
}

