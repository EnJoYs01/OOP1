#pragma once
#include "Location.h"
class PointLate :public Location{
private:
	COLORREF color;
public:
	PointLate(int, int, COLORREF color = RGB(0, 0, 0));
	virtual void Hide();
	virtual void Show();
	void MoveTo(int, int);
	void setColor(COLORREF color);
	COLORREF getColor();
};

