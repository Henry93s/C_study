#include <iostream>

using namespace std;

void print(int& x)
{
	cout << "&x : " << x << endl;
}

void print(const int& x)
{
	cout << "const &x : " << x << endl;
}

void print(int&& x)
{
	cout << "&&x : " << x << endl;
}

int main(void)
{
	int a; // lvalue
	a = 10; // lvalue = rvalue
	int& x1 = a; // lvalue(ref) = rvalue
	const int& x2 = 10; // lvalue(const int&) = rvalue
	int&& x3 = 10; // lvalue(r-value ref) = rvalue 10
	int&& x4 = std::move(a); // lvalue(r-value ref) = rvalue(casted a)

	print(x1);    // 1 x1 = lvalue
	print(x2);    // 2 x2 = lvalue
	print(x3);    // 1 x3 = lvalue
	print(x4);    // 1 x4 = lvalue
	print(std::move(x4));    // 3 rvalue(casted)
	print(3);     // 3 rvalue

	return 0;
}