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
	void ExecuteQueryDistinctSelect(CString nameTable, CString field, std::vector<CString> &lstData);
	void ExecuteQuerySelect(CString nameTable, std::vector<std::vector<CString>> &lstData);
	void ExeQuerySelectOneRowWithCond(CString nameTable, CString contition, std::vector<CString> &lstData);
	void ExeQuerySelectWithCond(CString nameTable, CString contition, std::vector<std::vector<CString>> &lstData);
	void ExeQuerySelectWithBill(CString nameTable, CString year, CString month, std::vector<std::vector<CString>> &lstData);
	void ExecuteQueryInsert(CString nameTable, std::vector<std::pair<DataType, CString>> listData);
	void ExecuteQueryUpdate(CString nameTable, std::map<CString, std::pair<DataType, CString>> listData, 
		std::map<CString, std::pair<DataType, CString>> listCondition);
};

#endif
