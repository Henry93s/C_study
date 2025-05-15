#ifndef _Triangle_h2_
#define _Triangle_h2_

#include "geo.h"

class Triangle : public GeometricFigure {
	public:
		Triangle();
		void SetWidth(const int width);
		void SetHeight(const int height);
		void CalArea();
		int GetWidth();
		int GetHeight();
		double GetArea();

	private:
		int width;
		int height;
		double area;
};

#else
#endif