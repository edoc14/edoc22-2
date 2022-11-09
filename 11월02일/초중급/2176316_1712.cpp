#include <iostream>

using namespace std;

int main()
{
    int A, B, C, ans;
    cin >> A >> B >> C;
    
    if (B >= C)
        cout << "-1";
    else {
        ans = A / (C-B)+1;
        cout << ans;
    }
}
