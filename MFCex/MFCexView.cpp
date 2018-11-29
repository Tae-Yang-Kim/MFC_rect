
// MFCexView.cpp: CMFCexView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCex.h"
#endif

#include "MFCexDoc.h"
#include "MFCexView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCexView

IMPLEMENT_DYNCREATE(CMFCexView, CView)

BEGIN_MESSAGE_MAP(CMFCexView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCexView 생성/소멸

CMFCexView::CMFCexView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCexView::~CMFCexView()
{
}

BOOL CMFCexView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCexView 그리기

void CMFCexView::OnDraw(CDC* pDC)
{
	CMFCexDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	/*CPoint point;
	for (POSITION pos = m_ArrList.GetHeadPosition();
		pos != NULL; m_ArrList.GetNext(pos)) {
		point = m_ArrList.GetAt(pos);
		Sleep(100);
		pDC->Rectangle(point.x - 25, point.y - 25, point.x + 25, point.y + 25);
	}*/
	CRect rect;
	GetClientRect(&rect);

	CPen pen, *pOldPen;
	pen.CreatePen(PS_SOLID, 3, RGB(rand()%255,
		rand() % 256, rand() % 256));
	pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(0, rect.bottom / 2);
	pDC->LineTo(rect.right, rect.bottom / 2);
	pDC->MoveTo(rect.right / 2, 0);
	pDC->LineTo(rect.right / 2, rect.bottom);
	pDC->SelectObject(pOldPen);

	CPoint *pPoint = new CPoint[6];
	for (int i = 0; i < 5; i++) {
		int x = rand() % rect.Width();
		int y = rand() % rect.Height();
		pPoint[i].x = x;
		pPoint[i].y = y;
	}
	pPoint[5] = pPoint[0];
	CBrush brush, *pOldBrush;
	brush.CreateSolidBrush(RGB(rand()%256,
		rand() % 256, rand() % 256));

	pOldBrush = pDC->SelectObject(&brush);
	pDC->Polygon(pPoint, 6);
	pDC->SelectObject(pOldBrush);
	delete[] pPoint;

}


// CMFCexView 진단

#ifdef _DEBUG
void CMFCexView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCexView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCexDoc* CMFCexView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCexDoc)));
	return (CMFCexDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCexView 메시지 처리기


void CMFCexView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//1. WinApi fuc
	/*CDC* pDC = GetDC();
	pDC->Rectangle(point.x - 25, point.y - 25, point.x + 25, point.y + 25);
	ReleaseDC(pDC);
	CView::OnLButtonDown(nFlags, point);*/

	//2. MFC class func
	/*CClientDC dc(this);
	dc.Rectangle(point.x - 25, point.y - 25, point.x + 25, point.y + 25);
	CView::OnLButtonDown(nFlags, point);*/

	//m_ArrList.AddTail(point);
	//Invalidate();  //다시그려라

	m_Pt1 = m_Pt2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCexView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	//SetTimer(0, 100, NULL);
}


void CMFCexView::OnDestroy()
{
	CView::OnDestroy();
	//KillTimer(0);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
#define OBJ_LINE		0
#define OBJ_RECTANGLE	1
#define OBJ_ELLIPSE		2
#define OBJ_ROUNDRECT	3
#define OBJ_CHORD		4
#define OBJ_PIE			5

void CMFCexView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC	dc(this);
	CRect rect;
	CBrush brush, *pOldBrush;
	CPen pen, *pOldPen;

	int x1, y1, x2, y2, x3, y3, x4, y4;
	int r, g, b;
	int nObject;

	GetClientRect(rect);

	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;

	brush.CreateSolidBrush(RGB(r, g, b));
	pOldBrush = (CBrush *)dc.SelectObject(&brush);

	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;

	pen.CreatePen(PS_SOLID, 5, RGB(r, g, b));

	pOldPen = (CPen*)dc.SelectObject(&pen);

	x1 = rand() % rect.right;
	y1 = rand() % rect.bottom;
	x2 = rand() % rect.right;
	y2 = rand() % rect.bottom;
	x3 = rand() % rect.right;
	y3 = rand() % rect.bottom;
	x4 = rand() % rect.right;
	y4 = rand() % rect.bottom;

	nObject = rand() % 6;

	switch (nObject) {
	case OBJ_LINE:
		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y2);
		break;
	case OBJ_RECTANGLE:
		dc.Rectangle(x1, y1, x2, y2);
		break;
	case OBJ_ELLIPSE:
		dc.Ellipse(x1, y1, x2, y2);
		break;
	case OBJ_ROUNDRECT:
		dc.RoundRect(x1, y1, x2, y2, x3, y3);
		break;
	case OBJ_CHORD:
		dc.Chord(x1, y1, x2, y2, x3, y3, x4, y4);
		break;
	case OBJ_PIE:
		dc.Pie(x1, y1, x2, y2, x3, y3, x4, y4);
		break;
	}

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);

	CView::OnTimer(nIDEvent);
}


void CMFCexView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON) {
		CClientDC dc(this);

		//레스트 오퍼레이션
		dc.SetROP2(R2_XORPEN);

		dc.SelectStockObject(WHITE_PEN);

		dc.MoveTo(m_Pt1);
		dc.LineTo(m_Pt2);

		dc.MoveTo(m_Pt1);
		dc.LineTo(point);

		m_Pt2 = point;
	}
	CView::OnMouseMove(nFlags, point);
}
