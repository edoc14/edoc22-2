//
// Created by Hyegyo on 2022-10-05.
//
#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> figure;
vector<vector<bool>> visited(m+1, vector<bool>(n+1, 0));
int dy[4] = {0,1,0,-1};
int dx[4] = {-1, 0, 1, 0};


void dfs( int x, int y){
    visited[x][y]=true;

    for(int i=0 ; i<4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0<= nx && nx < n && 0<=ny && ny < n){
            if(figure[nx][ny == 1 && visited[nx][ny]] == false){
                dfs(nx, ny);
            }
        }
    }

}

bool solution(){
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(figure[i][j]==0 && visited[i][j]== false){

                dfs(i,j);
            }
        }
    }

        for(int j=0 ; j<n ; j++){
            if(visited[m-1][j]==true){
                return true;
            }
        }


    return false;
}

int main(){
    //int m,n;

    //입력
    cin >> m >> n;
    figure.assign(m,vector<int>(n , 0));
    for(int i=0 ; i<m ; i++){
        for(int j=0; j<n ; j++)
            cin >> figure[i][j];
    }

    //연산, 출력
    if (solution()) {
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}