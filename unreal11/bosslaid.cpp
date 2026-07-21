#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct Boss {
	string DragonName = "드래곤";
	int Dhp = 500;
	int Dattack = 40;
};
struct Hero {
	string HeroName;
	int Hhp = 100;
	int Hattack = 15;
	int Hdefense = 5;
	bool isAlive = true;

};

// 보스의 체력을 깎는 함수
void TakeBossDamage(Boss *b, int damage) {

	// 체력깎기(Hero 한명이 공격할때 받는 데미지)
	b->Dhp -= damage;
	if (b->Dhp <= 0) { // 체력은 음수가 될 수 없으므로
		b->Dhp = 0;
	}
}

void TakeHeroDamage(Hero* h, int damage) {

	h->Hhp -= damage;
	if (h->Hhp <= 0) {
		h->Hhp = 0;
		h->isAlive = false;
	}
}


int main() {

	srand(static_cast<unsigned int>(time(NULL)));
	int heroCount;

	// 단계 1 (파티 생성): 프로그램이 시작되면 "참가할 영웅의 수"를 입력받습니다.
	cout << "참가할 영웅의 수를 입력하세요 : " << endl;
	cin >> heroCount;
	if (cin.fail() || heroCount <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "유효한 타입이 아니거나 입력된 수가 적절하지 않습니다." << endl;
		return 0;
	}

	// 단계 2 (동적 할당): 입력받은 영웅 수만큼 영웅 구조체 배열을 동적 할당(new)하고, 각 영웅의 이름을 입력받아 초기화
	Hero* hero = new Hero[heroCount];
	Boss* boss = new Boss; // 보스는 한명
	
	cout << "각 영웅의 이름을 입력하세요 : " << endl;
	string heroName;
	for (int i = 0; i < heroCount; i++) {
		cout << i + 1 << "번 영웅 이름: ";
		cin >> hero[i].HeroName;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "유효한 타입이 아닙니다." << endl;
			continue;
		}
	}
	int turn = 1;

	// 전투 반복문 - 턴제(살아있는 모든 영웅이 차례대로 보스를 공격)
	while (boss->Dhp > 0) 
	{
		cout << "플레이어 턴" << turn++ << endl;
		for (int i = 0; i < heroCount; i++)
		{
			if (hero[i].isAlive)
			{
				int demage = hero[i].Hattack;
				TakeBossDamage(boss, demage);
				cout << "| " << hero[i].HeroName << "이(가) 보스를 공격했습니다! (보스 남은 체력: " << boss->Dhp << ")" << endl;

				if (boss->Dhp <= 0) break; // 보스가 죽으면 나가고
			}
		}

		if (turn > 3) {
			break;
		}
		// 보스가 죽었으니 전투종료
		if (boss->Dhp <= 0) {
			cout << "\n 보스 [" << boss->DragonName << "이 사망하셨습니다." << endl;
			cout << hero << "의 승리입니다!" << endl;
			break;
		}
// ------------------------------------------------------------------------------------
		cout << "플레이어들이 다 공격했으면 이제 보스 턴" << endl;

		// 살아있는 영웅 중 무작위(또는 순차적)로 1명을 지정해 공격
		vector<int> aliveIndices;

		// 살아있는 영웅들은 배열에 담기
		for (int i = 0; i < heroCount; i++) {
			if (hero[i].isAlive) {
				aliveIndices.push_back(i);
			}
		}

		// 단 한명이라도 있으면
		while (!aliveIndices.empty()) 
		{
			// 랜덤으로 뽑기
			
			// 배열 사이즈
			int aliveHero = aliveIndices.size();
			// 적절한 난수를 인덱스로 가져와서
			int randomIndex = rand() % aliveHero;
			int targetIndex = aliveIndices[randomIndex];

			// 선택된 영웅의 주소 가져오기
			Hero* targetHero = &hero[targetIndex];

			// 보스의 공격력에서 영웅의 방어력을 뺀 만큼 영웅의 체력이 감소
			int demage = (boss->Dattack) - (hero->Hdefense);
			if (demage < 1) demage = 1;

			// 공격
			TakeHeroDamage(targetHero, demage);
			cout << "보스가 무작위로 [" << targetHero->HeroName << "을(를) 공격했습니다! (받은 피해: " << demage << ")" << endl;
			cout << "   " << targetHero->HeroName << "의 남은 체력 : " << targetHero->Hhp << endl;

			if (!targetHero->isAlive) {
				cout << "[" << targetHero->HeroName << "]이(가) 전사했습니다..." << endl;

				// targetHero를 배열에서 빼기
				aliveIndices.erase(aliveIndices.begin() + (targetIndex));
				break;
			}
		}
		
	}
	delete[] hero;
	delete boss;
	return 0;

}