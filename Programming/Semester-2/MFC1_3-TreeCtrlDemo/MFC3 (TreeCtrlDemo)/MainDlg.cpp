
// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC3 (TreeCtrlDemo).h"
#include "MainDlg.h"
#include "afxdialogex.h"

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
	: CDialog(IDD_MFC3TREECTRLDEMO_DIALOG, pParent)
	, m_sPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_ctrlTree);
	DDX_Control(pDX, IDC_LIST, m_ctrlList);
	DDX_Text(pDX, IDC_PATH, m_sPath);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &CMainDlg::OnTvnSelchangedTree)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CMainDlg::OnNMDblclkList)
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




	m_imageList.Create(16, 16, ILC_MASK | ILC_COLOR32, 3, 3);
	m_ctrlTree.SetImageList(&m_imageList, TVSIL_NORMAL);
	
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_FOLDER_CLOSE));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_FOLDER));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_STAR));
	
	m_ctrlList.InsertColumn(0, L"Name", LVCFMT_LEFT, 200);
	m_ctrlList.SetImageList(&m_imageList, LVSIL_SMALL);

	HTREEITEM hRoot = m_ctrlTree.InsertItem(L"Продукты", 0, 1, TVI_ROOT, TVI_SORT);

	HTREEITEM hMilks = m_ctrlTree.InsertItem(L"Молочные",	0, 1, hRoot, TVI_SORT);
	HTREEITEM hFruits = m_ctrlTree.InsertItem(L"Фрукты",	0, 1, hRoot, TVI_SORT);
	HTREEITEM hVegs = m_ctrlTree.InsertItem(L"Овощи",		0, 1, hRoot, TVI_SORT);

	m_ctrlTree.InsertItem(L"Творог",	2, 2, hMilks, TVI_SORT);
	m_ctrlTree.InsertItem(L"Сметана",	2, 2, hMilks, TVI_SORT);
	m_ctrlTree.InsertItem(L"Кефир",		2, 2, hMilks, TVI_SORT);

	m_ctrlTree.InsertItem(L"Яблоки",	2, 2, hFruits, TVI_SORT);
	m_ctrlTree.InsertItem(L"Киви",		2, 2, hFruits, TVI_SORT);
	m_ctrlTree.InsertItem(L"Апельсины", 2, 2, hFruits, TVI_SORT);
	m_ctrlTree.InsertItem(L"Бананы",	2, 2, hFruits, TVI_SORT);

	m_ctrlTree.InsertItem(L"Картофель", 2, 2, hVegs, TVI_SORT);
	m_ctrlTree.InsertItem(L"Капуста",	2, 2, hVegs, TVI_SORT);
	m_ctrlTree.InsertItem(L"Морковь",	2, 2, hVegs, TVI_SORT);


	m_ctrlTree.Select(hRoot, TVGN_CARET);	
	m_ctrlTree.Expand(hRoot, TVE_EXPAND);

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



void CMainDlg::OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	//1. Определить выделенный элемент дерева
	//2. Получить список дочерних эл-тов
	//3. Добавить эл-ты в список

	m_ctrlList.DeleteAllItems();

	HTREEITEM hSel = m_ctrlTree.GetSelectedItem();
	if (hSel == NULL)
	{
		return;
	}


	HTREEITEM hChild = m_ctrlTree.GetNextItem(hSel, TVGN_CHILD);

	while (hChild != NULL)
	{
		CString sCaption = m_ctrlTree.GetItemText(hChild);

		int nImage = 0, nSelImage = 0;
		m_ctrlTree.GetItemImage(hChild, nImage, nSelImage);
		m_ctrlList.InsertItem(m_ctrlList.GetItemCount(), sCaption, nImage);

		hChild = m_ctrlTree.GetNextItem(hChild, TVGN_NEXT);
	}

	m_sPath = GetTreePath(hSel);
	UpdateData(FALSE);

}


CString CMainDlg::GetTreePath(HTREEITEM hItem)
{
	CString sPath;

	HTREEITEM hParent = m_ctrlTree.GetNextItem(hItem, TVGN_PARENT);

	if (hParent != NULL)
	{
		sPath = GetTreePath(hParent);
	}
	sPath += L" \\ ";
	sPath += m_ctrlTree.GetItemText(hItem);
	return sPath;
}


void CMainDlg::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	POSITION pos = m_ctrlList.GetFirstSelectedItemPosition();

	if (!pos)
	{
		return;
	}

	int nItem = m_ctrlList.GetNextSelectedItem(pos);

	CString sCaption = m_ctrlList.GetItemText(nItem, 0);

	SelectTreeItemByCaption(m_ctrlTree.GetRootItem(), sCaption);
}


bool CMainDlg::SelectTreeItemByCaption(HTREEITEM hItem, CString sCaption)
{
	if (sCaption == m_ctrlTree.GetItemText(hItem))
	{
		m_ctrlTree.SelectItem(hItem);
		m_ctrlTree.Expand(hItem, TVE_EXPAND);
		return true;
	}

	HTREEITEM hChild = m_ctrlTree.GetNextItem(hItem, TVGN_CHILD);

	while (hChild != NULL)
	{
		if (SelectTreeItemByCaption(hChild, sCaption) == true)
			return true;
		hChild = m_ctrlTree.GetNextItem(hChild, TVGN_NEXT);
	}
	return false;
}