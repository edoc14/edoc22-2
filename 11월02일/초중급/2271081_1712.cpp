#include<stdio.h>

int main(){
	int fix, c, i, d;
	
	scanf("%d%d%d",&fix,&c,&i);
	d = i-c;
	if(d<=0) printf("-1");
	else printf("%d",fix/d+1);
	
	return 0;
}
