// SpecificRoomInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpecificRoomInformationDlg.h"
#include "afxdialogex.h"
#include "DatabaseAppication.h"
#include "InvoiceInformationDlg.h"
#include "Util.h"

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

	listctrl_food.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	listctrl_food.InsertColumn(0, L"Name Food", LVCFMT_LEFT, 400);

	// clear old data
	listctrl_food.DeleteAllItems();
	
	combox_sex.AddString(L"Female");
	combox_sex.AddString(L"Male");
	combox_sex.SetCurSel(1);

	// create data for combo box food
	std::vector<CString> lstData;
	DatabaseAppication::getInstance()->ExecuteQueryDistinctSelect(L"FOOD", L"FOODNAME", lstData);
	for (size_t i = 0; i < lstData.size(); i++)
	{
		combo_food.AddString(lstData[i]);
	}
	combo_food.SetCurSel(0);

	if (isRented)
	{
		//1.2 For view information room
		//- If status room is not empty, get data from database(RentedRoom, Reservation) based on roomID
		std::vector<std::vector<CString>> lstRentedData;
		CString condition = L"ROOMID='" + this->roomID + L"'";
		DatabaseAppication::getInstance()->ExecuteQuerySelect(L"RENTEDROOM", lstRentedData);
		for (size_t i = 0; i < lstRentedData.size(); i++)
		{
			std::vector<CString> temp = lstRentedData[i];
			// find a row with same roomID
			if (this->roomID.Compare(temp[2].Trim()) == 0)
			{
				serviceID = temp[0].Trim();
				std::vector<CString> reservationData;
				CString condition = L"SERVICEID='" + serviceID + L"'";
				DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"RESERVATION", condition, reservationData);
				if (reservationData.size() > 0 && reservationData[2].Trim() == L"0")
				{
					g_customerID = reservationData[1].Trim();
					g_checkinDate = temp[3].Trim();
					g_checkoutdate = temp[4].Trim();
					// find user's information in customer table
					std::vector<CString> customerData;
					CString conditionCus = L"IDENTIFICATION='" + g_customerID + L"'";
					DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"CUSTOMER", conditionCus, customerData);
					CString gender = customerData[1].Trim();
					CString address = customerData[2].Trim();
					CString age = customerData[3].Trim();
					CString name = customerData[4].Trim();
					edit_name_customer.SetWindowText(name);
					edit_id_customer.SetWindowText(g_customerID);
					// update sex
					if (gender == L"1")
						combox_sex.SetCurSel(1);
					else
						combox_sex.SetCurSel(0);
					// update checkin to gui
					COleDateTime inTime;
					std::string sCheckinDate = CStringA(g_checkinDate.Trim());
					// yyy-mm-dd
					sCheckinDate = sCheckinDate.substr(0, sCheckinDate.find_first_of(" "));
					CString cs_sCheckinDate(sCheckinDate.c_str());
					inTime.ParseDateTime(cs_sCheckinDate);
					datetime_checkin_room.SetTime(inTime);
					
					// update checkout day to gui
					COleDateTime outTime;
					// yyy-mm-dd
					std::string sCheckoutDate = CStringA(g_checkoutdate.Trim());
					sCheckoutDate = sCheckoutDate.substr(0, sCheckoutDate.find_first_of(" "));
					CString cs_sCheckoutDate(sCheckoutDate.c_str());
					outTime.ParseDateTime(cs_sCheckoutDate);
					datetime_checkout_room.SetTime(outTime);

					// update age and address to gui
					edit_age.SetWindowText(age);
					edit_address.SetWindowText(address);
					// Insert food are used to gui
					std::vector<std::vector<CString>> lstFoodData;
					DatabaseAppication::getInstance()->ExecuteQuerySelect(L"USINGFOOD", lstFoodData);
					for (size_t i = 0; i < lstFoodData.size(); i++)
					{
						std::vector<CString> tmp = lstFoodData[i];
						CString foodID = tmp[2].Trim();
						if (tmp[0].Trim().Compare(serviceID) == 0)
						{
							std::vector<CString> foodData;
							CString condition = L"FOODID=" + foodID;
							DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"FOOD", condition, foodData);
							CString foodName = foodData[2];
							listctrl_food.InsertItem(i, foodName);
						}
					}
					break;
				}
			}
		}
	}
	
	// update data to gui
	UpdateData(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

SpecificRoomInformationDlg::SpecificRoomInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SpecificRoomInformationDlg::IDD, pParent)
{
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
	DDX_Control(pDX, IDC_COMBO_FOOD, combo_food);
	DDX_Control(pDX, IDC_LIST_FOOD, listctrl_food);
}


BEGIN_MESSAGE_MAP(SpecificRoomInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_ADD, &SpecificRoomInformationDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDOK, &SpecificRoomInformationDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_PAYMENT, &SpecificRoomInformationDlg::OnBnClickedButtonPayment)
END_MESSAGE_MAP()


// SpecificRoomInformationDlg message handlers


void SpecificRoomInformationDlg::OnBnClickedBtnAdd()
{
	int cur = combo_food.GetCurSel();
	CString foodName;
	combo_food.GetLBText(cur, foodName);
	listctrl_food.InsertItem(0, foodName.Trim());
	this->lstFood.push_back(foodName);
}

void SpecificRoomInformationDlg::OnBnClickedOk()
{
#pragma region MyRegion
	// get checkout and checkin day
	// get checkin and checkout day
	bool newRegister = false;
	CString oldtime;
	CString checkinDate, checkoutDate;
	CTime ctiDate, ctoDate;
	datetime_checkin_room.GetTime(ctiDate);
	ctiDate.GetDay();
	checkinDate.Format(L"%d-%d-%d", ctiDate.GetYear(), ctiDate.GetMonth(), ctiDate.GetDay());
	datetime_checkout_room.GetTime(ctoDate);
	ctoDate.GetDay();
	checkoutDate.Format(L"%d-%d-%d", ctoDate.GetYear(), ctoDate.GetMonth(), ctoDate.GetDay());

	if (isRented)
	{
		// based on roomID, find a service in RESERVATION table with paid=0
		std::vector<std::vector<CString>> lstRentedData;
		CString condition = L"ROOMID='" + this->roomID + L"'";
		DatabaseAppication::getInstance()->ExecuteQuerySelect(L"RENTEDROOM", lstRentedData);
		for (size_t i = 0; i < lstRentedData.size(); i++)
		{
			std::vector<CString> temp = lstRentedData[i];
			// find a row with same roomID
			if (this->roomID.Compare(temp[2].Trim()) == 0)
			{
				serviceID = temp[0].Trim();
				std::vector<CString> reservationData;
				CString condition = L"SERVICEID='" + serviceID + L"'";
				DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"RESERVATION", condition, reservationData);
				if (reservationData.size() > 0 && reservationData[2].Trim() == L"0")
				{
					oldtime = temp[4].Trim();
					break;
				}
			}
		}

		// compare with new checking day, if yes, turn on flag register
		if (CompareTwoTime(oldtime, checkinDate))
			newRegister = true;
	}

	if (!isRented || newRegister) // && newRented
	{
		// 1.1 For renting room
		//  Get data from GUI (userID, date, ...)
		CString g_sex, g_checkin, g_age, g_address;
		edit_name_customer.GetWindowText(g_name);
		edit_id_customer.GetWindowText(g_customerID);
		combox_sex.GetLBText(combox_sex.GetCurSel(), g_sex);
		int iSex = _tstof(g_sex);
		if (iSex)
			g_sex = L"True";
		else
			g_sex = L"False";

		edit_age.GetWindowText(g_age);
		edit_address.GetWindowText(g_address);

		//TODO: random algorithm + create a serviceID by current time
		auto timeNow = std::chrono::system_clock::now();
		auto duration = timeNow.time_since_epoch();
		typedef std::chrono::duration<long double> MySecondTick;
		this->serviceID.Format(L"%s%ld", L"service", duration.count());
		// update table Customer
		{
			std::vector<CString> customerData;
			CString condition = L"IDENTIFICATION='" + g_customerID + L"'";
			DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"CUSTOMER", condition, customerData);
			if (customerData.size() > 0)
			{
				// Update status Room table is rented
				std::map<CString, std::pair<DataType, CString>> listData;
				listData[L"CUSAGE"] = std::make_pair(INTEGER, g_age);
				listData[L"CUSADDRESS"] = std::make_pair(STRING, g_address);
				std::map<CString, std::pair<DataType, CString>> listCondition;
				listCondition[L"IDENTIFICATION"] = std::make_pair(STRING, g_customerID);
				DatabaseAppication::getInstance()->ExecuteQueryUpdate(L"CUSTOMER", listData, listCondition);
			}
			else
			{
				std::vector<std::pair<DataType, CString>> lstField;
				lstField.push_back(std::make_pair(STRING, g_customerID));
				lstField.push_back(std::make_pair(STRING, g_sex));
				lstField.push_back(std::make_pair(STRING, g_address));
				lstField.push_back(std::make_pair(INTEGER, g_age));
				lstField.push_back(std::make_pair(STRING, g_name));
				DatabaseAppication::getInstance()->ExecuteQueryInsert(L"CUSTOMER", lstField);
			}
		}
		// update reservation table
		std::vector<std::pair<DataType, CString>> lstReservationField;
 		lstReservationField.push_back(std::make_pair(STRING, this->serviceID));
		lstReservationField.push_back(std::make_pair(STRING, g_customerID));
		lstReservationField.push_back(std::make_pair(STRING, L"False"));
		DatabaseAppication::getInstance()->ExecuteQueryInsert(L"RESERVATION", lstReservationField);
		// RentedRoom
		std::vector<std::pair<DataType, CString>> lstRentedRoomField;
		lstRentedRoomField.push_back(std::make_pair(STRING, serviceID));
		lstRentedRoomField.push_back(std::make_pair(STRING, staffID));
		lstRentedRoomField.push_back(std::make_pair(STRING, roomID));
		lstRentedRoomField.push_back(std::make_pair(STRING, checkinDate));
		lstRentedRoomField.push_back(std::make_pair(STRING, checkoutDate));
		DatabaseAppication::getInstance()->ExecuteQueryInsert(L"RENTEDROOM", lstRentedRoomField);
		// Update status Room table is rented
		std::map<CString, std::pair<DataType, CString>> listData;
		listData[L"STATUS"] = std::make_pair(STRING, L"True");
		std::map<CString, std::pair<DataType, CString>> listCondition;
		listCondition[L"ROOMID"] = std::make_pair(INTEGER, roomID);
		DatabaseAppication::getInstance()->ExecuteQueryUpdate(L"ROOM", listData, listCondition);
		AddFood();
		// Get price from room table
	}
#pragma endregion
	else
	{
		//MessageBox(L"Room is not available");
		// Add food when has been reservation
		if (lstFood.size() > 0)
			AddFood(true);
	}
	CDialogEx::OnOK();
}

void SpecificRoomInformationDlg::AddFood(bool isAdditionalFood)
{
	// Insert to table FOODORDER
	if (!isAdditionalFood)
	{
		std::vector<std::pair<DataType, CString>> lstOrder;
		lstOrder.push_back(std::make_pair(STRING, this->serviceID));
		lstOrder.push_back(std::make_pair(STRING, this->g_customerID));
		lstOrder.push_back(std::make_pair(STRING, L"False"));
		DatabaseAppication::getInstance()->ExecuteQueryInsert(L"FOODORDER", lstOrder);
	}
	for (size_t i = 0; i < lstFood.size(); i++)
	{
		// Insert to table USINGFOOD
		std::vector<std::pair<DataType, CString>> lstField;
		lstField.push_back(std::make_pair(STRING, this->serviceID));
		lstField.push_back(std::make_pair(STRING, this->staffID));
		// find foodID to insert into usingfood table
		std::vector<CString> foodData;
		CString conditionFood = L"FOODNAME='" + lstFood[i] + L"' AND ISUSED='False'";
		DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"FOOD", conditionFood, foodData);
		CString foodID = foodData[0].Trim();
		lstField.push_back(std::make_pair(INTEGER, foodID));
		CTime t = CTime::GetCurrentTime();
		CString currentTime = t.Format("%Y%m%d");
		lstField.push_back(std::make_pair(STRING, currentTime));
		DatabaseAppication::getInstance()->ExecuteQueryInsert(L"USINGFOOD", lstField);
		// update status of used food in FOOD talbe is true
		// Update status Room table is rented
		std::map<CString, std::pair<DataType, CString>> listData;
		listData[L"ISUSED"] = std::make_pair(STRING, L"True");
		std::map<CString, std::pair<DataType, CString>> listCondition;
		listCondition[L"FOODID"] = std::make_pair(INTEGER, foodID);
		DatabaseAppication::getInstance()->ExecuteQueryUpdate(L"FOOD", listData, listCondition);
	}


}

void SpecificRoomInformationDlg::OnBnClickedButtonPayment()
{
	InvoiceInformationDlg invoice;
	invoice.setIdentification(g_customerID);
	invoice.setServiceID(serviceID);
	invoice.setStaffID(staffID);
	invoice.setRoomID(roomID);
	invoice.setTimeInvoice(g_checkoutdate);
	//g_checkinDate

	int numOfDay = GetNumDateBetweenTwoTime(g_checkinDate, g_checkoutdate);
	invoice.setNumDay(numOfDay);
	if (invoice.DoModal() == IDOK)
	{
		// go to invoice monitor
		CDialogEx::OnOK();

	}

	

}
