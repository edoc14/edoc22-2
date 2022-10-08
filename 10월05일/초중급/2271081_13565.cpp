#include<stdio.h> 
int map[1000][1000],m,n, flag=0; //flag: ħ�� ���� 
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};//WSEN

void dfs(int x, int y){
	int i;
	if(x==m-1){  //���� �����ϸ� 
		flag=1;  //�����ߴٰ� ǥ�� 
		return;
	}
	map[x][y]=1; //�湮 ǥ��

	for(i=0; i<4; i++){
		int px=x+dx[i];	//������ �� ��ġ 
		int py=y+dy[i];
		
		if(map[px][py]==0&&px>=0&&px<m&&py>=0&&py<n){ //���� ��&�̹湮�̸� 
			dfs(px,py);
		}
	}
	
}
int main(){
	int i,j;
	
	scanf("%d%d",&m,&n);
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%1d",&map[i][j]); //������� �Է¹����ϱ� 1d 
		}
	}

	for(j=0; j<n; j++){
		if(map[0][j]==0){ //������ ���ϴ� ���̰ų� �湮���� �ʾҴ� �� 
			dfs(0,j);	  // ��->���̹Ƿ� 0��° �ٸ� ���� ��
			map[0][j]=1;  //�������� �ڿ��� �湮ǥ�� 
		}
	}
	
	
	if(flag==1) printf("YES");
	else printf("NO");
	return 0;
}
