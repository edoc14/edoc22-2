#include<stdio.h> 
int map[1000][1000],m,n, flag=0; //flag: 침투 여부 
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};//WSEN

void dfs(int x, int y){
	int i;
	if(x==m-1){  //끝에 도달하면 
		flag=1;  //도달했다고 표시 
		return;
	}
	map[x][y]=1; //방문 표시

	for(i=0; i<4; i++){
		int px=x+dx[i];	//다음에 갈 위치 
		int py=y+dy[i];
		
		if(map[px][py]==0&&px>=0&&px<m&&py>=0&&py<n){ //범위 내&미방문이면 
			dfs(px,py);
		}
	}
	
}
int main(){
	int i,j;
	
	scanf("%d%d",&m,&n);
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%1d",&map[i][j]); //공백없이 입력받으니까 1d 
		}
	}

	for(j=0; j<n; j++){
		if(map[0][j]==0){ //전류가 통하는 곳이거나 방문하지 않았던 곳 
			dfs(0,j);	  // 밖->안이므로 0번째 줄만 보면 됨
			map[0][j]=1;  //빠져나온 뒤에는 방문표시 
		}
	}
	
	
	if(flag==1) printf("YES");
	else printf("NO");
	return 0;
}
