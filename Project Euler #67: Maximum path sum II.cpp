#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Same as problem 18. Same solution implemented. The only difference is test case constraints. Problem 18 can be solved using plain recursion also but this one definitly requires DP.


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int dp[n][100];
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                cin >> dp[i][j];
            }
        }

   // pick the max sum from left sub tree and right sub tree
   // and store it in dp. build it up bottom up and dp[0][0] contains 
   // the max sum

   for(int i = n - 2; i >= 0; i--){
       for(int j = 0; j <= i; j++){
          // dp[i][j] contains current element
          dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
       }
   }

   cout << dp[0][0] << endl;
 }
}
