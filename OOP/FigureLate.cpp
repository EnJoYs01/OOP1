#include "pch.h"
#include "FigureLate.h"

extern HDC hdc;

FigureLate::FigureLate(int X, int Y, int Height, int Radius, COLORREF color) : PointLate(X, Y, color) {
	this->height = Height;
	this->radius = Radius;
}

void FigureLate::Show() {
	MoveToEx(hdc, this->getX(), this->getY(), NULL);
	HPEN pen = CreatePen(PS_SOLID, 2, this->getColor());
	SelectObject(hdc, pen);
	LineTo(hdc, this->getX() + 15, this->getY() - this->height);
	Ellipse(hdc, this->getX() + 15, this->getY() - this->height - 10, this->getX() + 15 + 40, this->getY() - this->height + 10);
	DeleteObject(pen);

	HRGN ellipse = CreateEllipticRgn(this->getX() - this->getRadius(), this->getY() - this->getRadius() / 2,
		this->getX() + this->getRadius(), this->getY() + this->getRadius() / 2);
	HBRUSH brush = CreateSolidBrush(this->getColor());
	FillRgn(hdc, ellipse, brush);
	DeleteObject(brush);
}

void FigureLate::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}

int FigureLate::getRadius() {
	return this->radius;
}

int FigureLate::getHeight() {
	return this->height;
}
