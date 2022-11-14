#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> num;
int main() {
    cin>>N;

    //내림차순인 숫자를 구하는 것은
    //0~9까지의 수에서 p개의 숫자를 뽑는 것과 같다. (나열은 무조건 내림차순이 될테니까)
    //따라서 총 경우의 수는 2^10-1개 이다. 즉 1023부터는 감소하는 수가 없다.
    if(N>=1023){
        cout<<-1;
        return 0;
    }else if(N<10){
        cout<<N;
        return 0;
    }

    //감소하는 수 구하기
    //1자리
    for (int i = 0; i < 10; ++i) {
        num.push_back(i);
    }

    //num[start]~num[end-1]는 이전 자릿수의 감소하는 수
    int start=0;
    int end=num.size();

    while (end<=N){
        for (int i = start; i < end; ++i) {
            int last=num[i]%10; //일의 자리 수

            //새로운 감소하는 수: 일의자리수보다 작은 수를 뒤에 붙인 수
            for (int j = 0; j < last; ++j) {
                num.push_back(num[i]*10+j);
            }
        }
        start=end;
        end=num.size();
    }

    cout<<num[N];

    return 0;
}
