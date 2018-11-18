#pragma once
#include "afxwin.h"
#include "resource.h"

// SpecificRoomInformationDlg dialog

class SpecificRoomInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SpecificRoomInformationDlg)

public:
	SpecificRoomInformationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SpecificRoomInformationDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_SPECIFIC_ROOM };// IDD_DIALOG_SPECIFIC_ROOM

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
