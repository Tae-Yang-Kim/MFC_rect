
// MFC_GView.cpp: CMFCGView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_G.h"
#endif

#include "MFC_GDoc.h"
#include "MFC_GView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCGView

IMPLEMENT_DYNCREATE(CMFCGView, CView)

BEGIN_MESSAGE_MAP(CMFCGView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32778, &CMFCGView::On32778)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFCGView 생성/소멸

CMFCGView::CMFCGView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bTransparent = FALSE;
	m_colorText = RGB(0, 0, 255);
	m_colorBk = RGB(255, 255, 0);

	m_logFont.lfHeight			= 100;
	m_logFont.lfWidth			= 0;
	m_logFont.lfEscapement		= 0;
	m_logFont.lfOrientation		= 0;
	m_logFont.lfWeight			= FW_NORMAL;
	m_logFont.lfItalic			= FALSE;
	m_logFont.lfUnderline		= FALSE;
	m_logFont.lfStrikeOut		= FALSE;
	m_logFont.lfCharSet			= DEFAULT_CHARSET;
	m_logFont.lfOutPrecision	= OUT_CHARACTER_PRECIS;
	m_logFont.lfClipPrecision	= CLIP_CHARACTER_PRECIS;
	m_logFont.lfQuality			= DEFAULT_QUALITY;
	m_logFont.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	/*strcpy(m_logFont.lfFaceName, _T("Times New Roman"));*/
}

CMFCGView::~CMFCGView()
{
}

BOOL CMFCGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(
		CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), NULL, NULL);

	//return TRUE;
	return CView::PreCreateWindow(cs);
}

// CMFCGView 그리기

void CMFCGView::OnDraw(CDC* /*pDC*/)
{
	CMFCGDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCGView 인쇄

BOOL CMFCGView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCGView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCGView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCGView 진단

#ifdef _DEBUG
void CMFCGView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCGView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCGDoc* CMFCGView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCGDoc)));
	return (CMFCGDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCGView 메시지 처리기


void CMFCGView::On32778()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CMFCGView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	CRect rect;
	GetClientRect(&rect);
	CPen pen(PS_SOLID, 5, RGB(rand() % 256,
		rand() % 256, rand() % 256)), *pOldPen;
	CBrush brush(HS_CROSS, RGB(0, 255, 0)),
		brush1, *pOldBrush;
	pOldBrush = dc.SelectObject(&brush);
	dc.Rectangle(&rect);
	dc.SelectObject(pOldBrush);

	//경계선이 검은색 이고 내부가 비어있는 타원을 그린다.
	dc.SelectStockObject(BLACK_PEN);
	dc.SelectStockObject(NULL_BRUSH);
	dc.Ellipse(100, 50, 200, 200);

	//경계선이 없고 내부가 밝은 회색으로 채워진 다각형을 그린다.
	dc.SelectStockObject(NULL_PEN);
	dc.SelectStockObject(LTGRAY_BRUSH);
	POINT points[] = { {200,50}, {350, 150}, {300, 200}, {250, 150}, {200, 100} };
	dc.Polygon(points, 5);

	pOldPen = dc.SelectObject(&pen);
	brush1.CreateSolidBrush(RGB(rand() % 256,
		rand() % 256, rand() % 256));
	pOldBrush = dc.SelectObject(&brush1);
	dc.Rectangle(400, 50, 600, 250);
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);x
}
