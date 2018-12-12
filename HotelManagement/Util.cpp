#include "stdafx.h"
#include <fstream>
#include <string>
#include "Util.h"


void ConvertDatetime2Systemtime(CString g_inputDate, SYSTEMTIME &outTime)
{
	int ci_year = 0, ci_day = 0, ci_month = 0;
	memset(&outTime, 0x00, sizeof(SYSTEMTIME));
	std::string sCheckinTime = CStringA(g_inputDate);
	sCheckinTime = sCheckinTime.substr(0, sCheckinTime.find_first_of(" "));
	sscanf((char*)sCheckinTime.c_str(), "%d-%d-%d", &ci_year, &ci_month, &ci_day);
	outTime.wYear = ci_year;
	outTime.wDay = ci_day;
	outTime.wMonth = ci_month;
}

int GetNumDateBetweenTwoTime(CString g_BeginDate, CString  g_EndDate)
{
	COleDateTime tm1;
	COleDateTime tm2;
	tm1.ParseDateTime(g_BeginDate);
	tm2.ParseDateTime(g_EndDate);
	COleDateTimeSpan ts = tm2 - tm1;
	int numOfDays = ts.GetDays();
	return numOfDays;
}

bool CompareTwoTime(CString g_BeginDate, CString  g_EndDate)
{
	COleDateTime tm1;
	COleDateTime tm2;
	tm1.ParseDateTime(g_BeginDate);
	tm2.ParseDateTime(g_EndDate);
	COleDateTimeSpan ts = tm2 - tm1;
	int numOfDays = ts.GetDays();
	if (numOfDays >= 0)
		return true;
	return false;
}

