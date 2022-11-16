#include<stdio.h>
#include<stdlib.h>

typedef struct TASK{
	long long int s;
	long long int e;
}Task;
Task task[1000000];
//task[][0]: 과제 최대한 미뤘을 때 시작일 [1]: 마감일 

int compare(const void *a, const void *b){
	Task x=*(Task *)a;
	Task y=*(Task *)b;
	
	if(x.s>y.s) return 1;
	if(x.s<y.s) return -1;
	
	if(x.e>y.e) return 1;
	if(x.e<y.e) return -1;
	
	return 0;
}
int main(){
	int d,t, p=0, n;
	long long int cnt=0; 
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%d%d",&d,&t); 
		task[i].s=t-d+1; task[i].e=t; //최대한 미룬 과제 시작일과 마감일로 저장(다른 과제 고려X) 
	}
	qsort(task,n,sizeof(Task),compare);
	
	printf("\n");
	for(int i=0; i<n; i++){
		printf("%lld %lld\n",task[i].s, task[i].e);
	}printf("\n");
	
	for(int i=1; i<n&&task[p].e>=task[i].s-1; i++){ //동떨어져 있는 경우 제외, p는 기준 
		if(task[p].e<task[i].e){ //겹쳐있는 상태 
			cnt += task[p].e - task[i].s + 1; 
			p=i;
		}
		else{ //큰 거에 포함되어 있는 상태 
			cnt += task[i].e - task[i].s + 1;
		}
		printf("p: %d i: %d cnt: %lld\n",p,i,cnt);
	}
	
	printf("%lld",task[0].s-cnt-1);
}
