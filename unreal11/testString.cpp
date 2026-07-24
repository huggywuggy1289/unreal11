#include <iostream>
#include "Monster.h"
#include <algorithm>
#include <string>
using namespace std;

int main() {

	// 초급---------------------------------

	/*
	char charArray[] = "Hello, World!";
	int size = sizeof(charArray) - 1;

	// 문자열 출력
	cout << charArray << endl;
	// 순수 길이 출력 ; 문자열 배열을 만들면, 문자열의 끝을 표시하기 위해 맨 뒤에 눈에 안 보이는 Null 문자('\0')가 무조건 1개(1바이트) 붙는다.

	cout << size << endl; // 기댓값 13

	*/

	// 중급---------------------------------

	/*
	string str = "C++ Programming";
	str.replace(0, 3, "c");
	int length = str.length();

	cout << str << endl; // 기댓값 c Programming
	cout << length << endl; // 13

	// `.find()` 와 `.replace()`를 콤보로 갈겨서 "Programming" 이라는 단어를 찾아내고 "Language" 로 교체하여 최종 출력하세요.
	size_t pos = str.find("Programming");
	str.replace(pos, 11, "Language");

	cout << str << endl; // 기댓값 c Language
	*/

	/*
	실전 코딩테스트
	*/

	// 금지어 필터 (비속어 마스킹)---------------------------------

	/*
	string word;

	cin >> word;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		return 0;
	}

	size_t pos1 = 0;
	while ((pos = word.find("바보")) != string::npos)
	{
		word.replace(pos1, string("바보").length(), "**");
	}

	int size1 = word.length() + 1;
	char* chat = new char[size1];

	for (int i = 0; i < size1; i++) {
		chat[i] = word[i]; // 값하나씩넣기
	}
	cout << chat << endl;

	delete[] chat;
	chat = nullptr;
	*/

	// 대소문자 반전기---------------------------------

	string EngWord;

	cin >> EngWord;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		return 0;
	}

	// 내장된 문자열의 전체 길이
	int wordSize = EngWord.length() + 1;

	char* eng = new char[wordSize];

	for (int i = 0; i < wordSize; i++) {
		eng[i] = EngWord[i]; // eng배열에 EngWord에 있는 값을 넣기

		// 대소문자 판별 후 eng값 변경 (처음엔 Eng를 변경했지만, 이미 EngWord에서 값복사한 eng는 변경되지않기에
		// 검사도 변경도 eng에서 해야한다.)
		if (eng[i] >= 65 && eng[i] <= 90) // 대문자
		{
			//transform(EngWord.begin(), EngWord.end(), EngWord.begin(), ::tolower);
			transform(eng, eng + (wordSize - 1), eng, ::tolower);
		}
		else if (eng[i] >= 97 && eng[i] <= 122) // 소문자
		{
			//transform(EngWord.begin(), EngWord.end(), EngWord.begin(), ::toupper);
			transform(eng, eng + (wordSize - 1), eng, ::toupper);
		}
	}
	eng[wordSize - 1] = '\0'; // 맨마지막문장은 정확도를 위해 '\0'을 해줘야함

	cout << eng << endl;
	delete[] eng;
	eng = nullptr;

	return 0;
}