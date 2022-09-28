#include<stdio.h>
#include<deque>
using namespace std;

deque<int> left,right; //커서 기준으로 왼쪽 오른쪽
int main(){
	int t;
	char c; 

	scanf("%d ",&t);
	for(int i=0; i<t; i++)
	{
		do
		{
			scanf("%c",&c);
			if(c=='\n') break; //한 번 테스트 완료됐을 때 
			if(c=='<')	//왼쪽 이동 
			{
				if(!left.empty())	//커서가 왼쪽 끝에 있을 때 제외 
				{
					right.push_front(left.back()); //asdf | g  ->> asd | fg
					left.pop_back();	
				}
			}
			else if(c=='>') 
			{
				if(!right.empty())
				{
					left.push_back(right.front()); //asdf | g ->> asdfg|
					right.pop_front();	
				}
				
			}
			else if(c=='-')
			{
				if(!left.empty())
				{
					left.pop_back();	//asdfg| ->> asdf| 				
				}
			}
			else //새로 입력받는 경우, 위에서 c=='\n'일 경우는 빼줬으니 그냥 else 
			{
				left.push_back(c);	 
			}
		}while(c!='\n');
		
		while(!left.empty())
		{
			printf("%c",left.front());
		 	left.pop_front();
		}
		while(!right.empty())
		{
			printf("%c",right.front());
			right.pop_front();
		}
		printf("\n");
	}
	
	
	return 0;
}
