#include <iostream>
using namespace std;
int main() {
    int num = 10;
    int& ref = num; // ref �� num �� ����

    cout << "num= " << num << endl;
    cout << "ref= " << ref << endl; // num ���

    ref = 100;

    cout << "num= " << num << endl; // 100
    cout << "ref= " << ref << endl; // 100

    cout << "&num= " << &num << endl; // ���� �ּ�
    cout << "&ref= " << &ref << endl; // ���� �ּ�

    return 0;
}
