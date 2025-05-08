#include <iostream>

using namespace std;

int main()
{
    bool a = true; // 1
    cout << "a=" << a <<endl; // 1
    a = false; // 0
    cout << "a=" << a <<endl; // 0
    a = -98;
    cout << "a=" << a <<endl; // 1 (0 이 아닌 값 : true)
    a=0;
    cout << "a=" << a <<endl; // 0

    return 0;
}
