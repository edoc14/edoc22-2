#include<stdio.h>
#include<list>

int main() {
	static char key[1000000];
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) { // Test case 만큼 반복
		scanf(" %s", key);
		std::list<char> password;
		std::list<char>::iterator p = password.begin(); // list크기가 0이므로 begin()==end(), p에insert하면 p의 앞에 저장된다
		for (int i = 0; key[i] != 0; i++) {
			switch (key[i]) {
			case '-':
				if (p != password.begin()) {
					p--; // p는 기본적으로 end 위치에 있으므로 -1하여 마지막 원소를 가르키게 만들어줘야 한다
					p = password.erase(p); // 지운 원소의 다음위치(기본적으론 end위치) 반환
				}
				break;
			case '<':
				if (p != password.begin()) p--; // p가 begin에 있지 않다면 -1
				break;
			case '>':
				if (p != password.end()) p++; // p가 end에 있지 않다면 +1
				break;
			default:
				password.insert(p, key[i]); // 문자 삽입
			}
		}
		while (!password.empty()) {
			printf("%c", password.front()); // 출력
			password.pop_front();
		}
        puts("");
	}
	return 0;
}
