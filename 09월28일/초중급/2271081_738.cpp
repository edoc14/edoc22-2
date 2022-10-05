#include<stdio.h>
#include<stdlib.h>

typedef struct ST{
	int s;
	int t;
}ST;

int compare(const void *a, const void *b){
	ST x = *(ST *)a;
	ST y = *(ST *)b;
	
	if(x.s > y.s) return 1;
	if(x.s < y.s) return -1;
	
	if(x.t > y.t) return 1;
	if(x.t < y.t) return -1;
	
	return 0; 
}
int main(){
	ST st[200]; 
	int t, n, time=0, x, y, visit[200]={0,},tmp, last;
	
	scanf("%d",&t);
	for(int k=0; k<t; k++)
	{
		scanf("%d",&n);
	
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&x, &y);
			if(x>y){ //���� �� ū �� ������ �� �� 
				tmp=x;
				x=y;
				y=tmp;
			}
			st[i].s = (x+1)/2; //�� ��ȣ�� �ƴ� ���� ��ȣ�� 
			st[i].t = (y+1)/2;
		}
	
		qsort(st,n,sizeof(ST),compare);

		for(int i=0; i<n; i++)
		{
			if(!visit[i])
			{
				visit[i]=1;
				last=st[i].t;
				for(int j=i+1; j<n; j++)
				{
					if(last<st[j].s&&!visit[j])
					{
						last=st[j].t;
						visit[j]=1; //��� ���� ���� ǥ ��  
					}
				}
				time++;
			}
		} 
		
		printf("%d\n",time*10);
		time=0;	//�ʱ� ȭ  
		for(int i=0; i<n; i++) visit[i] = 0;
	}
	return 0;
}
