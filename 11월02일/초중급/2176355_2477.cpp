#include <iostream>
#include <vector>

using namespace std;



int main(){
    int k;
    cin >> k;

    vector<vector<int>> len(6, vector<int>(2, 0));
    for(int i=0 ; i<6 ; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        len[x].push_back(y);
    }
    
    return 0;
}