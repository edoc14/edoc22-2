//
// Created by Hyegyo on 2022-10-05.
//
#include <iostream>
#include <vector>

using namespace std;

int countOutStudent(vector<int> choice) {
    int answer = 0;

    return answer;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;

        //입력
        cin >> n;
        vector<vector<int>> choice(n + 1, vector<int>(n+1,0) );
        for (int i = 1; i < n + 1; i++) { //인덱스 주의
            cin >> choice[i]; //2차원? 1차원? 고민해봐야
        }

        //연산
        cout << countOutStudent(choice) << '\n';
    }


    return 0;
}