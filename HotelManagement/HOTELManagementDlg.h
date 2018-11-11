
// ACManagementDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "AcInfo.h"


// HOTELManagementDlg dialog
class HOTELManagementDlg : public CDialogEx
{
// Construction
public:
	HOTELManagementDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_HOTELMANAGEMENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
protected:
	AcInfomation* p_ac_info;
protected:
	CEdit edit_username;
	CEdit edit_password;
public:
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnRegister();
};