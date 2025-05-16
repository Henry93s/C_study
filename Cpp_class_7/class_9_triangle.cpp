#include "triangle.h"

Triangle::Triangle() { cout << "Triangle()" << endl; }
void Triangle::SetWidth(const int width) {
	this->width = width;
}
void Triangle::SetHeight(const int height) {
	this->height = height;
}
void Triangle::CalArea() {
	cout << (width * height / 2,0) << endl;
}
int Triangle::GetWidth() {
	return width;
}
int Triangle::GetHeight() {
	return this->height;
}
double Triangle::GetArea() {
	return this->area;
}