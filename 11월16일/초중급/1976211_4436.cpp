#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main() {
    char *str;
    int N;
    cin.getline(str,10);
    while(strcmp(str,""))
    {
        N=stoi(str);
        int k;
        //k의 최대 값은 10
        for (k = 1; k < 11; ++k) {
            vector<bool> digit(10,false); int cnt=0;
            for (int i = 1; i <= k; ++i) {
                int num=i*N;
                while(num){
                    if(digit[num%10]){
                        num/=10;
                        continue;
                    }
                    digit[num%10]= true;
                    cnt++;
                    num/=10;
                }
            }
            if(cnt==10) break;
        }
        cout << k<<'\n';
        cin.getline(str,10);

    }
    return 0;
}
