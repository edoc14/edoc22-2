#include<stdio.h>

int main(){
	int n, flag[10]={0,}, a;
	long long int k, kn;

	while(scanf("%d",&n)!=EOF){
		k=0;
		while(a==0){
			k++;
			kn=k*n; 
			while(kn!=0){ 
				flag[kn%10]=1;
				kn/=10;
			}
			a=1;
		
			for(int i=0; i<10; i++){
				if(flag[i]!=1){
					a=0;
					break;
				}
			}
		}
		
		printf("%lld\n",k);
		a=0;
		for(int i=0; i<10; i++){//flag 초기화 
			flag[i]=0;
		}
	
	}
	return 0;
}
