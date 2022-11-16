#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> tc;
int main(){
	int TN, dp, tp, dc, t, sum; //sum: 칼로리 합 
	double best, price; //best: 1원 당 열량 price: 가격 합 
	
	scanf("%d",&TN); //토핑 종류 개수 
	scanf("%d%d",&dp,&tp); //도우 가격, 토핑 가격 
	scanf("%d",&dc); //도우 열량 
	
	for(int i=0; i<TN; i++){
		scanf("%d",&t); //토핑 열량 
		tc.push(t); //우선순위 큐->내림차순 정렬 
	}
//내림차순 -> 큐의 위에 있을수록 가성비 좋음 -> 위쪽이 안 되면 아래도 다 X 
	sum=dc;
	best=sum/dp; //도우만 올리는 경우 
	for(int i=0; i<TN; i++){
		sum += tc.top(); 
		tc.pop();
		price = dp+tp*(i+1);
		if(best<sum/price) best = sum/price;
	}
	
	printf("%d",(int)best);
	return 0;
}
