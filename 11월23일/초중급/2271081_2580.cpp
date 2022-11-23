
#include<stdio.h>
int map[9][9];
int ans[9][9], square[9][9], flag=0;
/*
void sdk(int x, int y, int a){
	for(int i=0; i<9; i++){ //vertical check
		if(ans[i][y]==a) 
	}
	for(int j=0; j<9; j++){ //horizonal check
		if(ans[x][j]==a)
	}
	for(int i=1; i<3; i++){ //square check..?
		for(int j=1; j<3; j++){
			if(ans[x+i][y+j]==a)
		}
	}
}*/
int main(){
	int s=-1, k=0; //square[s][k], s: section number, k: numbers in the section
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d",&map[i][j]);
			ans[i][j]=map[i][j];

			if(j%3==0){
				s++;
				if(j!=0) k-=3;
			}
			printf("\t(%d,%d)\n",s,k);
			square[s][k++]=map[i][j];
		}

		if((i+1)%3!=0||i==0){
			s-=3;
		}
		if(k>8) k=0;
	}
	
	for(int i=0; i<9; i++){
		printf("[%d]: ", i);
		for(int j=0; j<9; j++){
			printf("%d ",square[i][j]);
		}printf("\n");
	}
	/*
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(!map[i][j]){ //해당 값이 0이면 == 빈칸이면 
				sdk(i,j,1); //1부터 넣어보기 
			}
		}
	}
	*/
	
	return 0;
}
