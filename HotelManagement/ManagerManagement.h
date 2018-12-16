#pragma once
#include "Resource.h"
#include "afxwin.h"
#include "afxcmn.h"


// ManagerManagement dialog

class ManagerManagement : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerManagement)

public:
	ManagerManagement(CWnd* pParent = NULL);   // standard constructor
	virtual ~ManagerManagement(); 
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_MANAGER_MANAGEMENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CComboBox combo_month;
	CComboBox combo_year;
	CString staffID;
	CString branchID;
	float fTotalSalary;
public:
	CListCtrl lst_ctrl_invoice;
protected:
	CListCtrl lst_ctrl_salary;
	CEdit edit_total_income;
public:
	afx_msg void OnBnClickedBtnCalculate();
	void setStaffID(CString staffID) { this->staffID = staffID; };
	void setBranchID(CString branchID) { this->branchID = branchID; };
	afx_msg void OnBnClickedBtnRoomMng();
};
