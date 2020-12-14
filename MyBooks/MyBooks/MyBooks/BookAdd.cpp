// BookAdd.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "BookAdd.h"
#include "afxdialogex.h"
#include <mysql.h>


// BookAdd 대화 상자

IMPLEMENT_DYNAMIC(BookAdd, CDialogEx)

BookAdd::BookAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

BookAdd::~BookAdd()
{
}

void BookAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_strbookID);
	DDX_Control(pDX, IDC_EDIT2, m_strbookName);
	//  DDX_Control(pDX, IDC_EDIT3, m_strbookContact);
	//  DDX_Control(pDX, IDC_EDIT4, m_strbookemail);
	//  DDX_Control(pDX, IDC_EDIT5, m_strbookSNS);
	DDX_Control(pDX, IDC_EDIT3, m_strbookPrice);
	DDX_Control(pDX, IDC_EDIT4, m_strbookauthorID);
	DDX_Control(pDX, IDC_EDIT5, m_strbookpublisherID);
}


BEGIN_MESSAGE_MAP(BookAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BTNADDB, &BookAdd::OnBnClickedBtnaddb)
	ON_BN_CLICKED(IDCANCEL, &BookAdd::OnBnClickedCancel)
END_MESSAGE_MAP()


// BookAdd 메시지 처리기


void BookAdd::OnBnClickedBtnaddb()
{
	MYSQL mysql;			// mysql을 사용하기 위한변수
	mysql_init(&mysql);		// mysql 초기화
	mysql_real_connect(&mysql, "localhost", "root", "hong", "mybooks", 0, NULL, 0);		// mysql 접속

	CString id, name, price, authorid, publisherid;
	m_strbookID.GetWindowTextA(id);
	m_strbookName.GetWindowTextA(name);
	m_strbookPrice.GetWindowTextA(price);
	m_strbookauthorID.GetWindowTextA(authorid);
	m_strbookpublisherID.GetWindowTextA(publisherid);

	int ret = AfxMessageBox("추가하시겠습니까?", MB_YESNO | MB_ICONQUESTION);
	if (ret == IDYES)
	{
		CString sql = "insert into book values(" + id + ",'" + name + "'" + "," + price + "," + authorid + "," + publisherid + ");";
		if (mysql_query(&mysql, sql))										
		{
			mysql_close(&mysql);
			AfxMessageBox("error");
			return;
		}
		OnBnClickedCancel();

	}
}


void BookAdd::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
