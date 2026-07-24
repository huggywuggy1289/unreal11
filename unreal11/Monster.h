#pragma once
#include <string>

using namespace std;

// 일종의 설계도 -> 이걸통해 객체를 생성한다
class Monster
{
private:
	int hp = 0;
	string name = "";

public:
	// 선언만
	string GetName();
	void SetName(string str);

	int GetHp();
	void SetHp(int point);
};