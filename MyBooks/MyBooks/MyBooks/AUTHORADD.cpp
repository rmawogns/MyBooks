// AUTHORADD.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "AUTHORADD.h"
#include "afxdialogex.h"
#include <mysql.h>

IMPLEMENT_DYNAMIC(AUTHORADD, CDialogEx)

AUTHORADD::AUTHORADD(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

AUTHORADD::~AUTHORADD()
{
}

void AUTHORADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_authorID);
	DDX_Control(pDX, IDC_EDIT1, m_strauthorID);
	DDX_Control(pDX, IDC_EDIT2, m_strauthorName);
	//  DDX_Control(pDX, IDC_EDIT3, m_strauthoremail);
	//  DDX_Control(pDX, IDC_EDIT4, m_strauthorSNS);
	DDX_Control(pDX, IDC_EDIT3, m_strauthorContact);
	DDX_Control(pDX, IDC_EDIT4, m_strauthoremail);
	DDX_Control(pDX, IDC_EDIT5, m_strauthorSNS);
}


BEGIN_MESSAGE_MAP(AUTHORADD, CDialogEx)
	ON_BN_CLICKED(IDC_BTNADDA, &AUTHORADD::OnBnClickedBtnadda)
	ON_BN_CLICKED(IDCANCEL, &AUTHORADD::OnBnClickedCancel)
END_MESSAGE_MAP()



void AUTHORADD::OnBnClickedBtnadda()
{
	MYSQL mysql;			// mysql을 사용하기 위한변수
	mysql_init(&mysql);		// mysql 초기화
	mysql_real_connect(&mysql, "localhost", "root", "hong", "mybooks", 0, NULL, 0);		// mysql 접속

	CString id, name, contact, email, sns;
	m_strauthorID.GetWindowTextA(id);
	m_strauthorName.GetWindowTextA(name);
	m_strauthorContact.GetWindowTextA(contact);
	m_strauthoremail.GetWindowTextA(email);
	m_strauthorSNS.GetWindowTextA(sns);

	int ret = AfxMessageBox("추가하시겠습니까?", MB_YESNO | MB_ICONQUESTION);
	if (ret == IDYES)
	{
		CString sql = "insert into author values(" + id + ",'" + name + "'" + ",'" + contact + "'" + ",'" + email + "'" + ",'" + sns + "'" + ");";
		if (mysql_query(&mysql, sql))										// mysql 질의
		{
			mysql_close(&mysql);
			AfxMessageBox("error");
			return;
		}
		OnBnClickedCancel();
		//MYSQL_RES* result = mysql_store_result(&mysql);					// 질의 결과 받기
		//CMyBooksDlg::OnBnClickedBtnload();
	}
}


void AUTHORADD::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
