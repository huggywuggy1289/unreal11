#include <iostream>
#include <memory>
#include <cstdlib> // rand()
#include <ctime> // time()

using namespace std;

struct Player {
	string name = "";
	int hp = 0;
	int attackPower = 0;
	int critical = 0;
};

struct Monster {
	string Dname = "";
	int Dhp = 0;
	int DattackPower = 0;
	int Dcritical = 0;
};

//  객체의 주소를 전달받아 그 주소를 통해 원본데이터에 접근한다.(->가 그 의미)
void showPlayerInfo(Player* player) {

	cout << "플레이어 정보" << "\n";
	cout << "이름: " << player->name << "\n";
	cout << "HP: " << player->hp << "\n";
	cout << "공격력: " << player->attackPower << "\n";
	cout << "치명타: " << player->critical << endl;

}

// 객체의 별칭(구조체를 선언한 변수)을 전달받아 참조하여 그 객체의 주소안에 있는 값을 가져오는것
//void showMonsterInfo(Monster& monster) {
//	cout << "몬스터 정보" << "\n";
//	cout << "몬스터 이름: " << monster.Dname << "\n";
//	cout << "몬스터 HP: " << monster.Dhp << "\n";
//	cout << "몬스터 공격력: " << monster.DattackPower << "\n";
//	cout << "몬스터 치명타: " << monster.Dcritical << endl;
//}

void showMonsterInfo(Monster *monster) {
	cout << "몬스터 정보" << "\n";
	cout << "몬스터 이름: " << monster->Dname << "\n";
	cout << "몬스터 HP: " << monster->Dhp << "\n";
	cout << "몬스터 공격력: " << monster->DattackPower << "\n";
	cout << "몬스터 치명타: " << monster->Dcritical << endl;
}

// 플레이어가 데미지를 받는 함수
void takePlayerDamage(Player* player, Monster* monster) {

	player->hp -= monster->DattackPower / 100.0f;
	if (player->hp < 0) {
		player->hp = 0;
	}
	showPlayerInfo(player);
}

// 몬스터가 데미지를 받는 함수
void takeMonsterDamage(Monster* monster, Player* player) {

	//monster->Dhp -= player->attackPower;
	//if (monster->Dhp < 0) {
	//	monster->Dhp = 0;
	//}


	// 랜덤 데미지
	if (rand() % 100 <= player->critical)
	{
		cout << "\n치명타 발생!\n";
		monster->Dhp = monster->Dhp - (player->attackPower + 10);
	}
	else
	{
		monster->Dhp = monster->Dhp - player->attackPower;
	}
	if (monster->Dhp < 0) monster->Dhp = 0;

	showMonsterInfo(monster);
	
}

// 플레이어가 회복하는 함수
void healPlayer(Player* player, int amount) {
	player->hp += amount;
	if(player->hp > 100){
		player->hp = 100;
	}
}

// 참조처리
void TurnUpdate(int turn) {
	turn++;
}

//bool deadStateCheck(Player* p, Monster* m) {
//
//}

int main() 
{
	srand(time(NULL));

	// 스택 메모리에 저장
	Player player;
	Monster monster;

	int turn = 1;
	
	player.name = "재윤";
	player.hp = 10;
	player.attackPower = 20;
	player.critical = 20;

	monster.Dname = "마귀";
	monster.Dhp = 100;
	monster.DattackPower = 200;
	monster.Dcritical = 200;


	//takeMonsterDamage(&monster, &player);
	//cout << "공격받은 몬스터 체력 : " << monster.Dhp << endl; //기댓값 80 결괏값 80
	//takePlayerDamage(&player, &monster);
	//cout << "공격받은 플레이어 체력 : " << player.hp << endl; //기댓값 8 결괏값 8
	//healPlayer(&player, 1);
	//cout << "힐받은 플레이어 체력 : " << player.hp << endl; // 기댓값 9 결괏값 9

	while (monster.Dhp > 0) 
	{

		cout << "플레이어 턴" << endl;
		TurnUpdate(turn);

		if (player.hp > 0) 
		{

			int num = rand() % 3;

			switch (num)
			{
			case 1:// 1.공격
				takeMonsterDamage(&monster, &player);
				break;
			case 2: // 2.힐
				healPlayer(&player, 1);
				break;
			default:
				break;
			}
		}

		// 몬스터가 죽으면 나가고
		if (monster.Dhp <= 0) 
		{
			cout << "몬스터가 죽었습니다." << "\n";
			cout << player.name << "의 승리입니다!" << endl;
			break;
		}

		cout << "플레이어가 다 공격했으면 이제 몬스터 턴" << endl;

		TurnUpdate(turn);

		if (player.hp > 0) {
			takePlayerDamage(&player, &monster);
		}

		// 플레이어가 죽으면 나가고
		if (player.hp <= 0) {
			cout << "플레이어가 죽었습니다" << "\n";
			cout << monster.Dname << "의 승리입니다!" << endl;
			break;
		}
	}

	return 0;
}

