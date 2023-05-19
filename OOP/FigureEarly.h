#pragma once
#include "PointEarly.h"
class FigureEarly :public PointEarly{
private:
	int radius;
	int height;
public:
	FigureEarly(int, int, int, int, COLORREF = RGB(0, 0, 0));
	void MoveTo(int, int);
	void Show();
	void Hide();
	int getRadius();
	int getHeight();
};

