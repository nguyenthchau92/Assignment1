#include "stdafx.h"
#include "DatabaseAppication.h"


DatabaseAppication * DatabaseAppication::instance = NULL;

DatabaseAppication::DatabaseAppication()
{
}

DatabaseAppication::~DatabaseAppication()
{
}

void DatabaseAppication::ConnectDB()
{
	if (database.IsOpen())
	{
		//MessageBox(_T("The database has been connected to applicaiton"));
	}
	connection = _T("Driver={SQL Server Native Client 11.0};Server=IPHONE-6-PLUS\\SQLSERVER2014;Database=HotelManagement;Trusted_Connection=Yes;Uid=sa;Pwd=12345678;");
	if (database.OpenEx(connection, CDatabase::useCursorLib))
	{
		//		MessageBox(_T("Connected database successfully"));
	}
}

DatabaseAppication* DatabaseAppication::getInstance()
{
	if (instance == NULL)
		instance = new DatabaseAppication;
	return instance;
}

void DatabaseAppication::ExecuteQuerySelect(CString nameTable, std::vector<std::vector<CString>> &lstData)
{
	CString query = L"Select * from " + nameTable;
	CRecordset recordset(&database);
	CString temp;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
	while (!recordset.IsEOF())
	{
		std::vector<CString> row;
		int len = recordset.GetODBCFieldCount();
		for (int i = 0; i < len; i++)
		{
			recordset.GetFieldValue(i, temp);
			row.push_back(temp);
		}
		lstData.push_back(row);
		recordset.MoveNext();
	}
}


void DatabaseAppication::ExecuteQuery(CString query)
{
	database.ExecuteSQL(query);
}

void DatabaseAppication::ExecuteQueryInsert(CString nameTable, std::vector<std::pair<DataType, CString>> lstData)
{
	CString query = L"insert into " + nameTable + L" values(";
	for (int i = 0; i < lstData.size(); i++)
	{
		if (lstData[i].first == STRING)
		{
			// handle text
			if (i != lstData.size()-1)
				query += L"'" + lstData[i].second + L"'" + L",";
			else
				query += L"'" + lstData[i].second + L"'";
		}
		if (lstData[i].first == INTEGER)
		{ 
			if (i != lstData.size() - 1)
				query += lstData[i].second + L",";
			else
				query += lstData[i].second;
		}
	}

	query += L")";
	database.ExecuteSQL(query);
}

void DatabaseAppication::ExecuteQueryUpdate(CString nameTable, std::map<CString, std::pair<DataType, CString>> listData, 
				std::map<CString, std::pair<DataType, CString>> listCondition)
{
	CString query = L"UPDATE " + nameTable + L" SET ";
	// Create a map iterator and point to beginning of map
	std::map<CString, std::pair<DataType, CString>>::iterator it = listData.begin();

	// Iterate over the map using Iterator till end.
	while (it != listData.end())
	{
		// Accessing KEY from element pointed by it.
		CString fieldName = it->first;
		std::pair<DataType, CString> value = it->second;
		it++;
		// handle text
		if (value.first == STRING)
		{
			if (it != listData.end())
				query += fieldName + L"= '" + value.second + L"'" + L",";
			else
				query += fieldName + L"='" + value.second + L"'";
		}
		else if (value.first == INTEGER)
		{
			if (it != listData.end())
				query += fieldName + L"= " + value.second + L",";
			else
				query += fieldName + L"= " + value.second;
		}
	}

	query += L" WHERE ";
	std::map<CString, std::pair<DataType, CString>>::iterator it2 = listCondition.begin();

	// Iterate over the map using Iterator till end.
	while (it2 != listCondition.end())
	{
		// Accessing KEY from element pointed by it.
		CString fieldName = it2->first;
		std::pair<DataType, CString> value = it2->second;
		it2++;
		// handle text
		if (value.first == STRING)
		{
			if (it2 != listCondition.end())
				query += fieldName + L"= '" + value.second + L"'" + L",";
			else
				query += fieldName + L"='" + value.second + L"'";
		}
		else if (value.first == INTEGER)
		{
			if (it2 != listCondition.end())
				query += fieldName + L"= " + value.second + L",";
			else
				query += fieldName + L"= " + value.second;
		}
	}

	database.ExecuteSQL(query);
}



