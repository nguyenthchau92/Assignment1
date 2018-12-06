// RoomsInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RoomsInformationDlg.h"
#include "afxdialogex.h"
#include "SpecificRoomInformationDlg.h"


// RoomsInformationDlg dialog

IMPLEMENT_DYNAMIC(RoomsInformationDlg, CDialogEx)

RoomsInformationDlg::RoomsInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RoomsInformationDlg::IDD, pParent)
{

}

RoomsInformationDlg::~RoomsInformationDlg()
{
}

void RoomsInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RoomsInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_R101, &RoomsInformationDlg::OnBnClickedButtonR101)
	ON_BN_CLICKED(IDC_BUTTON_R102, &RoomsInformationDlg::OnBnClickedButtonR102)
END_MESSAGE_MAP()


// RoomsInformationDlg message handlers


void RoomsInformationDlg::OnBnClickedButtonR101()
{
	// call to diaglog specific room
	SpecificRoomInformationDlg roomDlg;
	std::vector<std::vector<CString>> lstData;
	CString branchID, roomID;
	DatabaseAppication::getInstance()->ExecuteQuerySelect(L"STAFF", lstData);
	for (size_t i = 0; i < lstData.size(); i++)
	{
		if (lstData[i][0].Trim().Compare(staffID) == 0)
		{
			branchID = lstData[i][1].Trim();
			break;
		}

	}
	std::vector<std::vector<CString>> lstRoomData;
	DatabaseAppication::getInstance()->ExecuteQuerySelect(L"ROOM", lstRoomData);
	for (size_t i = 0; i < lstRoomData.size(); i++)
	{
		if (lstRoomData[i][1].Trim().Compare(branchID) == 0 && 
			lstRoomData[i][6].Trim().Compare(L"101") == 0)
		{
			roomID = lstRoomData[i][0];
			break;
		}

	}
	roomDlg.setRoomID(roomID);
	roomDlg.setStaffID(staffID);
	if (roomDlg.DoModal() == IDOK)
	{

	}

}


void RoomsInformationDlg::OnBnClickedButtonR102()
{
	MessageBox(L"this is button 101");
	// call to diaglog specific room
	SpecificRoomInformationDlg roomDlg;
	if (roomDlg.DoModal() == IDOK)
	{

	}

}
