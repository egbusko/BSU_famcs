#pragma once


// CStudentEditDlg dialog

class CStudentEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CStudentEditDlg)

public:
	CStudentEditDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStudentEditDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STUDENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	float m_fMark;
};
