#include <iostream>
#include <vector>
using namespace std;

int k;
pair<int, int> line[6];
int width=1;
int result=0;

void Input(){
    cin>>k;
    for(int i=0; i<6; i++){
        cin>>line[i].first>>line[i].second;
    }
}

int Solution(){
    for (int i=0; i<6; i++){
        int cur=line[i].second*line[(i+1)%6].second;
        if(width==1||cur>width){
            width=cur;
            result=(width - line[(i+3)%6].second * line[(i+4)%6].second) * k;
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Input();
    cout<<Solution()<<endl;
    return 0;
}
