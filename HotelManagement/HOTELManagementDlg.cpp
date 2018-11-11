
// ACManagementDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HOTELManagement.h"
#include "HOTELManagementDlg.h"
#include "afxdialogex.h"
#include "RegisterDlg.h"	
#include "Util.h"	
#include "AccountInformationDlg.h"
#include "AccountInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// HOTELManagementDlg dialog



HOTELManagementDlg::HOTELManagementDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(HOTELManagementDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void HOTELManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_USERNAME_LOGIN, edit_username);
	DDX_Control(pDX, IDC_EDIT_PASSWORD_LOGIN, edit_password);
}

BEGIN_MESSAGE_MAP(HOTELManagementDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOGIN, &HOTELManagementDlg::OnBnClickedBtnLogin)
	ON_BN_CLICKED(IDC_BTN_REGISTER, &HOTELManagementDlg::OnBnClickedBtnRegister)
END_MESSAGE_MAP()


// HOTELManagementDlg message handlers

BOOL HOTELManagementDlg::OnInitDialog()
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void HOTELManagementDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void HOTELManagementDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR HOTELManagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void HOTELManagementDlg::OnBnClickedBtnLogin()
{
	CString us_login;
	CString pass_login;

	edit_username.GetWindowText(us_login);
	edit_password.GetWindowText(pass_login);

	bool isLoginOk = false;
	bool isExistedAccount = true;

	if (p_ac_info != NULL)
	{
		CString str_user(p_ac_info->get_user_name().c_str());
		CString str_pass(p_ac_info->get_pass().c_str());

		if (us_login.CompareNoCase(str_user) == 0)
		{
			if (pass_login.Compare(str_pass) == 0)
			{
				isLoginOk = true;
			}
		}
	}
	else
	{
		std::string st_local_path = BasicUtil::CreatePathFileForAccount();
		std::vector<std::string> data_list = BasicUtil::ReadFileAc(st_local_path);
		if (data_list.empty())
		{
			MessageBox(_T("Account is not existed! Please register."), _T("Info"), MB_OK | MB_ICONWARNING);
			isExistedAccount = false;
		}
		else
		{
			p_ac_info = new AcInfomation();
			if (data_list.size() >= 2)
			{
				CString str_user(data_list.front().c_str());
				CString str_pass(data_list.at(1).c_str());
				
				p_ac_info->set_user(data_list.front());
				p_ac_info->set_pass(data_list.at(1));
				if (data_list.size() >= 3)
				{
					p_ac_info->set_path(data_list.at(2));
				}

				if (us_login.CompareNoCase(str_user) == 0)
				{
					if (pass_login.Compare(str_pass) == 0)
					{
						isLoginOk = true;
					}
				}
			}
		}
	}
	if (isLoginOk)
	{
		AccountInformationDlg aci_dlg;
		std::string user_mng = CStringA(us_login);
		aci_dlg.set_account_mng(user_mng);
		aci_dlg.set_store_path(p_ac_info->get_path());
	
		if (aci_dlg.DoModal() == IDOK)
		{
			std::string str_path = aci_dlg.get_store_path();
			if (str_path.compare(p_ac_info->get_path()) != 0)
			{
				p_ac_info->set_path(str_path);
				std::vector<std::string> data_list;
				data_list.push_back(p_ac_info->get_user_name());
				data_list.push_back(p_ac_info->get_pass());
				data_list.push_back(str_path);
				// create file ACM.acc
				std::string str_local_path = BasicUtil::CreatePathFileForAccount();
				BasicUtil::WriteFile(str_local_path, data_list);
			}
		}
	}
	else
	{
		if (isExistedAccount)
		{
			MessageBox(_T("Login failed"), _T("Info"), MB_OK | MB_ICONERROR);
		}
	}
}

void HOTELManagementDlg::OnBnClickedBtnRegister()
{
	RegisterDlg register_dlg;
	if (register_dlg.DoModal() == IDOK)
	{
		p_ac_info = new AcInfomation();
		CString str_u = register_dlg.get_str_user();
		CString str_pass = register_dlg.get_str_pass();
		bool isSuccess = register_dlg.get_is_success();
		if (isSuccess)
		{
			std::string strUser = CStringA(str_u);
			std::string strPass = CStringA(str_pass);
			p_ac_info->set_user(strUser);
			p_ac_info->set_pass(strPass);

			std::vector<std::string> data_list;
			data_list.push_back(strUser);
			data_list.push_back(strPass);

			std::string str_local_path = BasicUtil::CreatePathFileForAccount();
			BasicUtil::WriteFile(str_local_path, data_list);
		}
	}
}
