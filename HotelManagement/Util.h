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

void ConvertDatetime2Systemtime(CString g_inputDate, SYSTEMTIME &outTime);
int GetNumDateBetweenTwoTime(CString g_inputDate, CString  g_outputDate);
bool CompareTwoTime(CString g_BeginDate, CString  g_EndDate);

#endif // !UTIL_H_
