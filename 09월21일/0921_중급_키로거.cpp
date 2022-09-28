#include<stdio.h>
#include<deque>
using namespace std;

deque<int> left,right; //Ŀ�� �������� ���� ������
int main(){
	int t;
	char c; 

	scanf("%d ",&t);
	for(int i=0; i<t; i++)
	{
		do
		{
			scanf("%c",&c);
			if(c=='\n') break; //�� �� �׽�Ʈ �Ϸ���� �� 
			if(c=='<')	//���� �̵� 
			{
				if(!left.empty())	//Ŀ���� ���� ���� ���� �� ���� 
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
			else //���� �Է¹޴� ���, ������ c=='\n'�� ���� �������� �׳� else 
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
