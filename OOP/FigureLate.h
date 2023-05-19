#pragma once
#include "PointLate.h"
class FigureLate :public PointLate{
private:
	int radius;
	int height;
public:
	FigureLate(int, int, int, int, COLORREF = RGB(0, 0, 0));
	void Show();
	void Hide();
	int getRadius();
	int getHeight();
};

