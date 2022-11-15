#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
string order[8] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
int moveTo[8][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int main() {
    char king[2], stone[2];
    cin >> king[0] >> king[1] >> stone[0] >> stone[1];
    int n; cin >> n;
    while(n--) {
        string move; cin >> move;
        int i;
        for (i = 0; i < 8; i++) {
            if(order[i] == move) break;
        }
        
        int x_king = king[0] + moveTo[i][0];
        int y_king = king[1] + moveTo[i][1];

        if (x_king < 'A' || x_king > 'H' || y_king < '1' || y_king > '8')
        {
            cout << "king out of range\n";
            continue;
        }
        if (x_king == stone[0] && y_king == stone[1])
        {
            int x_stone = stone[0] + moveTo[i][0];
            int y_stone = stone[1] + moveTo[i][1];
            if (x_stone < 'A' || x_stone > 'H' || y_stone < '1' || y_stone > '8'){
                cout << "king out of range\n";
                continue;
            }
            stone[0] = x_stone;
            stone[1] = y_stone;
        }
        king[0] = x_king;
        king[1] = y_king;
    }
    cout << king[0] << king[1] << '\n'
         << stone[0] << stone[1];
    return 0;
}