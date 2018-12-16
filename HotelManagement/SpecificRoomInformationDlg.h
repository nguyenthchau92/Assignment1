#pragma once
#include "afxwin.h"
#include "resource.h"
#include "afxdtctl.h"
#include "afxcmn.h"
#include <vector>
#include <chrono>

// SpecificRoomInformationDlg dialog

class SpecificRoomInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SpecificRoomInformationDlg)

public:
	SpecificRoomInformationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SpecificRoomInformationDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_SPECIFIC_ROOM };// IDD_DIALOG_SPECIFIC_ROOM

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdd();
protected:
	CEdit edit_name_customer;
	CEdit edit_id_customer;
	CDateTimeCtrl datetime_checkin_room;
	CDateTimeCtrl datetime_checkout_room;
	bool isRented;
	CComboBox combox_sex;
	CEdit edit_age;
	CEdit edit_address;
	CString roomID;
	CString staffID;
	CString serviceID;
	CString g_customerID;
	CString g_name;
	CString g_checkinDate;
	CString g_checkoutdate;
	std::vector<CString> lstFood;
public:
	static int counterService;
public:
	afx_msg void OnBnClickedOk();
public: 
	void setRoomID(CString roomID) { this->roomID = roomID; };
	void setStaffID(CString staffID) { this->staffID = staffID; };
	void setIsRented(bool isRented) { this->isRented = isRented; };
protected:
	CComboBox combo_food;
	CListCtrl listctrl_food;
public:
	afx_msg void OnBnClickedButtonPayment();
	void AddFood(bool isAdditionalFood = false);
};
