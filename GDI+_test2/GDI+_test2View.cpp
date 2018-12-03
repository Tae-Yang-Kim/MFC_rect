
// GDI+_test2View.cpp: CGDItest2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "GDI+_test2.h"
#endif

#include "GDI+_test2Doc.h"
#include "GDI+_test2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDItest2View

IMPLEMENT_DYNCREATE(CGDItest2View, CView)

BEGIN_MESSAGE_MAP(CGDItest2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CGDItest2View 생성/소멸

CGDItest2View::CGDItest2View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGDItest2View::~CGDItest2View()
{
}

BOOL CGDItest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGDItest2View 그리기

void CGDItest2View::OnDraw(CDC* pDC)
{
	CGDItest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	/*Graphics graphics(pDC->m_hDC);
	Pen pen(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256), 4);
	SolidBrush brush(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));

	graphics.DrawLine(&pen, 50, 50, 500, 50);
	graphics.DrawRectangle(&pen, 50, 100, 200, 100);
	graphics.FillRectangle(&brush, 300, 100, 200, 100);
	graphics.DrawEllipse(&pen, 50, 250, 200, 200);
	graphics.FillEllipse(&brush, 300, 250, 200, 200);
	graphics.DrawPie(&pen, 550, 100, 200, 200, 225, 90);
	graphics.FillPie(&brush, 550, 300, 200, 200, 225, 90);
	graphics.DrawArc(&pen, 800, 100, 200, 200, 225, 90);*/

	/*Graphics graphics(pDC->m_hDC);
	Pen pen(Color(255, 0, 0, 0), 3);
	int i = 0;

	Point points[] = { Point(30, 30), Point(120, 50),
		Point(170, 40), Point(160, 20),
		Point(280, 100), Point(150, 90),
		Point(90, 70), Point(50, 130), };

	int pointNum = sizeof(points) / sizeof(points[0]);
	graphics.DrawPolygon(&pen, points, pointNum);
	//다각형

	for (i = 0; i < pointNum; i++)
		points[i].X += 300;

	graphics.DrawClosedCurve(&pen, points, pointNum, 0.5f);
	for (i = 0; i < pointNum; i++)
		points[i].X += 300;
	graphics.DrawClosedCurve(&pen, points, pointNum, 1);

	for (i = 0; i < pointNum; i++) {
		points[i].X -= 600;
		points[i].Y += 200;
	}
	graphics.DrawCurve(&pen, points, pointNum, 0);
	//열린 커브
	for (i = 0; i < pointNum; i++) {
		points[i].X += 300;
	}
	graphics.DrawCurve(&pen, points, pointNum, 0.5);
	//열린 커브

	for (i = 0; i < pointNum; i++) {
		points[i].X += 300;
	}
	graphics.DrawCurve(&pen, points, pointNum, 1);*/

	/*Graphics graphics(pDC->m_hDC);


	Pen blackPen(Color(255, 0, 0, 0), 1);
	Pen greenPen(Color(255, 0, 255, 0), 10);

	greenPen.SetAlignment(PenAlignmentInset);
	graphics.DrawRectangle(&greenPen, 50, 50, 100, 100);
	graphics.DrawRectangle(&blackPen, 50, 50, 100, 100);

	greenPen.SetAlignment(PenAlignmentCenter);
	graphics.DrawRectangle(&greenPen, 180, 50, 100, 100);
	graphics.DrawRectangle(&blackPen, 180, 50, 100, 100);*/

	/*Graphics graphics(pDC->m_hDC);

	//선끝모양지양
	Pen capPen(Color(255, 0, 0, 0), 5);
	capPen.SetStartCap(LineCapSquare);
	capPen.SetEndCap(LineCapRound);
	graphics.DrawLine(&capPen, 50, 50, 400, 50);

	capPen.SetStartCap(LineCapTriangle);
	capPen.SetEndCap(LineCapNoAnchor);
	graphics.DrawLine(&capPen, 50, 100, 400, 100);

	capPen.SetStartCap(LineCapSquareAnchor);
	capPen.SetEndCap(LineCapRoundAnchor);
	graphics.DrawLine(&capPen, 50, 150, 400, 150);

	capPen.SetStartCap(LineCapDiamondAnchor);
	capPen.SetEndCap(LineCapArrowAnchor);
	graphics.DrawLine(&capPen, 50, 200, 400, 200);

	//선연결모양지정
	Pen joinPen(Color(255, 0, 0, 0), 10);

	joinPen.SetLineJoin(LineJoinBevel);
	graphics.DrawRectangle(&joinPen, 50, 250, 100, 100);

	joinPen.SetLineJoin(LineJoinMiter);
	graphics.DrawRectangle(&joinPen, 180, 250, 100, 100);

	joinPen.SetLineJoin(LineJoinRound);
	graphics.DrawRectangle(&joinPen, 310, 250, 100, 100);*/

	/*Graphics graphics(pDC->m_hDC);
	Pen pen(Color(255, 0, 0, 0), 3);

	pen.SetDashStyle(DashStyleSolid);//실선
	graphics.DrawLine(&pen, 50, 50, 400, 50);

	pen.SetDashStyle(DashStyleDash);//파선
	graphics.DrawLine(&pen, 50, 100, 400, 100);

	pen.SetDashStyle(DashStyleDot);//점선
	graphics.DrawLine(&pen, 50, 150, 400, 150);

	pen.SetDashStyle(DashStyleDashDot);//실선
	graphics.DrawLine(&pen, 50, 200, 400, 200);

	pen.SetDashStyle(DashStyleDashDotDot);//실선
	graphics.DrawLine(&pen, 50, 250, 400, 250);

	pen.SetDashOffset(5);//실선
	graphics.DrawLine(&pen, 50, 260, 400, 260);

	REAL dashVals[4] = { 5,1,2,1 };
	pen.SetDashPattern(dashVals, 4);
	graphics.DrawLine(&pen, 50, 310, 400, 310);*/

	/*Graphics graphics(pDC->m_hDC);

	CRect rect;
	GetClientRect(&rect);
	int x = 0, y = 0;

	SolidBrush brush(Color(rand() % 129, rand() % 256, rand() % 256, rand() % 256));

	x = rand() % rect.Width();
	y = rand() % rect.Height();
	graphics.FillRectangle(&brush, x, y, 200, 100);

	brush.SetColor(Color(rand() % 129, rand() % 256, rand() % 256, rand() % 256));
	x = rand() % rect.Width();
	y = rand() % rect.Height();
	graphics.FillEllipse(&brush, x, y, 200, 100);

	brush.SetColor(Color(rand() % 129, rand() % 256, rand() % 256, rand() % 256));
	x = rand() % rect.Width();
	y = rand() % rect.Height();
	graphics.FillPie(&brush, x, y, 200, 100, 135, 90);

	brush.SetColor(Color(rand() % 129, rand() % 256, rand() % 256, rand() % 256));
	//좌표지정
	Point *pPoints = new Point[6];
	for (int j = 0; j < 6; j++) {
		x = rand() % rect.Width();
		y = rand() % rect.Height();
		pPoints[j].X = x;
		pPoints[j].Y = y;
	}
	graphics.FillClosedCurve(&brush, pPoints, 6, FillModeAlternate, 1);
	delete[] pPoints;*/

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CGDItest2View 인쇄

BOOL CGDItest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGDItest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGDItest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGDItest2View 진단

#ifdef _DEBUG
void CGDItest2View::AssertValid() const
{
	CView::AssertValid();
}

void CGDItest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDItest2Doc* CGDItest2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDItest2Doc)));
	return (CGDItest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CGDItest2View 메시지 처리기
