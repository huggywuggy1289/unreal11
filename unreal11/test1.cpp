#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int age = 23;
	int hp(100); // int hp = 100;
	int level(1); // "

	float height = 180.5f;
	double PI = 3.141592;
	char grade = 'A';
	bool isAlive = true;

	cout << "나이: " << age << endl;
	cout << "체력: " << hp << endl;
	cout << "레벨: " << level << endl;
	cout << "신장: " << height << endl;
	cout << "원주율: " << PI << endl;
	cout << "학점: " << grade << endl;
	cout << "살아있음: " << isAlive << endl;
}