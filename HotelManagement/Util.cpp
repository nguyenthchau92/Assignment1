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
	// format time to yyyy-mm-dd
	std::string sBeginDate = CStringA(g_BeginDate);
	sBeginDate = sBeginDate.substr(0, sBeginDate.find_first_of(" "));
	CString cs_sCheckInDate(sBeginDate.c_str());
	// format time to yyy-mm-dd
	std::string sEndDate = CStringA(g_EndDate);
	sEndDate = sEndDate.substr(0, sEndDate.find_first_of(" "));
	CString cs_sCheckOutDate(sEndDate.c_str());
	// diff timestamp
	tm1.ParseDateTime(cs_sCheckInDate);
	tm2.ParseDateTime(cs_sCheckOutDate);
	COleDateTimeSpan ts = tm2 - tm1;
	int numOfDays = ts.GetDays();
	return numOfDays;
}

bool CompareTwoTime(CString g_BeginDate, CString  g_EndDate)
{
	COleDateTime tm1;
	COleDateTime tm2;
	// format time to yyyy-mm-dd
	std::string sBeginDate = CStringA(g_BeginDate);
	sBeginDate = sBeginDate.substr(0, sBeginDate.find_first_of(" "));
	CString cs_sCheckInDate(sBeginDate.c_str());
	// format time to yyy-mm-dd
	std::string sEndDate = CStringA(g_EndDate);
	sEndDate = sEndDate.substr(0, sEndDate.find_first_of(" "));
	CString cs_sCheckOutDate(sEndDate.c_str());
	// diff timestamp
	tm1.ParseDateTime(cs_sCheckInDate);
	tm2.ParseDateTime(cs_sCheckOutDate);
	COleDateTimeSpan ts = tm2 - tm1;
	int numOfDays = ts.GetDays();
	return (numOfDays > 0) ? true : false;
}

