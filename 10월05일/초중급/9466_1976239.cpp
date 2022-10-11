#include <iostream>
#include <vector>
#include <stack>
#include <memory.h> //������ memset()�̿�� �̰� import�ؾ���.
using namespace std;

int T, n;
const int MAX = 100001;

typedef struct node {
	int num;
	node* next;
} node;

node graph[MAX];
int visited[MAX]; //-1:���� ���� �ȵ� 0:������ 1:������ 
int teamFail[MAX]; //0:�湮 �ȵ� 1:�湮��
stack<int> s; //�׷��� Ž�� ���� ����
int* result;


int* dfs(node current) {
	visited[current.num] = 1;

	//������ �л� ��� Ž��
	if (teamFail[current.next->num] >= 0) { //������ �л��� �̹� �� ���ΰ� ������ ���¸� �ڵ����� team fail
		teamFail[current.num] = 1;
		while (!s.empty()) { //current ��� �� current�� ����� stack�� ���� ��� team fail
			teamFail[s.top()] = 1;
			s.pop();
		}
		return teamFail;
	}

	s.push(current.num); //current ��� ���ÿ� push.
	if (visited[current.next->num]) { //current�� ������ �л��� �̹� Ž���� ���, ����Ŭ ���� ���� Ȯ��
		int root = current.next->num; //���� ��带 root�� ����, stack���� ���� ���� node�� ������ root�� �����Ƿ� ����Ŭ ����, �� �� ����
		vector<int> temp; //���ÿ��� ���� ������ ������ ����

		while (!s.empty()) {
			int pop = s.top(); s.pop(); 
			temp.push_back(pop); //���ÿ��� ��� ���� ������ temp ���Ϳ� ����
			
			//����Ŭ ����, �� �� ���� ��
			if (pop == root) {
				for (int i : temp) {
					teamFail[i] = 0;
				}
				//���ÿ� ���� �л��� ��� �� ����
				while (!s.empty()) {
					teamFail[s.top()] = 1;
					s.pop();
				}
				return teamFail;
			}
			
			//����Ŭ ���� ����
			if (s.empty()) { //������ �� ������ root�� ���� ���� ��尡 ������ temp�� ����� ���� ��� team fail.
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
		//�׷��� �׸���
		for (int i = 1; i <= n; i++) {
			int s; cin >> s;
			graph[i].num = i;
			graph[i].next = &graph[s];
		}

		//���� �迭 �ʱ�ȭ
		memset(visited, 0, sizeof(visited));
		memset(teamFail, -1, sizeof(teamFail));
		
		//Ž�� ����
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
