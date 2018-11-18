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
	connection = _T("Driver={SQL Server Native Client 11.0};Server=IPHONE-6-PLUS\\SQLSERVER2014;Database=TestManagement;Trusted_Connection=Yes;Uid=sa;Pwd=12345678;");
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

void DatabaseAppication::SelectDataFromDB(CString nameTable, std::vector<std::vector<CString>> &lstData)
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

