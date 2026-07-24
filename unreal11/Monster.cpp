#include <iostream>
#include "Monster.h"
using namespace std;

// .h에서 선언한 내용을 바탕으로 정의한 함수

// name 조회
string Monster::GetName() 
{
	return name;
}

// name 업데이트
void Monster::SetName(string str) 
{
	name = str;
}

// hp 조회
int Monster::GetHp() {
	return hp;
}

// hp 업데이트
void Monster::SetHp(int point) {
	hp += point;
}


int main() 
{
	Monster* monster = new Monster(); // 구조체 동적할당
	monster->SetName("roger");
	monster->SetHp(100);

	cout << "몬스터 이름 : " << monster->GetName() << endl;
	cout << "몬스터의 체력 : " << monster->GetHp() << endl;

	monster->SetHp(-20);

	cout << "몬스터 체력 : " << monster->GetHp() << endl;

	delete monster;
	return 0;
}
