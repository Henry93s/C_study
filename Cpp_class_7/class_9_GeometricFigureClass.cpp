#include "geo.h"

GeometricFigure::GeometricFigure() {
	color = "white";
}

GeometricFigure::GeometricFigure(const string color) {
	this->color = color;
}

void GeometricFigure::SetColor(const string color) {
	this->color = color;
}

bool GeometricFigure::isPaint() {
	return (color == "white") ? false : true;
}

string GeometricFigure::GetColor() {
	return color;
}