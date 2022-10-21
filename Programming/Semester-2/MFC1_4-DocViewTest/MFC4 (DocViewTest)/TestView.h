
// TestView.h : interface of the CTestView class
//

#pragma once


class CTestView : public CListView
{
protected: // create from serialization only
	CTestView() noexcept;
	DECLARE_DYNCREATE(CTestView)

// Attributes
public:
	CTestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	void FillList();


	//int AddStudent(Student* st)


// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnUpdateDelete(CCmdUI *pCmdUI);

	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // debug version in TestView.cpp
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif

