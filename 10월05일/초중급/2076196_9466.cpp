#include <iostream>
#include <cstring>
using namespace std;

int A[1010][1010];
bool visited[1010][1010];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool answer = false;
int M,N;
int adj[100010];
void print(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}
bool dfs(int x, int nc){
  if(visited[x]) return nc;
  dfs(adj[x], nc+1);
  return 0;
}

int main(){
    int T;
    cin>>T;
    while(T--){
    memset(visited,0,sizeof(visited));
    cin>>N;
    int ans = N;
    for(int i = 0 ; i < N; i++){
        int a;
        cin>>a;
        adj[i+1] = a;
    }
    for(int i = 1; i <= N; i++){
        ans -= dfs(i,0);
    }
    }
}
