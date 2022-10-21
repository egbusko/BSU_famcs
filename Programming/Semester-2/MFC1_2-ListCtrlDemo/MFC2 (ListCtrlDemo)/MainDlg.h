
// MainDlg.h : header file
//

#pragma once
#include "list.h"


// CMainDlg dialog
class CMainDlg : public CDialog
{
// Construction
public:
	CMainDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC2LISTCTRLDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	static int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

// Implementation
protected:
	HICON m_hIcon;

	List m_list; 

	int		m_nSortColumn;
	BOOL	m_bSortAsc;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlList;
	void Fill_list();
	afx_msg void OnBtnAbout();
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnEdit();
	afx_msg void OnBtnDelete();
	afx_msg void OnDblclkListStudents(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemclickListStudents(NMHDR *pNMHDR, LRESULT *pResult);
};
