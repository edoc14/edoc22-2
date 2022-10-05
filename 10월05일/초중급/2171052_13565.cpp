
#include <iostream>
using namespace std;
int arr[100][100];
int n,m;

void funct(int a, int b){
    
    if(a<0||a>=m||b<0||b>=m)return;
    if(arr[a][b]==1||arr[a][b]==2)return;
    arr[a][b]=2;
    funct(a-1,b);
    funct(a+1,b);
    funct(a,b-1);
    funct(a,b+1);
    return;
}

int main()
{

    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int k;
    for(k=0;k<n;k++){
        if(arr[0][k]==0){
             funct(0,k);
        }
    }

  
    int ans=0;
     for(int i=0;i<n;i++){
        if(arr[n-1][i]==2){
            ans=1; break;
        }
    }
    if(ans==0)cout<<"NO";
    else cout<<"YES";
    return 0;
}
