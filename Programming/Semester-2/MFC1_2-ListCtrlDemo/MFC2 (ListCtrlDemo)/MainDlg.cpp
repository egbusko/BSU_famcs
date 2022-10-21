
// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC2 (ListCtrlDemo).h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "list.h"
#include "StudentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMainDlg dialog



CMainDlg::CMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MFC2LISTCTRLDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_nSortColumn = 0;
	m_bSortAsc = TRUE;
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STUDENTS, m_ctrlList);
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ABOUT, &CMainDlg::OnBtnAbout)
	ON_BN_CLICKED(IDC_BTN_ADD, &CMainDlg::OnBtnAdd)
	ON_BN_CLICKED(IDC_BTN_EDIT, &CMainDlg::OnBtnEdit)
	ON_BN_CLICKED(IDC_BTN_DELETE, &CMainDlg::OnBtnDelete)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_STUDENTS, &CMainDlg::OnDblclkListStudents)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CMainDlg::OnHdnItemclickListStudents)
END_MESSAGE_MAP()


// CMainDlg message handlers

BOOL CMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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




	m_ctrlList.InsertColumn(0, L"NSP", LVCFMT_LEFT, 200);
	m_ctrlList.InsertColumn(1, L"Number", LVCFMT_LEFT, 100);

	Fill_list();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMainDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMainDlg::Fill_list()
{
	m_ctrlList.DeleteAllItems();

	Student *st = m_list.GetFirst();
	while (st!=NULL)
	{
		int nItem = m_ctrlList.InsertItem(m_ctrlList.GetItemCount(), st->GetName(), -1);

		CString sMark;
		sMark.Format(L"%g", st->GetMark());

		m_ctrlList.SetItemText(nItem,1, sMark);
		m_ctrlList.SetItemData(nItem, (DWORD_PTR)st);

		st = m_list.GetNext();
	}

	m_ctrlList.SortItems(CompareFunc, (DWORD_PTR)this);
}




void CMainDlg::OnBtnAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}


void CMainDlg::OnBtnAdd()
{
	CStudentDlg dlg;

	if (IDOK==dlg.DoModal())
	{
		Student st;
		st.SetName(dlg.m_sFIO);
		st.SetMark(dlg.m_fMark);
		m_list.PushBack(&st);

		Fill_list();
	}
}


void CMainDlg::OnBtnEdit()
{
	if (m_ctrlList.GetSelectedCount()==0)
	{
		MessageBox(L"Choose element for editing", L"Information",MB_OK|MB_ICONINFORMATION);
		return;
	}

	POSITION pos = m_ctrlList.GetFirstSelectedItemPosition();
	if (pos != 0)
	{
		int nIndex = m_ctrlList.GetNextSelectedItem(pos);

		Student *st = (Student*)m_ctrlList.GetItemData(nIndex);
		if (st == NULL)
		{
			//* надо обработать ошибку
			return;
		}

		CStudentDlg dlg;
		dlg.m_sFIO = st->GetName();
		dlg.m_fMark = st->GetMark();

		if (IDOK == dlg.DoModal())
		{
			st->SetName(dlg.m_sFIO);
			st->SetMark(dlg.m_fMark);

			Fill_list();
		}

	}
}


void CMainDlg::OnBtnDelete()
{
	POSITION pos = m_ctrlList.GetFirstSelectedItemPosition();
	if (NULL==pos)
	{
		MessageBox(L"Choose element for deleting", L"Deleting", MB_OK | MB_ICONINFORMATION);
		return;
	}

	int nIndex = m_ctrlList.GetNextSelectedItem(pos);
	Student *st = (Student*)m_ctrlList.GetItemData(nIndex);

	CString sMsg;
	sMsg.Format(L"Delete student: \"%s\" ?",st->GetName());
	if (IDYES != MessageBox(sMsg, L"Deleting", MB_YESNO | MB_ICONQUESTION))
	{
		return;
	}

	for (Student *our = m_list.GetFirst(); our != NULL; our = m_list.GetNext())
	{
		if (our == st)
		{
			m_list.RemoveCurrent();
			break;
		}
	}
	Fill_list();
}




void CMainDlg::OnDblclkListStudents(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	if (m_ctrlList.GetSelectedCount() == 0)
		OnBtnAdd();
	else
		OnBtnEdit();

	*pResult = 0;
}




void CMainDlg::OnHdnItemclickListStudents(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);


	if (m_nSortColumn != phdr->iItem)
	{
		m_nSortColumn = phdr->iItem;
		m_bSortAsc = TRUE;
	}
	else
	{
		m_bSortAsc = !m_bSortAsc;
	}

	m_ctrlList.SortItems(CompareFunc, (DWORD_PTR)this);
		
	*pResult = 0;
}


int CALLBACK CMainDlg::CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{

	Student* st1 = (Student*)lParam1;
	Student* st2 = (Student*)lParam2;

	CMainDlg *pThis = (CMainDlg*)lParamSort;

	int nResult = 0;
	switch (pThis->m_nSortColumn)
	{
	case 0:
		nResult = st1->GetName().Compare(st2->GetName());
		break;

	case 1:
		if (st1->GetMark() < st2->GetMark())
		{
			nResult = -1;
		}
		else if (st1->GetMark() == st2->GetMark())
		{
			nResult = 0;
		}
		else
		{
			nResult = 1;
		}
		break;
	}

	if (pThis->m_bSortAsc==FALSE)
	{
		nResult = nResult * -1;
	}

	return nResult;
}