#pragma once


// AUTHORADD 대화 상자

class AUTHORADD : public CDialogEx
{
	DECLARE_DYNAMIC(AUTHORADD)

public:
	AUTHORADD(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~AUTHORADD();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnadda();
	afx_msg void OnBnClickedCancel();
//	CEdit m_authorID;
	CEdit m_strauthorID;
	CEdit m_strauthorName;
//	CEdit m_strauthoremail;
//	CEdit m_strauthorSNS;
	CEdit m_strauthorContact;
	CEdit m_strauthoremail;
	CEdit m_strauthorSNS;
};
