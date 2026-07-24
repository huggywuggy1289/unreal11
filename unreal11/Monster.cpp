#include <iostream>
#include "Monster.h"
using namespace std;

string Monster::GetName() 
{
	return name;
}

void Monster::SetName(string str) 
{
	name = str;
}

int Monster::GetHp() {
	return hp;
}

void Monster::SetHp(int point) {
	hp += point;
}
/*

int main() 
{
	Monster* monster = new Monster(); // 구조체 동적할당
	monster->SetName("roger");
	monster->SetHp(100);
}
*/