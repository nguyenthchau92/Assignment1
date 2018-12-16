// ManagerManagement.cpp : implementation file
//

#include "stdafx.h"
#include "ManagerManagement.h"
#include "afxdialogex.h"
#include <vector>
#include "DatabaseAppication.h"
#include "RoomsInformationDlg.h"


// ManagerManagement dialog

std::map<CString, CString> month2Num =
{
	{ L"January", L"1" },
	{ L"Feburary", L"2" },
	{ L"March", L"3" },
	{ L"April", L"4" },
	{ L"May", L"5" },
	{ L"June", L"6" },
	{ L"July", L"7" },
	{ L"August", L"8" },
	{ L"September", L"9" },
	{ L"October", L"10" },
	{ L"November", L"11" },
	{ L"December", L"12" },
};

IMPLEMENT_DYNAMIC(ManagerManagement, CDialogEx)

ManagerManagement::ManagerManagement(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerManagement::IDD, pParent)
{
	fTotalSalary = 0;
}

ManagerManagement::~ManagerManagement()
{
}

void ManagerManagement::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_MONTH, combo_month);
	DDX_Control(pDX, IDC_COMBO_YEAR, combo_year);
	DDX_Control(pDX, IDC_LIST_BILL, lst_ctrl_invoice);
	DDX_Control(pDX, IDC_LIST_SALARY, lst_ctrl_salary);
	DDX_Control(pDX, IDC_EDIT_TOTAL_INCOME, edit_total_income);
}

BOOL ManagerManagement::OnInitDialog()
{
	CDialog::OnInitDialog();
	// init data for month
	combo_month.InsertString(0, L"January");
	combo_month.InsertString(1, L"Feburary");
	combo_month.InsertString(2, L"March");
	combo_month.InsertString(3, L"April");
	combo_month.InsertString(4, L"May");
	combo_month.InsertString(5, L"June");
	combo_month.InsertString(6, L"July");
	combo_month.InsertString(7, L"August");
	combo_month.InsertString(8, L"September");
	combo_month.InsertString(9, L"October");
	combo_month.InsertString(10, L"November");
	combo_month.InsertString(11, L"December");
	combo_month.SetCurSel(0);
	// init data for year
	combo_year.InsertString(0, L"2018");
	combo_year.InsertString(1, L"2019");
	combo_year.InsertString(2, L"2020");
	combo_year.SetCurSel(0);
	// init data for bill
	lst_ctrl_invoice.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	lst_ctrl_invoice.InsertColumn(0, L"IDENTIFICATION", LVCFMT_LEFT, 100);
	lst_ctrl_invoice.InsertColumn(1, L"SERVICE", LVCFMT_LEFT, 100);
	lst_ctrl_invoice.InsertColumn(2, L"STAFFID", LVCFMT_LEFT, 100);
	lst_ctrl_invoice.InsertColumn(3, L"TIMEINVOICE", LVCFMT_LEFT, 100);
	lst_ctrl_invoice.InsertColumn(4, L"COSTINVOICE", LVCFMT_LEFT, 100);
	// init data for salary
	lst_ctrl_salary.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	lst_ctrl_salary.InsertColumn(0, L"STAFFID", LVCFMT_LEFT, 70);
	lst_ctrl_salary.InsertColumn(1, L"NAME", LVCFMT_LEFT, 100);
	lst_ctrl_salary.InsertColumn(2, L"SALARY", LVCFMT_LEFT, 70);
	lst_ctrl_salary.InsertColumn(3, L"POSITION", LVCFMT_LEFT, 100);
	// show salary to gui
	// find all emploee who work at same branch as manager
	int rowGui = 0;
	std::vector<std::vector<CString>> lstUsername;
	CString condition = L"BRANCHID='" + this->branchID + "'";
	DatabaseAppication::getInstance()->ExeQuerySelectWithCond(L"STAFF", condition, lstUsername);
	CString name, staffID, salary, position;	
	for (size_t i = 0; i < lstUsername.size(); i++)
	{
		std::vector<CString> recordStaff = lstUsername[i];
		staffID = recordStaff[0];
		name = recordStaff[4];
		salary = recordStaff[7];
		position = recordStaff[8];
		fTotalSalary += _tstof(salary);
		lst_ctrl_salary.InsertItem(rowGui, staffID);
		lst_ctrl_salary.SetItemText(rowGui, 1, name);
		lst_ctrl_salary.SetItemText(rowGui, 2, salary);
		lst_ctrl_salary.SetItemText(rowGui, 3, position);
		rowGui++;
	}

	UpdateData(false);
	return true;
}

BEGIN_MESSAGE_MAP(ManagerManagement, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_CALCULATE, &ManagerManagement::OnBnClickedBtnCalculate)
	ON_BN_CLICKED(IDC_BTN_ROOM_MNG, &ManagerManagement::OnBnClickedBtnRoomMng)
END_MESSAGE_MAP()


// ManagerManagement message handlers


void ManagerManagement::OnBnClickedBtnCalculate()
{
	// show bill to gui
	// find all bill which belong to one month
	CString year, month;
	int rowInvoice = 0;
	int curYear = combo_year.GetCurSel();
	combo_year.GetLBText(curYear, year);
	int curMonth = combo_month.GetCurSel();
	combo_month.GetLBText(curMonth, month);
	std::vector<std::vector<CString>> lstBill;
	CString numMonth = month2Num[month];
	DatabaseAppication::getInstance()->ExeQuerySelectWithBill(L"INVOICE", year, numMonth, lstBill);
	for (size_t i = 0; i < lstBill.size(); i++)
	{
		std::vector<CString> eachInvoice = lstBill[i];
		CString identification = eachInvoice[0];
		CString service = eachInvoice[1];
		CString staffID = eachInvoice[2];
		CString timeInvoice = eachInvoice[3];
		CString costInvoice = eachInvoice[4];
		lst_ctrl_invoice.InsertItem(rowInvoice, identification);
		lst_ctrl_invoice.SetItemText(rowInvoice, 1, service);
		lst_ctrl_invoice.SetItemText(rowInvoice, 2, staffID);
		lst_ctrl_invoice.SetItemText(rowInvoice, 3, timeInvoice);
		lst_ctrl_invoice.SetItemText(rowInvoice, 4, costInvoice);
		fTotalSalary += _tstof(costInvoice);
		rowInvoice++;
	}

	CString result;
	result.Format(L"%f", fTotalSalary);
	edit_total_income.SetWindowText(result);
	UpdateData(false);
}


void ManagerManagement::OnBnClickedBtnRoomMng()
{
	RoomsInformationDlg roomInfo_dlg;
	roomInfo_dlg.setStaffID(staffID);
	// if staff, go to screen room management
	roomInfo_dlg.DoModal();
}
