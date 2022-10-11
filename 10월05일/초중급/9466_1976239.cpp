#include <iostream>
#include <vector>
#include <stack>
#include <memory.h> //백준은 memset()이용시 이거 import해야함.
using namespace std;

int T, n;
const int MAX = 100001;

typedef struct node {
	int num;
	node* next;
} node;

node graph[MAX];
int visited[MAX]; //-1:아직 결정 안됨 0:팀성공 1:팀실패 
int teamFail[MAX]; //0:방문 안됨 1:방문됨
stack<int> s; //그래프 탐색 과정 스택
int* result;


int* dfs(node current) {
	visited[current.num] = 1;

	//선택한 학생 노드 탐색
	if (teamFail[current.next->num] >= 0) { //선택한 학생이 이미 팀 여부가 결정난 상태면 자동으로 team fail
		teamFail[current.num] = 1;
		while (!s.empty()) { //current 노드 및 current와 연결된 stack의 노드들 모두 team fail
			teamFail[s.top()] = 1;
			s.pop();
		}
		return teamFail;
	}

	s.push(current.num); //current 노드 스택에 push.
	if (visited[current.next->num]) { //current가 선택한 학생이 이미 탐색된 경우, 사이클 형성 여부 확인
		int root = current.next->num; //현재 노드를 root로 지정, stack에서 같은 값의 node가 나오면 root가 같으므로 사이클 형성, 즉 팀 성공
		vector<int> temp; //스택에서 꺼낸 노드들을 저장할 벡터

		while (!s.empty()) {
			int pop = s.top(); s.pop(); 
			temp.push_back(pop); //스택에서 노드 꺼낼 때마다 temp 벡터에 저장
			
			//사이클 형성, 즉 팀 성공 시
			if (pop == root) {
				for (int i : temp) {
					teamFail[i] = 0;
				}
				//스택에 남은 학생은 모두 팀 실패
				while (!s.empty()) {
					teamFail[s.top()] = 1;
					s.pop();
				}
				return teamFail;
			}
			
			//사이클 형성 실패
			if (s.empty()) { //스택이 빌 때까지 root와 같은 값의 노드가 없으면 temp에 저장된 노드들 모두 team fail.
				for (int i : temp) { 
					teamFail[i] = 1;
				}
				return teamFail;
			}
		}
	}
	
		return dfs(*current.next);
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		//그래프 그리기
		for (int i = 1; i <= n; i++) {
			int s; cin >> s;
			graph[i].num = i;
			graph[i].next = &graph[s];
		}

		//전역 배열 초기화
		memset(visited, 0, sizeof(visited));
		memset(teamFail, -1, sizeof(teamFail));
		
		//탐색 시작
		result = dfs(graph[1]);
		for (int i = 2; i <= n;i++) {
			if (result[i] == -1) {
				result = dfs(graph[i]);
			}
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (result[i] == 1) {
				ans++;
			}
		}
		
		cout << ans << endl;
		memset(graph, 0, sizeof(graph));
	}

	return 0;
}
