#include <iostream>
using namespace std;

char c;
int M, N;
int map[1001][1001];
bool ans;

void bfs(int y, int x){
	map[y][x] = 1; 
    
	if (y == M){
		ans = true;
		return;
	}

	if (y >= 2 && map[y - 1][x] == 0)
		bfs(y - 1, x); 

	if (map[y + 1][x] == 0)
		bfs(y + 1, x); 

	if(x >= 2 && map[y][x - 1] == 0)
		bfs(y, x - 1); 

	if (map[y][x + 1] == 0 && x <= N - 1)
		bfs(y, x + 1); 
}

int main() 
{
	cin >> M >> N;
	
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++){
			cin >> c;
			map[i][j] = c - '0';
		}

	for (int i = 1; i <= N; i++){
		if (map[1][i] == 0){
			bfs(1, i);
		}
	}
    
	cout << (ans ? "YES" : "NO");
}