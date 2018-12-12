// InvoiceInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "InvoiceInformationDlg.h"
#include "afxdialogex.h"
#include "DatabaseAppication.h"


// InvoiceInformationDlg dialog

IMPLEMENT_DYNAMIC(InvoiceInformationDlg, CDialogEx)

InvoiceInformationDlg::InvoiceInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(InvoiceInformationDlg::IDD, pParent)
{

}

InvoiceInformationDlg::~InvoiceInformationDlg()
{
}

BOOL InvoiceInformationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	list_ctrl_item.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	list_ctrl_item.InsertColumn(0, L"Name", LVCFMT_LEFT, 200);
	list_ctrl_item.InsertColumn(1, L"Price", LVCFMT_LEFT, 200);

	//	2.2 Update data in table Invoice from RentedRoom and Order tables
	std::vector<std::map<CString, CString>> lstRoomCost;
	std::vector<std::map<CString, CString>> lstFoodCost;
	//TODO: calulator cost of invoice
	// find list ROOMID based on serviceID table
	std::vector<std::vector<CString>> lstRentedroomData;
	DatabaseAppication::getInstance()->ExecuteQuerySelect(L"RENTEDROOM", lstRentedroomData);
	for (size_t i = 0; i < lstRentedroomData.size(); i++)
	{
		std::vector<CString> temp = lstRentedroomData[i];
		// find a row with same service ID
		if (this->serviceID.Compare(temp[0].Trim()) == 0)
		{
			// Get price from room table based on ROOMID
			std::vector<CString> lstRoomData;
			CString condition = L"ROOMID=" + temp[2].Trim();
			DatabaseAppication::getInstance()->ExecuteQuerySelectWithCondition(L"ROOM", condition, lstRoomData);
			if (lstRoomData.size() > 0)
			{
				CString roomName = lstRoomData[6].Trim();
				CString roomCost = lstRoomData[5].Trim();
				std::map<CString, CString> tmp;
				tmp[roomName] = roomCost;
				lstRoomCost.push_back(tmp);
			}
		}
	}

	std::vector<std::vector<CString>> lstFoodData;
	DatabaseAppication::getInstance()->ExecuteQuerySelect(L"USINGFOOD", lstFoodData);
	for (size_t i = 0; i < lstFoodData.size(); i++)
	{
		std::vector<CString> temp = lstFoodData[i];
		// find a row with same service ID
		if (this->serviceID.Compare(temp[0].Trim()) == 0)
		{
			// Get price from FOOD table based on FOODNAME
			std::vector<CString> lstFoodData;
			CString condition = L"FOODID=" + temp[2].Trim();
			DatabaseAppication::getInstance()->ExecuteQuerySelectWithCondition(L"FOOD", condition, lstFoodData);
			if (lstFoodData.size() > 0)
			{
				CString foodCost = lstFoodData[5].Trim();
				std::map<CString, CString> tmp;
				tmp[lstFoodData[2].Trim()] = foodCost;
				lstFoodCost.push_back(tmp);
			}
		}
	}

	float fCostInvoice = 0;
	for (int i = 0; i < lstRoomCost.size(); i++)
	{
		std::map<CString, CString> tmp = lstRoomCost[i];
		fCostInvoice += _tstof(tmp.begin()->second);
	}	
	if (numDay == 0)
		numDay++;
	fCostInvoice *= numDay;	
	for (int i = 0; i < lstFoodCost.size(); i++)
	{
		std::map<CString, CString> tmp = lstFoodCost[i];
		fCostInvoice += _tstof(tmp.begin()->second);
	}
	costInvoice.Format(L"%f", fCostInvoice);

	std::vector<std::pair<DataType, CString>> lstField;
	lstField.push_back(std::make_pair(STRING, identification));
	lstField.push_back(std::make_pair(STRING, serviceID));
	lstField.push_back(std::make_pair(STRING, staffID));
	lstField.push_back(std::make_pair(STRING, timeInvoice));
	lstField.push_back(std::make_pair(INTEGER, costInvoice));
	DatabaseAppication::getInstance()->ExecuteQueryInsert(L"INVOICE", lstField);

	//	2.3 Upload data from table Bill to GUI

	// update customer name from userID
	std::vector<CString> lstUsername;
	CString condition = L"IDENTIFICATION='" + identification + "'";
	DatabaseAppication::getInstance()->ExecuteQuerySelectWithCondition(L"CUSTOMER", condition, lstUsername);
	if (lstUsername.size() > 0)
		username = lstUsername[4].Trim();
	edit_name_user.SetWindowText(username);

	// update time
	/*SYSTEMTIME billTime;
	int ci_year = 0, ci_day = 0, ci_month = 0;
	memset(&billTime, 0x00, sizeof(SYSTEMTIME));
	std::string stimeInvoice = CStringA(timeInvoice);
	stimeInvoice = stimeInvoice.substr(0, stimeInvoice.find_first_of(" "));
	sscanf((char*)stimeInvoice.c_str(), "%d-%d-%d", &ci_year, &ci_month, &ci_day);
	billTime.wYear = ci_year;
	billTime.wDay = ci_day;
	billTime.wMonth = ci_month;*/
	COleDateTime tm1;
	tm1.ParseDateTime(timeInvoice);
	datetime_picker_invoice.SetTime(tm1);

	// find name staff in table staff based on staffid
	std::vector<CString> staffData;
	CString conditionStaff = L"STAFFID='" + staffID + L"'";
	DatabaseAppication::getInstance()->ExecuteQuerySelectWithCondition(L"STAFF", conditionStaff, staffData);
	if (staffData.size() > 0)
	{
		edit_staff_name.SetWindowText(staffData[4]);
	}

	 //add foodName, foodCost.......
	for (size_t i = 0; i < lstFoodCost.size(); i++)
	{
		std::map<CString, CString> tmp = lstFoodCost[i];
		list_ctrl_item.InsertItem(i, tmp.begin()->first);
		list_ctrl_item.SetItemText(i, 1, tmp.begin()->second);
	}
	// roomName, roomCost......
	for (size_t i = 0; i < lstRoomCost.size(); i++)
	{
		std::map<CString, CString> tmp = lstRoomCost[i];
		list_ctrl_item.InsertItem(i + lstFoodCost.size(), L"Room " + tmp.begin()->first);
		list_ctrl_item.SetItemText(i + lstFoodCost.size(), 1, tmp.begin()->second);
	}

	// add cost invoice to gui
	edit_total_price.SetWindowText(costInvoice);
	//	2.4 Update status room is empty, reservation is empty
	// Update status Room table is rented
	std::map<CString, std::pair<DataType, CString>> listRoomData;
	listRoomData[L"STATUS"] = std::make_pair(STRING, L"False");
	std::map<CString, std::pair<DataType, CString>> listRoomCondition;
	listRoomCondition[L"ROOMID"] = std::make_pair(INTEGER, roomID);
	DatabaseAppication::getInstance()->ExecuteQueryUpdate(L"ROOM", listRoomData, listRoomCondition);

	std::map<CString, std::pair<DataType, CString>> listReservationData;
	listReservationData[L"PAID"] = std::make_pair(STRING, L"True");
	std::map<CString, std::pair<DataType, CString>> listReserCondition;
	listReserCondition[L"SERVICEID"] = std::make_pair(STRING, serviceID);
	DatabaseAppication::getInstance()->ExecuteQueryUpdate(L"RESERVATION", listReservationData, listReserCondition);
	UpdateData(false);
	
	return true;
}

void InvoiceInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME_USER, edit_name_user);
	DDX_Control(pDX, IDC_DATETIMEPICKER_INVOICE, datetime_picker_invoice);
	DDX_Control(pDX, IDC_EDIT_STAFF_NAME, edit_staff_name);
	DDX_Control(pDX, IDC_LIST_INVOICE_ITEMS, list_ctrl_item);
	DDX_Control(pDX, IDC_EDIT_TOTAL_PRICE, edit_total_price);
}


BEGIN_MESSAGE_MAP(InvoiceInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &InvoiceInformationDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// InvoiceInformationDlg message handlers


void InvoiceInformationDlg::OnBnClickedOk()
{


	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
