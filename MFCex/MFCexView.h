
// MFCexView.h: CMFCexView 클래스의 인터페이스
//

#pragma once


class CMFCexView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCexView() noexcept;
	DECLARE_DYNCREATE(CMFCexView)

// 특성입니다.
public:
	CMFCexDoc* GetDocument() const;

// 작업입니다.
public:
	CList<CPoint, CPoint&> m_ArrList;
	CPoint m_Pt1, m_Pt2;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMFCexView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCexView.cpp의 디버그 버전
inline CMFCexDoc* CMFCexView::GetDocument() const
   { return reinterpret_cast<CMFCexDoc*>(m_pDocument); }
#endif

