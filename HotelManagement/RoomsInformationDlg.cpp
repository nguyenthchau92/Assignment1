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
	ON_BN_CLICKED(IDC_BUTTON_R103, &RoomsInformationDlg::OnBnClickedButtonR103)
	ON_BN_CLICKED(IDC_BUTTON_R104, &RoomsInformationDlg::OnBnClickedButtonR104)
	ON_BN_CLICKED(IDC_BUTTON_R105, &RoomsInformationDlg::OnBnClickedButtonR105)
	ON_BN_CLICKED(IDC_BUTTON_R201, &RoomsInformationDlg::OnBnClickedButtonR201)
	ON_BN_CLICKED(IDC_BUTTON_R202, &RoomsInformationDlg::OnBnClickedButtonR202)
	ON_BN_CLICKED(IDC_BUTTON_R203, &RoomsInformationDlg::OnBnClickedButtonR203)
	ON_BN_CLICKED(IDC_BUTTON_R204, &RoomsInformationDlg::OnBnClickedButtonR204)
	ON_BN_CLICKED(IDC_BUTTON_R205, &RoomsInformationDlg::OnBnClickedButtonR205)
	ON_BN_CLICKED(IDC_BUTTON_R301, &RoomsInformationDlg::OnBnClickedButtonR301)
	ON_BN_CLICKED(IDC_BUTTON_R302, &RoomsInformationDlg::OnBnClickedButtonR302)
	ON_BN_CLICKED(IDC_BUTTON_R303, &RoomsInformationDlg::OnBnClickedButtonR303)
	ON_BN_CLICKED(IDC_BUTTON_R304, &RoomsInformationDlg::OnBnClickedButtonR304)
	ON_BN_CLICKED(IDC_BUTTON_R305, &RoomsInformationDlg::OnBnClickedButtonR305)
	ON_BN_CLICKED(IDC_BUTTON_R401, &RoomsInformationDlg::OnBnClickedButtonR401)
	ON_BN_CLICKED(IDC_BUTTON_R402, &RoomsInformationDlg::OnBnClickedButtonR402)
	ON_BN_CLICKED(IDC_BUTTON_R403, &RoomsInformationDlg::OnBnClickedButtonR403)
	ON_BN_CLICKED(IDC_BUTTON_R404, &RoomsInformationDlg::OnBnClickedButtonR404)
	ON_BN_CLICKED(IDC_BUTTON_R405, &RoomsInformationDlg::OnBnClickedButtonR405)
	ON_BN_CLICKED(IDCANCEL, &RoomsInformationDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// RoomsInformationDlg message handlers

void RoomsInformationDlg::RoomHandler(CString roomnumber)
{
	// call to diaglog specific room
	SpecificRoomInformationDlg roomDlg;
	std::vector<CString> lstData;
	CString branchID, roomID, roomStatus = L"0";
	CString condition = L"STAFFID='" + staffID + L"'";
	DatabaseAppication::getInstance()->ExecuteQuerySelectWithCondition(L"STAFF", condition, lstData);
	if (lstData.size() > 0)
	{
		branchID = lstData[1];
		std::vector<CString> roomData;
		CString condition = L"BRANCHID='" + branchID + L"' and ROOMNUMBER='" + roomnumber + L"'";
		DatabaseAppication::getInstance()->ExecuteQuerySelectWithCondition(L"ROOM", condition, roomData);
		if (roomData.size() > 0)
		{
			roomID = roomData[0];
			roomStatus = roomData[2];
		}
	}
	roomDlg.setRoomID(roomID);
	roomDlg.setStaffID(staffID);
	roomDlg.setIsRented((roomStatus == L"1") ? true : false);
	if (roomDlg.DoModal() == IDOK)
	{

	}
}

void RoomsInformationDlg::OnBnClickedButtonR101()
{
	RoomHandler(L"101");
}


void RoomsInformationDlg::OnBnClickedButtonR102()
{
	RoomHandler(L"102");
}


void RoomsInformationDlg::OnBnClickedButtonR103()
{
	RoomHandler(L"103");
}


void RoomsInformationDlg::OnBnClickedButtonR104()
{
	RoomHandler(L"104");
}


void RoomsInformationDlg::OnBnClickedButtonR105()
{
	RoomHandler(L"105");
}


void RoomsInformationDlg::OnBnClickedButtonR201()
{
	RoomHandler(L"201");
}


void RoomsInformationDlg::OnBnClickedButtonR202()
{
	RoomHandler(L"202");
}


void RoomsInformationDlg::OnBnClickedButtonR203()
{
	RoomHandler(L"203");
}


void RoomsInformationDlg::OnBnClickedButtonR204()
{
	RoomHandler(L"204");
}


void RoomsInformationDlg::OnBnClickedButtonR205()
{
	RoomHandler(L"205");
}


void RoomsInformationDlg::OnBnClickedButtonR301()
{
	RoomHandler(L"301");
}


void RoomsInformationDlg::OnBnClickedButtonR302()
{
	RoomHandler(L"302");
}


void RoomsInformationDlg::OnBnClickedButtonR303()
{
	RoomHandler(L"303");
}


void RoomsInformationDlg::OnBnClickedButtonR304()
{
	RoomHandler(L"304");
}


void RoomsInformationDlg::OnBnClickedButtonR305()
{
	RoomHandler(L"305");
}


void RoomsInformationDlg::OnBnClickedButtonR401()
{
	RoomHandler(L"401");
}


void RoomsInformationDlg::OnBnClickedButtonR402()
{
	RoomHandler(L"402");
}


void RoomsInformationDlg::OnBnClickedButtonR403()
{
	RoomHandler(L"403");
}


void RoomsInformationDlg::OnBnClickedButtonR404()
{
	RoomHandler(L"404");
}


void RoomsInformationDlg::OnBnClickedButtonR405()
{
	RoomHandler(L"405");
}


void RoomsInformationDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void RoomsInformationDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if (nIDCtl == IDC_BUTTON_R101)
	{
		CDC dc;

		dc.Attach(lpDrawItemStruct->hDC);
		RECT rect;
		rect = lpDrawItemStruct->rcItem;

		dc.FillSolidRect(&rect, RGB(0, 255, 0));
		UINT state = lpDrawItemStruct->itemState;

		if ((state & ODS_SELECTED))
		{
			dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);

		}
		else
		{
			dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);
		}

		dc.SetBkColor(RGB(100, 100, 255));
		dc.SetTextColor(RGB(255, 0, 0));
		dc.SetBkMode(TRANSPARENT);

		TCHAR buffer[MAX_PATH];
		ZeroMemory(buffer, MAX_PATH);
		::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH);
		dc.DrawText(buffer, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		dc.Detach();
	}

	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}