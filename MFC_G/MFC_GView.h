
// MFC_GView.h: CMFCGView 클래스의 인터페이스
//

#pragma once


class CMFCGView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCGView() noexcept;
	DECLARE_DYNCREATE(CMFCGView)

// 특성입니다.
public:
	CMFCGDoc* GetDocument() const;

// 작업입니다.
public:
	BOOL m_bTransparent;	//텍스트 배경을 투명하게 할것인지
	COLORREF m_colorText;	//텍스트 전경색
	COLORREF m_colorBk;		//텍스트 배경색
	LOGFONT	 m_logFont;		//텍스트를 출력할 논리적 글꼴

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
// 구현입니다.
public:
	virtual ~CMFCGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFont();
	afx_msg void OnForecolor();
	afx_msg void OnBackcolor();
	afx_msg void OnBkmode();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32778();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFC_GView.cpp의 디버그 버전
inline CMFCGDoc* CMFCGView::GetDocument() const
   { return reinterpret_cast<CMFCGDoc*>(m_pDocument); }
#endif

