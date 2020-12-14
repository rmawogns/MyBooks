#pragma once


// BookAdd 대화 상자

class BookAdd : public CDialogEx
{
	DECLARE_DYNAMIC(BookAdd)

public:
	BookAdd(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~BookAdd();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnaddb();
	afx_msg void OnBnClickedCancel();
	CEdit m_strbookID;
	CEdit m_strbookName;
//	CEdit m_strbookContact;
//	CEdit m_strbookemail;
//	CEdit m_strbookSNS;
	CEdit m_strbookPrice;
	CEdit m_strbookauthorID;
	CEdit m_strbookpublisherID;
};
