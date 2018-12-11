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
	void RoomHandler(CString nameroom);
	afx_msg void OnBnClickedButtonR103();
	afx_msg void OnBnClickedButtonR104();
	afx_msg void OnBnClickedButtonR105();
	afx_msg void OnBnClickedButtonR201();
	afx_msg void OnBnClickedButtonR202();
	afx_msg void OnBnClickedButtonR203();
	afx_msg void OnBnClickedButtonR204();
	afx_msg void OnBnClickedButtonR205();
	afx_msg void OnBnClickedButtonR301();
	afx_msg void OnBnClickedButtonR302();
	afx_msg void OnBnClickedButtonR303();
	afx_msg void OnBnClickedButtonR304();
	afx_msg void OnBnClickedButtonR305();
	afx_msg void OnBnClickedButtonR401();
	afx_msg void OnBnClickedButtonR402();
	afx_msg void OnBnClickedButtonR403();
	afx_msg void OnBnClickedButtonR404();
	afx_msg void OnBnClickedButtonR405();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};
