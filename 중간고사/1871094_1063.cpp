#include "iostream"
#include "string"
using namespace std;

pair<int,int> move(string str, pair<int, int> p) {
    pair<int, int> tmp = p;
    if (str == "R") {
        p.second++;
    } else if (str == "L") {
        p.second--;
    } else if (str == "B") {
        p.first--;
    } else if (str == "T") {
        p.first++;
    } else if (str == "RT") {
        p.first++;
        p.second++;
    } else if (str == "LT") {
        p.first++;
        p.second--;
    } else if (str == "RB") {
        p.first--;
        p.second++;
    } else if (str == "LB") {
        p.first--;
        p.second--;
    }
    if (p.first < 0 || p.first > 7 || p.second < 0 || p.second > 7) {
        return tmp;
    } else {
        return p;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    pair<int, int> king, rock;
    king.second = str[0] - 'A';
    king.first = str[1] - '1';
    cin >> str;
    rock.second = str[0] - 'A';
    rock.first = str[1] - '1';
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        pair<int, int> nking = move(str, king);
        if (nking.first == rock.first && nking.second == rock.second) {
            rock = move(str, rock);
            if (nking.first == rock.first && nking.second == rock.second) {
                nking = king;
            }
        }
        king = nking;
    }
    string ansk = "";
    string ansr = "";
    ansk += king.second + 'A';
    ansk += king.first + '1';
    ansr += rock.second + 'A';
    ansr += rock.first + '1';

    cout << ansk << '\n' << ansr;

    return 0;
}