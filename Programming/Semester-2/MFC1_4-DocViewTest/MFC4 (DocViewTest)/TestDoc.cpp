
// TestDoc.cpp : implementation of the CTestDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC4 (DocViewTest).h"
#endif

#include "TestDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestDoc

IMPLEMENT_DYNCREATE(CTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestDoc, CDocument)
END_MESSAGE_MAP()


// CTestDoc construction/destruction

CTestDoc::CTestDoc() noexcept
{
	// TODO: add one-time construction code here

}

CTestDoc::~CTestDoc()
{
}

BOOL CTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}




// CTestDoc serialization

void CTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		int nCount = m_list.GetCount();

		ar << nCount; 

		Student *st = m_list.GetFirst();
		while (st != NULL)
		{
			st->Serialize(ar);
			st = m_list.GetNext();
		}
	}
	else
	{
		int nCount = 0;
		ar >> nCount;

		for (int i = 0; i < nCount; ++i)
		{
			Student st;
			st.Serialize(ar);

			m_list.PushBack(&st);
		}
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTestDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTestDoc diagnostics

#ifdef _DEBUG
void CTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTestDoc commands


void CTestDoc::DeleteContents()
{
	m_list.Clear();

	CDocument::DeleteContents();
}
