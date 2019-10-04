#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int maxSum = -1;
// void findSum(int currentSum, int i, int j){
//     if(n == i)
//         return;
//     int  leftJ, rightJ;
//     leftJ = j;
//     rightJ = j + 1;
//     int leftSum = currentSum, rightSum = currentSum;
//     leftSum  +=  arr[i + 1][leftJ];
//     rightSum +=  arr[i + 1][rightJ];

//     maxSum = max(maxSum,max( leftSum, rightSum));
//     findSum(leftSum, i + 1, leftJ );
//     findSum(rightSum, i + 1, rightJ);
// }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int dp[n][15];
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
