#include <iostream>

using namespace std;

int main()
{

    int n;
    int res = 0;
    int dp[1001][10] = {0}; //define arrya, dp

    cin >> n;
    for (int i = 0; i < 10; i++) //put initialized value into dp array
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++) { //beside dp that the initial value is 1, put value of dp by algorithm
        for (int j = 0; j < 10; j++) {
            if (j == 0) {  //in dp[i][j], if j is 0, all of the value of dp is 1
                dp[i][0] = 1;
                continue;
            }

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]); //rule to fill dp arrays
            dp[i][j] %= 10007;
        }
    }

    
    for (int i = 0; i < 10; i++)
        res = (res + dp[n][i]);  //update result by adding dp

    cout << res % 10007; //print result by dividing into 10007(a remainder is the result)
    return 0;
}