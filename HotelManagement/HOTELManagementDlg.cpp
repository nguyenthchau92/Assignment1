
// ACManagementDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HOTELManagement.h"
#include "HOTELManagementDlg.h"
#include "afxdialogex.h"
#include "RegisterDlg.h"	
#include "Util.h"	
#include "ListRoomsInformationDlg_bkg.h"
#include "RoomInfo.h"
#include <vector>
#include <tuple>
#include "DatabaseAppication.h"
#include "SpecificRoomInformationDlg.h"
#include "RoomsInformationDlg.h"

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
	// create an connection to database
	InitGUI();

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

	// get username and password from register table
	std::vector<std::vector<CString>> lstData;
	DatabaseAppication::getInstance()->ExecuteQuerySelect(L"register", lstData);

	// compare with data is input from GUI
	for (std::vector<std::vector<CString>>::iterator it = lstData.begin(); it != lstData.end(); ++it)
	{
		std::vector<CString> tmp = *it;
		if (tmp[0].Trim().Compare(us_login) == 0 && tmp[1].Trim().Compare(pass_login) == 0)
		{
			isLoginOk = true;
			break;
		}
	}
	// if yes, go to main monitor
	if (isLoginOk)
	{
		RoomsInformationDlg roomInfo_dlg;
		// find staffid based on us_login
		std::vector<std::vector<CString>> lstData;
		DatabaseAppication::getInstance()->ExecuteQuerySelect(L"register", lstData);
		// compare with data is input from GUI
		for (int i = 0; i < lstData.size(); i++)
		{
			std::vector<CString> tmp = lstData[i];
			if (tmp[0].Trim().Compare(us_login) == 0 )
			{
				roomInfo_dlg.setStaffID(tmp[2].Trim());
				break;
			}
		}

		if (roomInfo_dlg.DoModal() == IDOK)
		{
		

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
		CString str_user = register_dlg.get_str_user();
		CString str_pass = register_dlg.get_str_pass();
		CString str_staffID = register_dlg.get_str_staffID();

		bool isSuccess = register_dlg.get_is_success();
		if (isSuccess)
		{
			std::string strUser = CStringA(str_user);
			std::string strPass = CStringA(str_pass);
			CString query = L"insert into register values('";
			query += str_user + L"','" + str_pass + L"','" + str_staffID + L"')";
			MessageBox(query);		
			DatabaseAppication::getInstance()->ExecuteQuery(query);
		}
	}
}

void HOTELManagementDlg::InitGUI()
{
	DatabaseAppication::getInstance()->ConnectDB();
}



