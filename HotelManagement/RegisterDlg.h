#pragma once
#include "afxwin.h"
#include "HOTELManagementDlg.h"


// RegisterDlg dialog

class RegisterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RegisterDlg)

public:
	RegisterDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~RegisterDlg();

// Dialog Data
	enum { IDD = IDD_DLG_REGISTER };

public:
	CString get_str_user() const { return str_reg_user; };
	CString get_str_pass() const { return str_reg_pass; };
	CString get_str_staffID() const { return str_staffid; };

	void set_user(CString user) { str_reg_user = user; };
	void set_password(CString password) { str_reg_pass = password; };
	void set_staffID(CString staffID) { str_staffid = staffID; };

	bool get_is_success() const { return is_success; };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnApprove();
protected:
	CEdit edit_reg_user;
	CEdit edit_reg_pass;
	CEdit edit_reg_repass;
	CEdit edit_reg_staffID;

	bool is_success;
	CString str_reg_user;
	CString str_reg_pass;
	CString str_staffid;
	
public:
	afx_msg void OnEnChangeEditUsernameRegister();
	afx_msg void OnBnClickedOk();
};

