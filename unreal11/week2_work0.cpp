#include <iostream>
using namespace std;

void compareTwoNumbers() {
    int a;
    int b;

    // 별도의 초기화가 필요없는 이유는, 실제 입력값이 덮어씌워진다.
    // 쓰레기값이 문제가 되는 경우는 선언만 하고 초기화나 cin같은 입력없이 바로 사용할때이다.
    cin >> a;
    cin >> b;

    if (a > b) {
        cout << "Bigger number : " << a << endl;
    }
    else if (a < b) {
        cout << "Bigger number : " << b << endl;
    }
    else {
        cout << "Both numbers are equal" << endl;
    }
}

int main() {
    compareTwoNumbers();
    return 0;
}