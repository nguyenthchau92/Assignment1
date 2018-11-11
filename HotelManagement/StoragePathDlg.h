#pragma once
#include "afxwin.h"
#include <string>

// StoragePathDlg dialog

class StoragePathDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StoragePathDlg)

public:
	StoragePathDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~StoragePathDlg();

// Dialog Data
	enum { IDD = IDD_DLG_STORE_PATH };
	virtual BOOL OnInitDialog();
	void set_path(const std::string& path){ store_path = path; };
	std::string get_path() const { return store_path; };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnBrowser();
protected:
	CEdit edit_store_path;
	std::string store_path;
public:
	afx_msg void OnBnClickedOk();
};
