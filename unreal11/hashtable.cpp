//#include <iostream>
//#include <stdio.h>
//#include <vector>
//
//using namespace std;
//using uint = unsigned int;
//
//class hash_map {
//
//	// 자동할당 배열 선언
//	vector<int> data;
//
//	// 초기화
//public:
//
//	hash_map(size_t n) {
//		// 배열을 빈것으로 초기화
//		data = vector<int>(n, -1);
//	}
//
//	/*
//	값 삽입
//	*/
//	void insert(uint value) {
//		int n = data.size();
//		data[value % n] = value;
//		cout << value << " 삽입완료" << endl;
//	}
//
//	/*
//	값 찾기
//	*/
//	bool find(uint value) {
//		int n = data.size();
//		return(data[value % n] == value);
//	}
//
//	/*
//	값 지우기
//	*/
//	void erase(uint value) {
//		int n = data.size();
//		data[value % n] = -1;
//		cout << value << " 삭제완료" << endl;
//	}
//};
//
//int main() {
//
//	hash_map map(7); // 배열 data = {n,n,n,n,n,n,n}
//	auto print = [&](int value) {
//		if (map.find(value)) {
//			cout << value << " 이/가 존재함" << endl;
//		}
//		else {
//			cout << value << " 이/가 존재하지 않음" << endl;
//		}
//	};
//
//	map.insert(17); // 17을 넣어서 idx 7에 값 삽입 
//	map.insert(20); // 20을 넣어서 idx 6에 값 삽입 
//	map.insert(11); // 11을 넣어서 idx 4에 값 삽입
//
//	print(7); // 7존재여부 출력
//	print(17);
//	print(20);
//	print(11);
//
//	map.insert(2);
//	print(2);
//	map.erase(2); // idx 7에 값을 삭제
//	print(2);
//
//	return 0;
//}

/*
17 삽입완료
20 삽입완료
11 삽입완료
7 이/가 존재하지 않음
17 이/가 존재함
20 이/가 존재함
11 이/가 존재함
2 삽입완료
2 이/가 존재함
2 삭제완료
2 이/가 존재하지 않음
*/