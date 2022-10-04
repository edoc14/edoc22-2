#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int s[31]={0,1,3};

int sol(){
    int n;cin>>n;
    if(n==1)return 1;
    f(i,3,n)s[i]=s[i-1]+(s[i-2]<<1);
    return (s[n]+(n&1?s[n>>1]:s[(n>>1) + 1]))>>1;
    //s[i]가 가로가 i일때의 경우의 수. 홀수의 경우 가운데 타일 제외하고 좌우가 같은 타일들..
    //짝수의 경우에는 가운데 타일 제외하고 좌우가 같을때 + 사이에 아무타일 없는경우
    //홀수 : s[i/2] 짝수 : s[i/2+1]
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<sol();
    return 0;
}