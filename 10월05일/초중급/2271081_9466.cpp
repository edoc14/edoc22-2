#include<stdio.h>
int flag, select[100001], visit[100001], s, cnt=0; //visit: 1:visiting, -1: visited but team X, -2: visited&team O

void find(int p){
	visit[p]=1; //1: 현재 방문 중
	if(visit[select[p]]<0) flag = -1; //팀 구성 실패 
	else if(visit[select[p]]==1){
		 flag=-2; // 팀 구성 성공
		 s = select[p]; //시작점이 어딘지 s에 
	}
	else find(select[p]);
	
	visit[p] = flag;
	if(flag==-1) cnt++;
	else if(p==s) flag=-1; //팀을 구성(flag==-2) && 표시완료=> 이 전은 다 팀 구성 
}
int main(){
	int t, n, i, j;
	
	scanf("%d",&t);
	
	while(t>0){
		scanf("%d",&n);
		for(i=1; i<=n; i++){ 
			scanf("%d",&select[i]);
			if(i==select[i]) visit[i]=-2; //자신이 지목하면 바로 팀 
		}
		for(i=1; i<=n; i++){
			if(visit[i]==0){
				find(i); 
			}
		}
		printf("%d\n",cnt);
		for(j=0; j<=n; j++) visit[j]=0;//초기화 
		cnt=0;
		t--;
	}
	
	return 0;
}
