// AccountInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HOTELManagement.h"
#include "AccountInformationDlg.h"
#include "afxdialogex.h"
#include "Util.h"
#include "StoragePathDlg.h"


// AccountInformationDlg dialog

IMPLEMENT_DYNAMIC(AccountInformationDlg, CDialogEx)

AccountInformationDlg::AccountInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AccountInformationDlg::IDD, pParent)
{
	index_item = -1;
	account_mng = "";
}

AccountInformationDlg::~AccountInformationDlg()
{
	if (!ac_info_list.empty())
	{
		ac_info_list.clear();
	}
}

void AccountInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, edit_address);
	DDX_Control(pDX, IDC_EDIT_USERNAME, edit_username);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, edit_password);
	DDX_Control(pDX, IDC_EDIT_EMAIL, edit_email);
	DDX_Control(pDX, IDC_EDIT_OTHER, edit_other);
	DDX_Control(pDX, IDC_LIST_INFO, list_information);
}


BEGIN_MESSAGE_MAP(AccountInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_ADD_NEW, &AccountInformationDlg::OnBnClickedBtnAddNew)
	ON_BN_CLICKED(IDC_BTN_STORE_PATH, &AccountInformationDlg::OnBnClickedBtnStorePath)
	ON_BN_CLICKED(IDC_BTN_REMOVE, &AccountInformationDlg::OnBnClickedBtnRemove)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_INFO, OnItemChanged)
	ON_BN_CLICKED(IDC_BTN_MODIFY, &AccountInformationDlg::OnBnClickedBtnModify)
	ON_BN_CLICKED(IDOK, &AccountInformationDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// AccountInformationDlg message handlers
BOOL AccountInformationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	InitInfoList();
	LoadInformation();
	return true;
}


void AccountInformationDlg::InitInfoList()
{
	list_information.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	list_information.InsertColumn(0, _T("Address"), LVCFMT_LEFT, 100);
	list_information.InsertColumn(1, _T("Name"), LVCFMT_LEFT, 80);
	list_information.InsertColumn(2, _T("Pass"), LVCFMT_LEFT, 80);
	list_information.InsertColumn(3, _T("Email"), LVCFMT_LEFT, 40);
	list_information.InsertColumn(4, _T("Other"), LVCFMT_LEFT, 40);
	list_information.ShowScrollBar(SB_VERT);
}

void AccountInformationDlg::LoadInformation()
{
	if (ac_info_list.empty())
	{
		ReadDataFromFile();
	}

	list_information.DeleteAllItems();
	if (!ac_info_list.empty())
	{
		for (int i = 0; i < ac_info_list.size(); i++)
		{
			AccountInfo ac_info = ac_info_list.at(i);

			std::string str_address = ac_info.get_address();
			std::string str_user = ac_info.get_user_name();
			std::string str_pass = ac_info.get_pass();
			std::string str_email = ac_info.get_email();
			std::string str_other = ac_info.get_other();

			list_information.InsertItem(0, CString(str_address.c_str()));
			list_information.SetItemText(0, 1, CString(str_user.c_str()));
			list_information.SetItemText(0, 2, CString(str_pass.c_str()));
			list_information.SetItemText(0, 3, CString(str_email.c_str()));
			list_information.SetItemText(0, 4, CString(str_other.c_str()));
		}
	}

	if (store_path.empty())
	{
		store_path = BasicUtil::GetLocalPathFolder() + "\\ACManagement";
		MessageBox(CString(store_path.c_str()), _T("Info"), MB_OK);
	}
}

void AccountInformationDlg::WriteInformation()
{
	if (!ac_info_list.empty())
	{
		std::vector < std::string> data_list;
		for (int i = 0; i < ac_info_list.size(); i++)
		{
			AccountInfo ac_info = ac_info_list.at(i);
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
			str_file = BasicUtil::CreatePathfileAccountInfo(str_file_info);
		}
		else
		{
			str_file = store_path + str_file_info;
		}
		BasicUtil::WriteFile(str_file, data_list);
	}
}

void AccountInformationDlg::OnBnClickedBtnAddNew()
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
		AccountInfo ac_new;
		ac_new.set_full_info(std::string(CStringA(str_address)),
			std::string(CStringA(str_user)),
			std::string(CStringA(str_pass)),
			std::string(CStringA(str_email)),
			std::string(CStringA(str_other)));

		bool isDuplicate = false;
		for (int i = 0; i < ac_info_list.size(); i++)
		{
			AccountInfo ac_info = ac_info_list.at(i);
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


void AccountInformationDlg::OnBnClickedBtnStorePath()
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

void AccountInformationDlg::ReadDataFromFile()
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
			AccountInfo p_info;
			p_info.set_address(ret_list.at(0));
			p_info.set_user(ret_list.at(1));
			p_info.set_pass(ret_list.at(2));
			p_info.set_email(ret_list.at(3));
			p_info.set_other(ret_list.at(4));
			ac_info_list.push_back(p_info);
		}
	}
}

void AccountInformationDlg::OnBnClickedBtnRemove()
{
	if (index_item >= 0)
	{
		CString str_address = list_information.GetItemText(index_item, 0);
		list_information.DeleteItem(index_item);

		for (int i = 0; i < ac_info_list.size(); i++)
		{
			std::string str = ac_info_list.at(i).get_address();
			CString str_ad = CString(str.c_str());
			if (str_ad.Compare(str_address) == 0)
			{
				ac_info_list.erase(ac_info_list.begin() + i);
			}
		}
	}
}

void AccountInformationDlg::OnBnClickedBtnModify()
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
		AccountInfo ac_info = ac_info_list.at(index_item);
		ac_info.set_full_info(str_add, str_us, str_pa, str_em, str_o);
		ac_info_list.at(index_item) = ac_info;

		list_information.SetItemText(index_item, 0, str_address);
		list_information.SetItemText(index_item, 1, str_user);
		list_information.SetItemText(index_item, 2, str_pass);
		list_information.SetItemText(index_item, 3, str_email);
		list_information.SetItemText(index_item, 4, str_other);
	}

}


void AccountInformationDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	WriteInformation();
}


void AccountInformationDlg::OnItemChanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLISTVIEW* pNMLV = (NMLISTVIEW*)pNMHDR;
	if (pNMLV != NULL)
	{
		index_item = pNMLV->iItem;
	}

	FillData();
}

void AccountInformationDlg::FillData()
{
	if (index_item >= 0)
	{
		CString str_adress = list_information.GetItemText(index_item, 0);
		CString str_name = list_information.GetItemText(index_item, 1);
		CString str_pass = list_information.GetItemText(index_item, 2);
		CString str_email = list_information.GetItemText(index_item, 3);
		CString str_other = list_information.GetItemText(index_item, 4);

		edit_address.SetWindowText(str_adress);
		edit_username.SetWindowText(str_name);
		edit_password.SetWindowText(str_pass);
		edit_email.SetWindowText(str_email);
		edit_other.SetWindowText(str_other);
	}
}