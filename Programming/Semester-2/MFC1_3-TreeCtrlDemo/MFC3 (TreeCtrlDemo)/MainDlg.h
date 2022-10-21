
// MainDlg.h : header file
//

#pragma once


// CMainDlg dialog
class CMainDlg : public CDialog
{
// Construction
public:
	CMainDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC3TREECTRLDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	CString GetTreePath(HTREEITEM hItem);
	bool SelectTreeItemByCaption(HTREEITEM hItem, CString sCaption);

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
	CTreeCtrl m_ctrlTree;
	CImageList m_imageList;
	afx_msg void OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_ctrlList;
	CString m_sPath;
	afx_msg void OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
};
