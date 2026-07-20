//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//
//int main() {
//
//	string name;
//	int lv = 0;
//	int power = 0; // 힘
//	int quickness = 0; // 민첩
//	int hp = 0; // 체력
//	float attack_speed = 0.0f; // 공격속도
//	float move_speed = 0.0f; // 이동속도
//
//	cin >> name;
//	cin >> lv;
//	cin >> power;
//	cin >> quickness;
//	cin >> hp;
//	cin >> attack_speed;
//	cin >> move_speed;
//
//	// 공격력
//	int attack = power * 2 + lv * 5;
//	// 방어력
//	int defense = quickness / 2 + lv * 3;
//
//	//체력 증가량
//	float hpGrowth = hp * 0.1f;
//	
//	// 초당 공격횟수
//	float attackSpeed = 1.0f / attack_speed;
//	// 10초 동안 이동거리
//	float moveDistance = move_speed * 10.0f;
//
//	cout << "===== 캐릭터 정보 =====" << endl;
//	cout << "이름: " << name << endl;
//	cout << "레벨: " << lv << endl;
//	cout << endl;
//
//	cout << "===== 전투 정보 =====" << endl;
//	cout << "공격력: " << attack << endl;
//	cout << "방어력: " << defense << endl;
//	cout << "체력 증가량: " << hpGrowth << endl;
//	cout << "초당 공격 횟수: " << attackSpeed << endl;
//	cout << endl;
//
//	cout << "===== 이동 정보 =====" << endl;
//	cout << "10초 이동 거리: " << moveDistance << endl;
//	cout << "=======================" << endl;
//
//}