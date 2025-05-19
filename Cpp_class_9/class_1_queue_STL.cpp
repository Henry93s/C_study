#include <iostream>
#include <queue> // 선입선출 컨테이너 구조(vs 스택 : 후입선출)
/*
    queue(STL) : 선입선출 컨테이너 구조로 push 는 뒤에서, pop 은 앞에서
    정직하게 수행됨.
    -> C 에서 queue 를 구현할 때는 앞에서 부터 넣어도 index 로 관리하면 구현 가능함
*/
using namespace std;
int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // queue : 10 20 30 40
    for (int i = 0;i < q.size();i++) { // q.size() : pop 에 따라서 size 가 반영됨
        cout << q.front() << " "; // front : 10 20
        q.pop();
        // pop : 40 30
    }
    cout << endl;

    return 0;
}
