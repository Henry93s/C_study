#ifndef _REC_H_
#define _REC_H_

#include "geo.h"

class Rectangle : public GeometricFigure {
public:
	Rectangle();
	void SetWidth(const double width);
	void SetHeight(const double height);
	void CalArea();
	double GetWidth();
	double GetHeight();
	double GetArea();
	
private:
	double width;
	double height;
	double area;
};

#else
#endif