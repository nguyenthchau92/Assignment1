// RegisterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HOTELManagement.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"
#include "Util.h"

// RegisterDlg dialog

IMPLEMENT_DYNAMIC(RegisterDlg, CDialogEx)

RegisterDlg::RegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RegisterDlg::IDD, pParent)
{

}

RegisterDlg::~RegisterDlg()
{
}

void RegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_USERNAME_REGISTER, edit_reg_user);
	DDX_Control(pDX, IDC_EDIT_PASSWORD_REGISTER, edit_reg_pass);
	DDX_Control(pDX, IDC_EDIT_REPASSWORD_REGISTER, edit_reg_repass);
	DDX_Control(pDX, IDC_EDIT_STAFFID, edit_reg_staffID);
}


BEGIN_MESSAGE_MAP(RegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_APPROVE, &RegisterDlg::OnBnClickedBtnApprove)
END_MESSAGE_MAP()


// RegisterDlg message handlers


void RegisterDlg::OnBnClickedBtnApprove()
{
	CString str_staffID;
	CString str_user;
	CString str_pass;
	CString str_repass;
	bool isValid = true;

	edit_reg_staffID.GetWindowText(str_staffID);
	edit_reg_user.GetWindowText(str_user);
	edit_reg_pass.GetWindowText(str_pass);
	edit_reg_repass.GetWindowText(str_repass);

	if (str_staffID.IsEmpty())
	{
		MessageBox(_T("Staff ID is empty"), _T("Info"), MB_ICONWARNING | MB_OK);
		isValid = false;
	}
	if (str_user.IsEmpty())
	{
		MessageBox(_T("User name is empty!"), _T("Info"), MB_OK | MB_ICONWARNING);
		isValid = false;
	} 
	else if (str_pass.IsEmpty())
	{
		MessageBox(_T("Password is empty!"), _T("Info"), MB_OK | MB_ICONWARNING);
		isValid = false;
	} 
	else if (str_pass.Compare(str_repass) != 0)
	{
		MessageBox(_T("Password and re-password are not same!"), _T("Info"), MB_OK | MB_ICONWARNING);
		isValid = false;
	}

	if (isValid)
	{
		bool is_existed = false;
		// checking account is existence
		{
		/*	{
				CString str_user(data_list.front().c_str());
				if (str_u.CompareNoCase(str_user) == 0)
				{
					is_existed = true;
				}
			}*/
		}

		if (!is_existed)
		{
			set_user(str_user);
			set_password(str_pass);
			set_staffID(str_staffID);
			is_success = true;
			OnOK();
		}
		else
		{
			MessageBox(_T("Account has been existed! Choose another account"), _T("Info"), MB_OK | MB_ICONWARNING);
		}
	}

}


