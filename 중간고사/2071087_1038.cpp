#include <iostream>
#include <queue>
#define MAX 10000010
using namespace std;

int N;
long long DP[MAX];

void Solution(){
    queue<long long> Q;
    for (int i = 1; i <= 9; i++){
        Q.push(i);
        DP[i] = i;
    }

    if (0 <= N && N <= 10){
        cout << N << "\n";
        return;
    }

    int Idx = 10;
    while (Idx <= N && Q.empty() == false){
        long long Number = Q.front();
        Q.pop();

        int Last = Number % 10;
        for (int i = 0; i < Last; i++){
            Q.push(Number * 10 + i);
            DP[Idx++] = Number * 10 + i;
        }
    }

    if (Idx >= N && DP[N] != 0) cout << DP[N] << "\n";
    else cout << -1 << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    Solution();

    return 0;
}
