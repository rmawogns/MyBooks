// AddAuthor.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "AddAuthor.h"
#include "afxdialogex.h"


// AddAuthor 대화 상자

IMPLEMENT_DYNAMIC(AddAuthor, CDialogEx)

AddAuthor::AddAuthor(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDAUTHOR, pParent)
{

}

AddAuthor::~AddAuthor()
{
}

void AddAuthor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddAuthor, CDialogEx)
END_MESSAGE_MAP()


// AddAuthor 메시지 처리기
