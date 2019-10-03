#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501] ={{0}};
const int mod = 1E9 + 7;
int main() {
    dp[0][0] = 1;
    for(int i = 0 ; i <= 500; i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    // we can move only right and down, so dp[i][0] and dp[0][i] for all i will be 1
    for(int i = 1; i <= 500; i++){
        for(int j = 1; j <=500; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << dp[n][m]  << endl;

    }
    return 0;
}
