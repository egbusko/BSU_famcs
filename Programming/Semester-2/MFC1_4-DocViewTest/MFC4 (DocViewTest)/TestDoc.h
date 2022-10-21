
// TestDoc.h : interface of the CTestDoc class
//


#pragma once
#include "list.h"

#define UPDATE_ADD_STUDENT 1
#define UPDATE_DEL_STUDENT 2
#define UPDATE_EDIT_STUDENT 3

class CTestDoc : public CDocument
{
protected: // create from serialization only
	CTestDoc() noexcept;
	DECLARE_DYNCREATE(CTestDoc)

// Attributes
public:
	List m_list;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};
