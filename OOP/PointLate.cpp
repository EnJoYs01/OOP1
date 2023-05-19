#include "pch.h"
#include "PointLate.h"

extern HDC hdc;

PointLate::PointLate(int X, int Y, COLORREF color) {
	this->setColor(color);
	this->setX(X);
	this->setY(Y);
}

void PointLate::setColor(COLORREF color) {
	this->color = color;
}

COLORREF PointLate::getColor() {
	return this->color;
}

void PointLate::Show() {
	SetPixel(hdc, this->getX(), this->getY(), this->getColor());
}

void PointLate::Hide() {
	COLORREF defColor = this->color;
	this->setColor(RGB(255, 255, 255));
	SetPixel(hdc, this->getX(), this->getY(), this->getColor());
	this->setColor(defColor);
}

void PointLate::MoveTo(int X, int Y) {
	this->Hide();
	this->setX(X);
	this->setY(Y);
	this->Show();
}