// ListRoomsInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HOTELManagement.h"
#include "ListRoomsInformationDlg.h"
#include "afxdialogex.h"
#include "Util.h"
#include "StoragePathDlg.h"
#include "HOTELManagementDlg.h"

IMPLEMENT_DYNAMIC(ListRoomsInformationDlg, CDialogEx)

ListRoomsInformationDlg::ListRoomsInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ListRoomsInformationDlg::IDD, pParent)
{
	index_item = -1;
	account_mng = "";
}

ListRoomsInformationDlg::~ListRoomsInformationDlg()
{
	if (!ac_info_list.empty())
	{
		ac_info_list.clear();
	}
}

void ListRoomsInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ListRoomsInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_ADD_NEW, &ListRoomsInformationDlg::OnBnClickedBtnAddNew)
	ON_BN_CLICKED(IDC_BTN_STORE_PATH, &ListRoomsInformationDlg::OnBnClickedBtnStorePath)
	ON_BN_CLICKED(IDC_BTN_REMOVE, &ListRoomsInformationDlg::OnBnClickedBtnRemove)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ROOM_INFO, OnItemChanged)
	ON_BN_CLICKED(IDC_BTN_MODIFY, &ListRoomsInformationDlg::OnBnClickedBtnModify)
	ON_BN_CLICKED(IDOK, &ListRoomsInformationDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ListRoomsInformationDlg message handlers
BOOL ListRoomsInformationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	InitInfoList();
	
	// fill data from database into list room information

	LoadInformation();
	return true;
}


void ListRoomsInformationDlg::InitInfoList()
{

}

void ListRoomsInformationDlg::LoadInformation()
{
	if (ac_info_list.empty())
	{
		ReadDataFromFile();
	}

	if (!ac_info_list.empty())
	{
		for (int i = 0; i < ac_info_list.size(); i++)
		{

		}
	}

}

void ListRoomsInformationDlg::WriteInformation()
{
	if (!ac_info_list.empty())
	{
		std::vector < std::string> data_list;
		for (int i = 0; i < ac_info_list.size(); i++)
		{
			RoomInfo ac_info = ac_info_list.at(i);
			std::string str_address = ac_info.get_address();
			std::string str_name = ac_info.get_user_name();
			std::string str_pass = ac_info.get_pass();
			std::string  str_email = ac_info.get_email();
			std::string str_other = ac_info.get_other();

			std::string str_split = "-";
			std::string str_full = str_address + str_split;
			str_full += str_name + str_split;
			str_full += str_pass + str_split;
			str_full += str_email + str_split;
			str_full += str_other;
		
			data_list.push_back(str_full);
		}
		std::string str_file_info = "\\" + account_mng + ".aci";
		std::string str_file;
		if (store_path.empty())
		{
			str_file = BasicUtil::CreatePathfileRoomInfo(str_file_info);
		}
		else
		{
			str_file = store_path + str_file_info;
		}
		BasicUtil::WriteFile(str_file, data_list);
	}
}

void ListRoomsInformationDlg::OnBnClickedBtnAddNew()
{
	CString str_address;
	CString str_user;
	CString str_pass;
	CString str_email;
	CString str_other;

	edit_address.GetWindowText(str_address);
	edit_username.GetWindowText(str_user);
	edit_password.GetWindowText(str_pass);
	edit_email.GetWindowText(str_email);
	edit_other.GetWindowText(str_other);

	if (str_address.IsEmpty() || str_user.IsEmpty() || str_pass.IsEmpty())
	{
		MessageBox(_T("Data are empty"), _T("Info"), MB_OK | MB_ICONWARNING);
	}
	else
	{
		RoomInfo ac_new;
		ac_new.set_full_info(std::string(CStringA(str_address)),
			std::string(CStringA(str_user)),
			std::string(CStringA(str_pass)),
			std::string(CStringA(str_email)),
			std::string(CStringA(str_other)));

		bool isDuplicate = false;
		for (int i = 0; i < ac_info_list.size(); i++)
		{
			RoomInfo ac_info = ac_info_list.at(i);
			if (ac_info.get_address().compare(ac_new.get_address()) == 0)
			{
				isDuplicate = true;
				break;
			}
		}

		if (!isDuplicate)
		{
			ac_info_list.push_back(ac_new);
			LoadInformation();
		}
		else
		{
			MessageBox(_T("This address has been existed!"), _T("Info"), MB_OK | MB_ICONWARNING);
		}
	}
}


void ListRoomsInformationDlg::OnBnClickedBtnStorePath()
{
	StoragePathDlg store_path_dlg;
	store_path_dlg.set_path(store_path);
	if (store_path_dlg.DoModal() == IDOK)
	{
		std::string new_path = store_path_dlg.get_path();
		if (new_path.compare(store_path) != 0)
		{
			store_path = new_path;
		}
	}
}

void ListRoomsInformationDlg::ReadDataFromFile()
{
	std::string fileInfo = "\\" + account_mng + ".aci";
	
	std::string pathToFile = store_path;
	pathToFile += fileInfo;
	std::vector<std::string> list_data = BasicUtil::ReadFileAc(pathToFile);

	int length = list_data.size();
	for (int i = 0; i < length; i++)
	{
		std::string str_line = list_data.at(i);
		std::vector<std::string> ret_list;
		BasicUtil::SplitString(str_line, ret_list, '-');

		if (ret_list.size() >= 5)
		{
			RoomInfo p_info;
			p_info.set_address(ret_list.at(0));
			p_info.set_user(ret_list.at(1));
			p_info.set_pass(ret_list.at(2));
			p_info.set_email(ret_list.at(3));
			p_info.set_other(ret_list.at(4));
			ac_info_list.push_back(p_info);
		}
	}
}

void ListRoomsInformationDlg::OnBnClickedBtnRemove()
{
	if (index_item >= 0)
	{
		
		
	}
}

void ListRoomsInformationDlg::OnBnClickedBtnModify()
{
	CString str_address;
	CString str_user;
	CString str_pass;
	CString str_email;
	CString str_other;

	edit_address.GetWindowText(str_address);
	edit_username.GetWindowText(str_user);
	edit_password.GetWindowText(str_pass);
	edit_email.GetWindowText(str_email);
	edit_other.GetWindowText(str_other);

	std::string str_add = CStringA(str_address);
	std::string str_us = CStringA(str_user);
	std::string str_pa = CStringA(str_pass);
	std::string str_em = CStringA(str_email);
	std::string str_o = CStringA(str_other);

	if (index_item >= 0 && index_item < ac_info_list.size())
	{
		RoomInfo ac_info = ac_info_list.at(index_item);
		ac_info.set_full_info(str_add, str_us, str_pa, str_em, str_o);
		ac_info_list.at(index_item) = ac_info;
	}

}


void ListRoomsInformationDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	WriteInformation();
}


void ListRoomsInformationDlg::OnItemChanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLISTVIEW* pNMLV = (NMLISTVIEW*)pNMHDR;
	if (pNMLV != NULL)
	{
		index_item = pNMLV->iItem;
	}

	FillData();
}

void ListRoomsInformationDlg::FillData()
{
	if (index_item >= 0)
	{

	}
}