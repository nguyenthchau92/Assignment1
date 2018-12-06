// SpecificRoomInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpecificRoomInformationDlg.h"
#include "afxdialogex.h"
#include "DatabaseAppication.h"


// SpecificRoomInformationDlg dialog

IMPLEMENT_DYNAMIC(SpecificRoomInformationDlg, CDialogEx)
int SpecificRoomInformationDlg::counterService = 0;

BOOL SpecificRoomInformationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	combox_sex.AddString(L"Male");
	combox_sex.AddString(L"Female");
	combox_sex.SetCurSel(0);

	if (isRented)
	{
		//1.2 For view information room
			//- If status room is not empty, I will get data from database(RentedRoom, Room) based on roomID
		// get data from database into diaglog
		//Name
		CString cs_nameCustomer;
		CString cs_idCustomer;
		CString cs_checkin;
		CString cs_checkout;

		// ID
		CString nameTable = L"renting";
		std::vector<std::vector<CString>> lstData;
		DatabaseAppication::getInstance()->ExecuteQuerySelect(nameTable, lstData);


		//Price per day

		// checkin day

		// checkout day
	}
	



	// update data to gui
	UpdateData(false);



	return TRUE;  // return TRUE  unless you set the focus to a control
}

SpecificRoomInformationDlg::SpecificRoomInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SpecificRoomInformationDlg::IDD, pParent)
{
	isRented = false;
}

SpecificRoomInformationDlg::~SpecificRoomInformationDlg()
{
}

void SpecificRoomInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME_CUSTOMER, edit_name_customer);
	DDX_Control(pDX, IDC_EDIT_ID_CUSTOMER, edit_id_customer);
	DDX_Control(pDX, IDC_DATETIMEPICKER_IN, datetime_checkin_room);
	DDX_Control(pDX, IDC_DATETIMEPICKER_OUT, datetime_checkout_room);
	DDX_Control(pDX, IDC_COMBO_SEX, combox_sex);
	DDX_Control(pDX, IDC_EDIT_AGE, edit_age);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, edit_address);
}


BEGIN_MESSAGE_MAP(SpecificRoomInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_ADD, &SpecificRoomInformationDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDOK, &SpecificRoomInformationDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SpecificRoomInformationDlg message handlers


void SpecificRoomInformationDlg::OnBnClickedBtnAdd()
{








}

void SpecificRoomInformationDlg::OnBnClickedOk()
{
	if (!isRented)
	{
		// 1.1 For renting room
		//  Get data from GUI(userID, date, ...)
		CString g_name, g_id, g_sex, g_checkin, g_checkout, g_age, g_address;
		edit_name_customer.GetWindowText(g_name);
		edit_id_customer.GetWindowText(g_id);
		combox_sex.GetLBText(combox_sex.GetCurSel(), g_sex);
		int iSex = _tstof(g_sex);
		if (iSex)
			g_sex = L"True";
		else
			g_sex = L"False";

		// get checkin and checkout day
		CString checkinDate, checkoutDate;
		CTime ctiDate, ctoDate;
		datetime_checkin_room.GetTime(ctiDate);
		ctiDate.GetDay();
		checkinDate.Format(L"%d-%d-%d", ctiDate.GetYear(), ctiDate.GetMonth(), ctiDate.GetDay());
		edit_age.GetWindowText(g_age);
		edit_address.GetWindowText(g_address);

		datetime_checkout_room.GetTime(ctoDate);
		ctoDate.GetDay();
		checkoutDate.Format(L"%d-%d-%d", ctoDate.GetYear(), ctoDate.GetMonth(), ctoDate.GetDay());

		// Create a serviceID
		counterService ++;
		CString serviceID;
		serviceID.Format(L"%s%d",  L"service" ,counterService);
		
		// Update table Customer
		std::vector<std::pair<DataType, CString>> lstField;
		lstField.push_back(std::make_pair(STRING, g_id));
		lstField.push_back(std::make_pair(STRING, g_sex));
		lstField.push_back(std::make_pair(STRING, g_address));
		lstField.push_back(std::make_pair(INTEGER, g_age));
		lstField.push_back(std::make_pair(STRING, g_name));
		DatabaseAppication::getInstance()->ExecuteQueryInsert(L"CUSTOMER", lstField);

		// Update reservation table
		std::vector<std::pair<DataType, CString>> lstReservationField;
 		lstReservationField.push_back(std::make_pair(STRING, serviceID));
		lstReservationField.push_back(std::make_pair(STRING, g_id));
		lstReservationField.push_back(std::make_pair(STRING, L"False"));
		lstReservationField.push_back(std::make_pair(STRING, checkinDate));
		lstReservationField.push_back(std::make_pair(STRING, checkoutDate));
		DatabaseAppication::getInstance()->ExecuteQueryInsert(L"RESERVAION", lstReservationField);
		
		// RentedRoom
		std::vector<std::pair<DataType, CString>> lstRentedRoomField;
		lstRentedRoomField.push_back(std::make_pair(STRING, serviceID));
		lstRentedRoomField.push_back(std::make_pair(STRING, staffID));
		lstRentedRoomField.push_back(std::make_pair(STRING, roomID));
		DatabaseAppication::getInstance()->ExecuteQueryInsert(L"RENTEDROOM", lstRentedRoomField);

		// Update status Room table is rented
		std::map<CString, std::pair<DataType, CString>> listData;
		listData[L"STATUS"] = std::make_pair(STRING, L"True");
		std::map<CString, std::pair<DataType, CString>> listCondition;
		listCondition[L"ROOMID"] = std::make_pair(STRING, roomID);
		DatabaseAppication::getInstance()->ExecuteQueryUpdate(L"ROOM", listData, listCondition);

		// RentedFood

		// Get price from room table
	}
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
