#pragma once
#include "resource.h"
#include "DatabaseAppication.h"


// RoomsInformationDlg dialog

class RoomsInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RoomsInformationDlg)

public:
	RoomsInformationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~RoomsInformationDlg();

// Dialog Data
	enum { IDD = IDD_DLG_LIST_ROOMS_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonR101();
	afx_msg void OnBnClickedButtonR102();
private:
	CString staffID;
public:
	void setStaffID(CString staffID) { this->staffID = staffID; };
};
