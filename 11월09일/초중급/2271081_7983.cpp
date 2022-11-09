#include<stdio.h>
#include<stdlib.h>

typedef struct TASK{
	int s;
	int e;
}Task;
Task task[1000000];
int n, cnt=0; //task[][0]: 과제 최대한 미뤘을 때 시작일 [1]: 마감일 

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
	int d,t, p=0;
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%d%d",&d,&t); 
		task[i].s=t-d+1; task[i].e=t;
	}
	qsort(task,n,sizeof(Task),compare);
	
	for(int i=0; i<n; i++){
		printf("%d %d\n",task[i].s, task[i].e);
	}
	
	for(int i=1; i<n&&task[p].e>=task[i].s; i++){
		if(task[p].e<task[i].e){ //겹쳐있는 상태 
			cnt += task[i].s - task[p].e + 1;
			p=i;
		}
		else{ //큰 거에 포함되어 있는 상태 
			cnt += task[i].e - task[i].s + 1;
		}
	}
	
	printf("%d",task[0].s-cnt-1);
}
