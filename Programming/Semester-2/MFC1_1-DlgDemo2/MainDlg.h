
// MainDlg.h : header file
//

#pragma once


// CMainDlg dialog
class CMainDlg : public CDialogEx
{
// Construction
public:
	CMainDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGDEMO2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnGetFileIn();
	CString m_sFileIn;
	afx_msg void OnGetFileOut();
	CString m_sFileOut;
	afx_msg void OnProcess();
	bool ProcessFiles(CString sFileIn, CString sFileOut);
};
