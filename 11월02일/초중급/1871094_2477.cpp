#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    cin >> K;
    vector<int> vec;
    int horizMaxLen = 0;
    int horizMaxIdx = 0;
    int horizMaxDir = 0;
    int vertiMaxLen = 0;
    int vertiMaxIdx = 0;
    int veritMaxDir = 0;
    for (int i = 0; i < 6; i++) {
        int dir, len;
        cin >> dir >> len;
        vec.push_back(len);
        if (dir == 1 || dir == 2) { // horiz
            if (len > horizMaxLen) {
                horizMaxLen = len;
                horizMaxIdx = i;
                horizMaxDir = dir;
            }
        } else { // verti
            if (len > vertiMaxLen) {
                vertiMaxLen = len;
                vertiMaxIdx = i;
                veritMaxDir = dir;
            }
        }
    }
    int size = horizMaxLen * vertiMaxLen;
    if (horizMaxDir + veritMaxDir == 5) {
        int horiz = vec[(horizMaxIdx + 4) % 6];
        int verti = vec[(vertiMaxIdx + 2) % 6];
        size -= horiz * verti;
    } else {
        int horiz = vec[(horizMaxIdx + 2) % 6];
        int verti = vec[(vertiMaxIdx + 4) % 6];
        size -= horiz * verti;
    }
    cout << size * K;
    return 0;
}