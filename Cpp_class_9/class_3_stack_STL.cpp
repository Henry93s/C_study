#include <iostream>
#include <stack> // 후입선출 컨테이너 구조
/*
    stack(STL) : 후입선출 컨테이너 구조로 맨 위에서 원소를 push 하고
    마지막 인덱스에서 pop
*/
using namespace std;
int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // stack : 40 30 20 10
    for (int i = 0;i < st.size();i++) { // st.size() : pop 에 따라서 size 가 반영됨
        cout << st.top() << " "; // top : 40 30
        st.pop();
        // pop : 40 30
    }
    cout << endl;

    return 0;
}
