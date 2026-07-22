#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Player {
	string name = "";
	int hp = 0;
	int attackPower = 0;
	int critical = 0;
};

struct Monster {
	string name = "";
	int hp = 0;
	int attackPower = 0;
	int critical = 0;
};

// 정보 출력 함수
void showPlayerInfo(const Player* player) {
	cout << "\n[플레이어 정보]" << "\n";
	cout << "이름: " << player->name << "\n";
	cout << "HP: " << player->hp << "\n";
	cout << "공격력: " << player->attackPower << "\n";
	cout << "치명타: " << player->critical << "%\n";
}

void showMonsterInfo(const Monster* monster) {
	cout << "\n[몬스터 정보]" << "\n";
	cout << "이름: " << monster->name << "\n";
	cout << "HP: " << monster->hp << "\n";
	cout << "공격력: " << monster->attackPower << "\n";
	cout << "치명타: " << monster->critical << "%\n";
}

// 전투 기능 함수
void takePlayerDamage(Player* player, const Monster* monster) {
	int damage = monster->attackPower / 10;
	player->hp -= damage;
	if (player->hp < 0) player->hp = 0;

	cout << "\n⚔️ " << monster->name << "에게 " << damage << "의 데미지를 입었습니다!\n";
	showPlayerInfo(player);
}

void takeMonsterDamage(Monster* monster, const Player* player) {
	int damage = player->attackPower;

	if (rand() % 100 < player->critical) {
		cout << "\n💥 치명타 발생!";
		damage += 10;
	}

	monster->hp -= damage;
	if (monster->hp < 0) monster->hp = 0;

	cout << "\n⚔️ " << monster->name << "에게 " << damage << "의 데미지를 입혔습니다!\n";
	showMonsterInfo(monster);
}

void healPlayer(Player* player, int amount) {
	player->hp += amount;
	if (player->hp > 100) player->hp = 100;

	cout << "\n💚 체력을 " << amount << " 회복했습니다!";
	showPlayerInfo(player);
}

// -------------------------------------------------------------
// 📌 4단계 필수 요구사항 구현 파트
// -------------------------------------------------------------

// 1. 사용자 입력 함수 (1, 2 이외의 값 예외처리)
int UserInput() {
	int choice = 0;
	while (true) {
		cout << "\n행동을 선택하세요 (1. 공격 / 2. 힐): ";
		cin >> choice;

		// 숫자 1, 2만 입력받도록 처리
		if (choice == 1 || choice == 2) {
			return choice;
		}

		cout << "⚠️ 잘못된 입력입니다! 1 또는 2를 입력해 주세요." << endl;
	}
}

// 2. 턴 처리 함수 (참조 연산자 & 사용)
void TurnUpdate(int& turn) {
	turn++;
}

// 3. 죽음 상태 체크 함수 (게임 종료 여부 판단)
bool deadStateCheck(Player* p, Monster* m) {
	if (p->hp <= 0) {
		cout << "\n💀 플레이어가 죽었습니다." << "\n";
		cout << m->name << "의 승리입니다!" << endl;
		return true; // 누군가 죽었으므로 true 반환 (게임 종료)
	}

	if (m->hp <= 0) {
		cout << "\n🎉 몬스터가 죽었습니다." << "\n";
		cout << "🏆 " << p->name << "의 승리입니다!" << endl;
		return true; // 누군가 죽었으므로 true 반환 (게임 종료)
	}

	return false; // 둘 다 살아있음
}

// -------------------------------------------------------------

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Player player;
	Monster monster;

	int turn = 1;

	player.name = "재윤";
	player.hp = 10;
	player.attackPower = 20;
	player.critical = 20;

	monster.name = "마귀";
	monster.hp = 100;
	monster.attackPower = 20;
	monster.critical = 20;

	// 게임 루프 시작
	while (true)
	{
		cout << "\n================ [ Turn " << turn << " ] ================" << endl;

		// --- 1. 플레이어 턴 (우선권) ---
		cout << "▶ " << player.name << "의 턴!" << endl;
		int choice = UserInput();

		if (choice == 1) {
			takeMonsterDamage(&monster, &player);
		}
		else if (choice == 2) {
			healPlayer(&player, 5);
		}

		// 플레이어 공격 후 몬스터 사망 체크
		if (deadStateCheck(&player, &monster)) {
			break; // 사망 시 즉시 게임 종료
		}

		// --- 2. 몬스터 턴 ---
		cout << "\n▶ " << monster.name << "의 턴!" << endl;
		takePlayerDamage(&player, &monster);

		// 몬스터 공격 후 플레이어 사망 체크
		if (deadStateCheck(&player, &monster)) {
			break; // 사망 시 즉시 게임 종료
		}

		// --- 3. 턴 증가 ---
		TurnUpdate(turn);
	}

	cout << "\n게임을 종료합니다." << endl;
	return 0;
}
#endif