#pragma once
#include "Location.h"
class PointEarly : public Location{
private:
	COLORREF color;
public:
	PointEarly(int, int, COLORREF color = RGB(0, 0, 0));
	void Hide();
	void Show();
	void MoveTo(int, int);
	void setColor(COLORREF color);
	COLORREF getColor();
};

