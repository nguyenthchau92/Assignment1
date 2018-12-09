#pragma once
#include "Resource.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include "afxcmn.h"


// InvoiceInformationDlg dialog

class InvoiceInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InvoiceInformationDlg)

public:
	InvoiceInformationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~InvoiceInformationDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_INVOICE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	CString identification;
	CString username;
	CString serviceID;
	CString staffID;
	CString timeInvoice;
	CString costInvoice;
	CString roomID;
	int numDay;
public:
	void setIdentification(CString identificaiton){ this->identification = identificaiton; };
	void setServiceID(CString serviceID){ this->serviceID = serviceID; };
	void setStaffID(CString staffID){ this->staffID = staffID; };
	void setUsername(CString username){ this->username = username; };
	void setRoomID(CString roomID) { this->roomID = roomID; };
	void setTimeInvoice(CString timeInvoice) { this->timeInvoice = timeInvoice; };
	void setNumDay(int numday) { this->numDay = numday; };

protected:
	CEdit edit_name_user;
public:
	CDateTimeCtrl datetime_picker_invoice;
protected:
	CEdit edit_staff_name;
	CListCtrl list_ctrl_item;
	CEdit edit_total_price;
};
