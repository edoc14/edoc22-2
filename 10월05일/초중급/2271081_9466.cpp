#include<stdio.h>
int flag, select[100001], visited[100001], cnt=0;

void find(int f, int p){
	printf("[%d] %d\n",f,p);
	if(select[p]<0){
		flag=-2; //-2는 팀 결성 무산됨 
		printf("flag :%d\n",flag);
		return;
	}
	else if(select[p]==f){
		flag=-1; //-1은 팀이 이미 정해진 것 
		printf("flag :%d\n",flag);
	} 
	else find(f,select[p]);

	select[p]=flag;
	printf("select[%d]= %d\n",p,flag);
	if(flag==-2){
		cnt++;
		printf("cnt: %d\n",cnt);	
	} 
	
}
int main(){
	int t, n, i;
	
	scanf("%d",&t);
	
	while(t>0){
		scanf("%d",&n);
		for(i=1; i<=n; i++){ 
			scanf("%d",&select[i]);
			if(i==select[i]) select[i]=-1; //자신이 지목하면 바로 팀 
		}
		for(i=1; i<=n; i++){
			if(select[i]>0){ //정해진 게 없으면 
				find(i,i);
			}
		}
		printf("%d\n",cnt);
		cnt=0;
		t--;
	}
	
	return 0;
}
