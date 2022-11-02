#include <iostream>
#include <vector>
using namespace std;

typedef struct edge {
	int direction; //1:동 2:서 3:남 4:북
	int length; // 1 <= length <= 500
	edge* front;
	edge* back;
} edge; //주어지는 육각형의 각 변을 double linked list인 edge로 구현하여, 육각형을 edge들의 cycle로 구현한다. 
		//front와 back은 이어진 양 변을 가리킨다.

edge edges[7]; //edges[1]~[6]은 육각형의 각 변을 저장한다.

int K; //1m^2당 참외 개수 (1 <= K <= 20)
int area; //총 면적

int main() {
	cin >> K;
	for (int i = 1; i <= 6; i++) {
		cin >> edges[i].direction >> edges[i].length;
	}

	//입력된 순서에 따라 각 변의 front와 back을 저장한다.
	for (int i = 1; i <= 6; i++) {
		if (i == 1) { //edges[1]의 front는 edges[6]을 가리킨다.
			edges[i].front = &edges[6]; 
			edges[i].back = &edges[i + 1];
		}
		else if (i == 6) {//edges[6]의 back은 edges[1]을 가리킨다.
			edges[i].front = &edges[i-1];
			edges[i].back = &edges[1];
		}

		else { //나머지 변들의 front는 바로 앞, back은 바로 뒷순서의 edge이다.
			edges[i].front = &edges[i - 1];
			edges[i].back = &edges[i + 1];
		}
	}

	//ㄱ자 모양의 육각형에서는 꺾이는 변의 쌍이 무조건 두 번 연달아서 나타난다.
		//ex. 예제입력1의 경우 4 2 3 1 3 1 -> 3 1 이 연속해서 두 번 나타남.
		//ex2.				 3 1 4 2 3 1 -> 육각형이 double linked list로 구현된 cycle이기 때문에 역시 동일하게 3 1이 연속해서 두 번 나타난다고 볼 수 있다. 
	//같은 방향의 변끼리 길이를 더하면 각각 육각형을 감싸는 전체 사각형의 가로 및 세로 길이가 된다.
	//그리고 제외되는 사각형의 경우
	//edges[i]의 front변과 back변이 방향이 같고, edges[i]변과 edges[i]->back->back변의 방향이 같다면, edges[i]와 edges[i].back은 제외되는 사각형의 두 변이 된다. 
		//ex. 4 2 3 1 3 1 를 4 2 3a 1a 3b 1b 로 나타낼 때, 제외되는 사각형의 면적은 (1a변의 길이) x (3b변의 길이)이다.

	int x, y; //전체 사각형의 두 변 길이
	int z, w; //제외되는 사각형의 두 변 길이
		   	  //즉 육각형의 면적은 x*y - z*w

	for (int i = 1; i <= 6; i++) { //제외되는 사각형의 변이 되는 조건을 만족하는 edges[i] 탐색
		if (edges[i].direction == edges[i].back->back->direction && edges[i].front->direction == edges[i].back->direction) {
			x = edges[i].length + edges[i].back->back->length;
			y = edges[i].front->length + edges[i].back->length;

			z = edges[i].length;
			w = edges[i].back->length;
			
			area = x * y - z * w;
			break;
		}
	}

	int result = K * area; //밭에서 자라는 참외의 총 개수 (출력할 정답)

	cout << result;
	return 0;
}