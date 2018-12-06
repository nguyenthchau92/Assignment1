#ifndef UTIL_H_
#define UTIL_H_
#include <string>
#include <vector>
#include <afxdb.h>


typedef enum DataType
{
	STRING = 0,
	INTEGER
};

namespace BasicUtil
{
	std::string GetTempPathFolder();
	std::string GetLocalPathFolder();

	void WriteFile(const std::string& full_name, std::vector<std::string>& data_list);
	std::vector<std::string> ReadFileAc(const std::string& full_name);

	char* ConvertStringToChar(const std::string& str);
	bool CreateFolder(std::string& path_folder);

	std::string CreatePathFileForAccount();
	std::string CreatePathfileRoomInfo(const std::string& str_file);

	BOOL DirectoryExist(const char* dirName);

	unsigned int SplitString(const std::string &str_input,
		std::vector<std::string> &ret_list, char ch);

}


#endif // !UTIL_H_
