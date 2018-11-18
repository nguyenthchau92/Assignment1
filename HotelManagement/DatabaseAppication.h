#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H

#include <afxdb.h>
#include <vector>

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
	void SelectDataFromDB(CString nameTable, std::vector<std::vector<CString>> &lstData);
};

#endif
