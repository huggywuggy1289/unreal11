#define RUN_THIS 0
#if RUN_THIS

#include <iostream>
#include <memory>

using namespace std;

// 구조체 생성 (학번, 이름, 프로그래밍 점수, 알고리즘점수, 평균값)
struct Student{

	int studentId;
	string name;
	int progScore;
	int algoScore;
	int avg;

};

// 평균 계산 함수
void avg(Student* s) {
	s->avg = (s->progScore + s->algoScore) / 2.0f;
}

// 점수 입력 검증 및 예외처리
float getValidScore(const string& subjectName) {

	float score;

	while (true) {
		cout << " - " << subjectName << "점수(0~100)" << endl;
		cin >> score;

		// 숫자가 아니거나 범위를 벗어난 입력처리
		if (cin.fail() || score < 0 || score > 100) {

			cin.clear();
			cin.ignore(10000, '\n');
			cout << " 적절하지 않은 타입이거나 유효한 범위가 아닙니다." << endl;
		}
		else {
			return score;
		}
	}
}

int main() {

	// 1. 전체 학생 수를 입력받습니다.
	int studentCount = 0;

	cout << "================성적 관리 리스트=================" << endl;
	while (true) {
		cout << "등록할 전체 학생의 수를 입력하세요: ";
		cin >> studentCount;

		if (!cin.fail() && studentCount > 0) break; // 학생 수는 0보다 커야 입력 진행

		cin.clear();
		cin.ignore(10000, '\n');
		cout << "오류! 올바른 학생 수를 입력해주세요. \n";
	}

	// 2. 입력받은 학생 수 만큼 동적 할당
	Student* students = new Student[studentCount];

	for (int i = 0; i < studentCount; i++) {
		cout << "\n[" << i + 1 << "/" << studentCount << "]번째 학생 정보 입력\n";

		cout << "- 학번: ";
		cin >> students[i].studentId;

		cout << "- 이름: ";
		cin >> students[i].name;

		students[i].progScore = getValidScore("프로그래밍");
		students[i].algoScore = getValidScore("알고리즘");

		avg(&students[i]);
	}

	system("cls");
	int choice = 0; // 선택을 포함할 변수

	while (choice != 3) {
		cout << "\n========== 메뉴 ==========\n";
		cout << "1. 전체 학생 성적조회\n";
		cout << "2. 장학금 수혜자 명단 조회\n";
		cout << "3. 프로그래밍 종료\n";
		cout << "선택: ";
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "잘못된 입력입니다. 숫자를 입력해주세요.\n";
			continue;
		}

		switch (choice) {
		case 1:
			system("cls");
			cout << "\n --- 전체 학생 성적 조회 --- \n";
			for (int i = 0; i < studentCount; i++) {
				cout << "학번 : " << students[i].studentId
					<< " | 이름 : " << students[i].name
					<< " | 프로그래밍 : " << students[i].progScore
					<< " | 알고리즘 : " << students[i].algoScore
					<< " | 평균 : " << students[i].avg << "\n";
			}
			break;

		case 2: {
			system("cls");
			cout << "\n --- 장학금 수혜자 명단 조회 --- \n";
			bool found = false;

			for (int i = 0; i < studentCount; i++) {
				if (students[i].algoScore >= 80 && students[i].progScore >= 80 && students[i].avg >= 90) {
					cout << "학번 : " << students[i].studentId
						<< " | 이름 : " << students[i].name
						<< " | 평균 : " << students[i].avg << "\n";
					found = true;
				}
			}

			if (!found) {
				cout << "장학금 수혜자가 없습니다.\n";
			}
			break;
		}

		case 3:
			system("cls");
			cout << "\n프로그램을 종료합니다.\n";
			break;

		default:
			cout << "1-3사이의 메뉴를 선택하세요.\n";
			break;
		}
	}

	delete[] students;

	return 0;
}

#endif;