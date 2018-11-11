#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include <vector>
#include "AccountInfo.h"


// AccountInformationDlg dialog

class AccountInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AccountInformationDlg)

public:
	AccountInformationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~AccountInformationDlg();

// Dialog Data
	enum { IDD = IDD_DLG_AC_INFO_ALL };

public:
	void LoadInformation();
	void ReadDataFromFile();
	void InitInfoList();
	void WriteInformation();
	void FillData();

	std::string get_account_mng() const { return account_mng; };
	void set_account_mng(const std::string& ac_mng) { account_mng = ac_mng;};
	std::string get_store_path() const { return store_path; };
	void set_store_path(const std::string& store_path_) { store_path = store_path_; };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	CEdit edit_address;
	CEdit edit_username;
	CEdit edit_password;
	CEdit edit_email;
	CEdit edit_other;
public:
	afx_msg void OnBnClickedBtnAddNew();
protected:
	CListCtrl list_information;
	int index_item;

	std::vector<AccountInfo> ac_info_list;

	std::string account_mng;
	std::string store_path;
public:
	afx_msg void OnBnClickedBtnStorePath();
	afx_msg void OnBnClickedBtnRemove();
	afx_msg void OnBnClickedBtnModify();
	afx_msg void OnBnClickedOk();
	afx_msg void OnItemChanged(NMHDR *pNMHDR, LRESULT *pResult);
};
