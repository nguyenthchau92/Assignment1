#pragma once
#include "afxwin.h"


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
	bool is_success;
	CString str_reg_user;
	CString str_reg_pass;
};

