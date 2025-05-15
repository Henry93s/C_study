#include "triangle.h"

int main() {
	Triangle triangle1;
	triangle1.SetWidth(2);
	triangle1.SetHeight(3);
	triangle1.CalArea();
	
	triangle1.SetColor("blue");
	cout << "삼각형 정보" << endl;
	cout << "밑변: " << triangle1.GetWidth() << endl;
	cout << "높이: " << triangle1.GetHeight() << endl;
	cout << "넓이: " << triangle1.GetArea() << endl;

	if (triangle1.isPaint()) {
		cout << "색 정보: " << triangle1.GetColor() << endl;
	}

	return 0;
}