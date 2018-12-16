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
	DDX_Control(pDX, IDC_BUTTON_R101, m_btn_r101);
	DDX_Control(pDX, IDC_BUTTON_R102, m_btn_r102);
	DDX_Control(pDX, IDC_BUTTON_R103, m_btn_r103);
	DDX_Control(pDX, IDC_BUTTON_R104, m_btn_r104);
	DDX_Control(pDX, IDC_BUTTON_R105, m_btn_r105);
	DDX_Control(pDX, IDC_BUTTON_R201, m_btn_r201);
	DDX_Control(pDX, IDC_BUTTON_R202, m_btn_r202);
	DDX_Control(pDX, IDC_BUTTON_R203, m_btn_r203);
	DDX_Control(pDX, IDC_BUTTON_R204, m_btn_r204);
	DDX_Control(pDX, IDC_BUTTON_R205, m_btn_r205);
	DDX_Control(pDX, IDC_BUTTON_R301, m_btn_r301);
	DDX_Control(pDX, IDC_BUTTON_R302, m_btn_r302);
	DDX_Control(pDX, IDC_BUTTON_R303, m_btn_r303);
	DDX_Control(pDX, IDC_BUTTON_R304, m_btn_r304);
	DDX_Control(pDX, IDC_BUTTON_R305, m_btn_r305);
	DDX_Control(pDX, IDC_BUTTON_R401, m_btn_r401);
	DDX_Control(pDX, IDC_BUTTON_R402, m_btn_r402);
	DDX_Control(pDX, IDC_BUTTON_R403, m_btn_r403);
	DDX_Control(pDX, IDC_BUTTON_R404, m_btn_r404);
	DDX_Control(pDX, IDC_BUTTON_R405, m_btn_r405);
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
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// RoomsInformationDlg message handlers

void RoomsInformationDlg::RoomHandler(CString roomnumber)
{
	// call to diaglog specific room
	SpecificRoomInformationDlg roomDlg;
	std::vector<CString> lstData;
	CString branchID, roomID, roomStatus = L"0";
	CString condition = L"STAFFID='" + staffID + L"'";
	DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"STAFF", condition, lstData);
	if (lstData.size() > 0)
	{
		branchID = lstData[1];
		std::vector<CString> roomData;
		CString condition = L"BRANCHID='" + branchID + L"' and ROOMNUMBER='" + roomnumber + L"'";
		DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"ROOM", condition, roomData);
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
	//	m_btn_r101.SetTextColor(RGB(0, 255, 0));
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
	CString roomnumber;
	switch (nIDCtl)
	{
		case IDC_BUTTON_R101:
			roomnumber = L"101";
			break;
		case IDC_BUTTON_R102:
			roomnumber = L"102";
			break;
		case IDC_BUTTON_R103:
			roomnumber = L"103";
			break;
		case IDC_BUTTON_R104:
			roomnumber = L"104";
			break;
		case IDC_BUTTON_R105:
			roomnumber = L"105";
			break;
		case IDC_BUTTON_R201:
			roomnumber = L"201";
			break;
		case IDC_BUTTON_R202:
			roomnumber = L"202";
			break;
		case IDC_BUTTON_R203:
			roomnumber = L"203";
			break;
		case IDC_BUTTON_R204:
			roomnumber = L"204";
			break;
		case IDC_BUTTON_R205:
			roomnumber = L"205";
			break;
		case IDC_BUTTON_R301:
			roomnumber = L"301";
			break;
		case IDC_BUTTON_R302:
			roomnumber = L"302";
			break;
		case IDC_BUTTON_R303:
			roomnumber = L"303";
			break;
		case IDC_BUTTON_R304:
			roomnumber = L"304";
			break;
		case IDC_BUTTON_R305:
			roomnumber = L"305";
			break;
		case IDC_BUTTON_R401:
			roomnumber = L"401";
			break;
		case IDC_BUTTON_R402:
			roomnumber = L"402";
			break;
		case IDC_BUTTON_R403:
			roomnumber = L"403";
			break;
		case IDC_BUTTON_R404:
			roomnumber = L"404";
			break;
		case IDC_BUTTON_R405:
			roomnumber = L"405";
			break;
		default:
			break;
	}

	SpecificRoomInformationDlg roomDlg;
	std::vector<CString> lstData;
	CString branchID, roomStatus = L"0";
	CString condition = L"STAFFID='" + staffID + L"'";
	DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"STAFF", condition, lstData);
	if (lstData.size() > 0)
	{
		branchID = lstData[1];
		std::vector<CString> roomData;
		CString condition = L"BRANCHID='" + branchID + L"' and ROOMNUMBER='" + roomnumber + L"'";
		DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"ROOM", condition, roomData);
		if (roomData.size() > 0)
		{
			roomStatus = roomData[2];
		}
	}

	bool isRented = (roomStatus == L"1") ? true : false;
	COLORREF color;
	if (isRented)
		color = RGB(255, 0, 0);
	else
		color = RGB(0, 0, 255);
	switch (nIDCtl)
	{
		case IDC_BUTTON_R101:
			m_btn_r101.SetTextColor(color);
			break;
		case IDC_BUTTON_R102:
			m_btn_r102.SetTextColor(color);
			break;
		case IDC_BUTTON_R103:
			m_btn_r103.SetTextColor(color);
			break;
		case IDC_BUTTON_R104:
			m_btn_r104.SetTextColor(color);
			break;
		case IDC_BUTTON_R105:
			m_btn_r105.SetTextColor(color);
			break;
		case IDC_BUTTON_R201:
			m_btn_r201.SetTextColor(color);
			break;
		case IDC_BUTTON_R202:
			m_btn_r202.SetTextColor(color);
			break;
		case IDC_BUTTON_R203:
			m_btn_r203.SetTextColor(color);
			break;
		case IDC_BUTTON_R204:
			m_btn_r204.SetTextColor(color);
			break;
		case IDC_BUTTON_R205:
			m_btn_r205.SetTextColor(color);
			break;
		case IDC_BUTTON_R301:
			m_btn_r301.SetTextColor(color);
			break;
		case IDC_BUTTON_R302:
			m_btn_r302.SetTextColor(color);
			break;
		case IDC_BUTTON_R303:
			m_btn_r303.SetTextColor(color);
			break;
		case IDC_BUTTON_R304:
			m_btn_r304.SetTextColor(color);
			break;
		case IDC_BUTTON_R305:
			m_btn_r305.SetTextColor(color);
			break;
		case IDC_BUTTON_R401:
			m_btn_r401.SetTextColor(color);
			break;
		case IDC_BUTTON_R402:
			m_btn_r402.SetTextColor(color);
			break;
		case IDC_BUTTON_R403:
			m_btn_r403.SetTextColor(color);
			break;
		case IDC_BUTTON_R404:
			m_btn_r404.SetTextColor(color);
			break;
		case IDC_BUTTON_R405:
			m_btn_r405.SetTextColor(color);
			break;
		default:
		break;
	}
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

