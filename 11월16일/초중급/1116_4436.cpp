#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    vector<int> num(10,1);
    int k=1;
    long long arr=0;
    while(true){
        arr += n;
        long long temp = arr;
        while(temp != 0){
            long long temp2 = arr%10;
            if(num[temp2]==1) num.erase(num.begin()+temp2);
            temp /= 10;
        }
        if(num.empty()) break;
        k++;
    }
    return k;
}

int main(){

    while(true){
        int n;
        cin >> n;
        if (cin.eof()) break;
        cout << solution(n)<<'\n';
    }

    return 0;
}