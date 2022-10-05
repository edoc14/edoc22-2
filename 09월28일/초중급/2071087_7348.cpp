#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main(){
    int t,n,start, end;
    cin>>t;
    for (int i = 0; i < t; i++) {
        vector<int> x(200,0);
        cin>>n;
        for (int j = 0; j < n; j++) {
            cin >> start >> end;
            int tmp;
            if (start > end) { //역방향인 경우 시작점과 끝점 바꿔줌
                tmp = end;
                end = start;
                start = tmp;
            }
            start = (start - 1) / 2;
            end = (end - 1) / 2;
            for (int k = start; k <= end; k++) {
                x[k] += 10;
            }
        }
        int answer = 0;
        for (int j = 0; j < 200; j++) {
            answer = max(answer, x[j]);
        }
        cout << answer << '\n';
    }
    return 0;
}
