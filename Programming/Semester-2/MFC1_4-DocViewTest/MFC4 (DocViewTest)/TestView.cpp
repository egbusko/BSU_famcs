
// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC4 (DocViewTest).h"
#endif

#include "TestDoc.h"
#include "TestView.h"
#include "CStudentEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestView

IMPLEMENT_DYNCREATE(CTestView, CListView)

BEGIN_MESSAGE_MAP(CTestView, CListView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CListView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_COMMAND(ID_MODIFY_ADD, OnAdd)
	ON_COMMAND(ID_MODIFY_DELETE, OnDelete)
	ON_UPDATE_COMMAND_UI(ID_MODIFY_DELETE, OnUpdateDelete)

END_MESSAGE_MAP()

// CTestView construction/destruction

CTestView::CTestView() noexcept
{
	// TODO: add construction code here

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}


void CTestView::OnDraw(CDC* /*pDC*/)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


void CTestView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	
	GetListCtrl().DeleteAllItems();
	FillList();
}


// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CListView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}


CTestDoc* CTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestView message handlers


int CTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	GetListCtrl().InsertColumn(0, L"Name", LVCFMT_LEFT, 150);
	GetListCtrl().InsertColumn(1, L"Mark", LVCFMT_LEFT, 150);

	return 0;
}





void CTestView::OnAdd()
{
	CStudentEditDlg dlg;

	if (IDOK == dlg.DoModal())
	{
		Student st;
		st.SetName(dlg.m_strName);
		st.SetMark(dlg.m_fMark);

		GetDocument()->m_list.PushBack(&st);

		//Делает возможным сохранить документ перед закрытием окна
		GetDocument()->SetModifiedFlag(TRUE);

		GetDocument()->UpdateAllViews(NULL, UPDATE_ADD_STUDENT, NULL);

	}

}

void CTestView::OnDelete()
{
	if (IDYES != MessageBox(L"Delete student ?", L"Confirmation", MB_YESNO | MB_ICONQUESTION))
	{
		return;
	}
	CListCtrl& rList = GetListCtrl();

	POSITION pos = rList.GetFirstSelectedItemPosition();

	while (pos)
	{
		int nItem = rList.GetNextSelectedItem(pos);

		Student*st = GetDocument()->m_list.GetFirst();

		while (st != NULL)
		{
			if (st == (Student*) rList.GetItemData(nItem))
			{
				GetDocument()->m_list.RemoveCurrent();
				break;
			}
			st = GetDocument()->m_list.GetNext();
		}
	}
	GetDocument()->SetModifiedFlag(TRUE);
	GetDocument()->UpdateAllViews(NULL, UPDATE_DEL_STUDENT, NULL);

}

void CTestView::OnUpdateDelete(CCmdUI * pCmdUI)
{
	BOOL bEnable = FALSE;
	if (GetListCtrl().GetSelectedCount() > 0)
	{
		bEnable = TRUE;
	}
	pCmdUI->Enable(bEnable);
}

void CTestView::FillList()
{
	CListCtrl& rList = GetListCtrl();
	rList.DeleteAllItems();

	Student *st = GetDocument()->m_list.GetFirst();

	for (; st != NULL; st = GetDocument()->m_list.GetNext())
	{
		int nPos = rList.InsertItem(rList.GetItemCount(), st->GetName(), 0);

		CString sMark;
		sMark.Format(L"%g", st->GetMark());
		rList.SetItemText(nPos, 1, sMark);
		rList.SetItemData(nPos, (DWORD_PTR) st);
		
	}
}


void CTestView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* pHint)
{
	FillList();

	/*switch (lHint)
	{

	case UPDATE_ADD_STUDENT:
		break;

	case UPDATE_DEL_STUDENT:
		break;

	case UPDATE_EDIT_STUDENT:
		break;
	}*/
	

}
