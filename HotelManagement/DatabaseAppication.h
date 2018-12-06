#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H

#include <afxdb.h>
#include <vector>
#include <map>
#include "Util.h"

class DatabaseAppication
{
private:
	static DatabaseAppication *instance;
	DatabaseAppication();

	CString connection;
	CDatabase database;
	
public:
	~DatabaseAppication();
	static DatabaseAppication *getInstance();

	void ConnectDB();
	void ExecuteQuery(CString query);
	void ExecuteQuerySelect(CString nameTable, std::vector<std::vector<CString>> &lstData);
	void ExecuteQueryInsert(CString nameTable, std::vector<std::pair<DataType, CString>> listData);
	void ExecuteQueryUpdate(CString nameTable, std::map<CString, std::pair<DataType, CString>> listData, 
		std::map<CString, std::pair<DataType, CString>> listCondition);
};

#endif
