#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <string>
using namespace std;

int main() {
    int age = 20;
    cout << "현재 나이는 " << age << endl;

    int hp{ 100 };
    int level{ 10 };

    float moveSpeed = 2.5f;
    double PI = 3.1425;

    cout << "이동속도는 " << moveSpeed << endl;
    cout << "파이는 " << PI << endl;

    char grade = 'A';
    cout << "현재 등급은 " << grade << endl;

    bool b = false;
    cout << "불리언 b의 초기값 : " << b << endl;

    b = true;
    cout << "불리언 true를 입력한 후 " << b << endl;

    cout << "최종 불리언 값 : " << (b ? "참" : "거짓") << endl;

    string name = "네더라이트 검";
    char itemGrade = 'S';
    float power = 125.5f;
    float defence = 50.0f;
    int itemCount = 3;

    cout << "아이템 이름: " << name << "\n";
    cout << "등급: " << itemGrade << "\n";
    cout << "공격력: " << power << "\n";
    cout << "방어력: " << defence << "\n";
    cout << "아이템 개수: " << itemCount << "\n";

    return 0;
}


#endif
/*
현재 나이는 20
이동속도는 2.5
파이는 3.1425
현재 등급은 A
불리언 b의 초기값 : 0
불리언 true를 입력한 후 1
*/