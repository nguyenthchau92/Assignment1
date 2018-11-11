// StoragePathDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HOTELManagement.h"
#include "StoragePathDlg.h"
#include "afxdialogex.h"
#include "Util.h"


// StoragePathDlg dialog

IMPLEMENT_DYNAMIC(StoragePathDlg, CDialogEx)

StoragePathDlg::StoragePathDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(StoragePathDlg::IDD, pParent)
{

}

StoragePathDlg::~StoragePathDlg()
{
}

void StoragePathDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PATH, edit_store_path);
}


BEGIN_MESSAGE_MAP(StoragePathDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_BROWSER, &StoragePathDlg::OnBnClickedBtnBrowser)
	ON_BN_CLICKED(IDOK, &StoragePathDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// StoragePathDlg message handlers
BOOL StoragePathDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	if (!store_path.empty())
	{
		edit_store_path.SetWindowTextW(CString(store_path.c_str()));
	}
	return TRUE;
}

void StoragePathDlg::OnBnClickedBtnBrowser()
{
	CFolderPickerDialog dlgFolder;
	if (dlgFolder.DoModal() == IDOK)
	{
		CString str_new_path = dlgFolder.GetFolderPath();
		store_path = CStringA(str_new_path);
		edit_store_path.SetWindowTextW(str_new_path);
	}
}


void StoragePathDlg::OnBnClickedOk()
{
	CString str;
	edit_store_path.GetWindowText(str);
	store_path = CStringA(str);
	char *ch_path = BasicUtil::ConvertStringToChar(store_path);
	bool is_valid = BasicUtil::DirectoryExist(ch_path);
	if (is_valid)
	{
		CDialogEx::OnOK();
	}
	else
		MessageBox(_T("Folder Path is not exist"), _T("Info"), MB_OK | MB_ICONWARNING);
		
}

