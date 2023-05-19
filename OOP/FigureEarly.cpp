#include "pch.h"
#include "FigureEarly.h"

extern HDC hdc;

FigureEarly::FigureEarly(int X, int Y, int Height, int Radius, COLORREF color) : PointEarly(X, Y, color) {
	this->height = Height;
	this->radius = Radius;
}

void FigureEarly::Show() {
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

void FigureEarly::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}

int FigureEarly::getRadius() {
	return this->radius;
}

int FigureEarly::getHeight() {
	return this->height;
}

void FigureEarly::MoveTo(int X, int Y) {
	this->Hide();
	this->setX(X);
	this->setY(Y);
	this->Show();
}