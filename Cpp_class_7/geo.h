#ifndef _GEO_H2_
#define _GEO_H2_

#include <iostream>
#include <string>
using namespace std;


class GeometricFigure {
public:
	GeometricFigure();
	GeometricFigure(const string color);
	void SetColor(const string color);
	bool isPaint();
	string GetColor();
protected:
	string color;
};

#else
#endif