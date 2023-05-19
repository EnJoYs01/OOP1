#include "pch.h"
#include "PointEarly.h"

extern HDC hdc;


PointEarly::PointEarly(int X, int Y, COLORREF color) {
	this->setColor(color);
	this->setX(X);
	this->setY(Y);
}

void PointEarly::setColor(COLORREF color) {
	this->color = color;
}

COLORREF PointEarly::getColor() {
	return this->color;
}

void PointEarly::Show() {
	SetPixel(hdc, this->getX(), this->getY(), this->getColor());
}

void PointEarly::Hide() {
	COLORREF defColor = this->color;
	this->setColor(RGB(255, 255, 255));
	SetPixel(hdc, this->getX(), this->getY(), this->getColor());
	this->setColor(defColor);
}

void PointEarly::MoveTo(int X, int Y) {
	this->Hide();
	this->setX(X);
	this->setY(Y);
	this->Show();
}
