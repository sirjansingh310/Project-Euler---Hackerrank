#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long sumOfSquares = (n * (n + 1) *(2 * n + 1)) / 6;
        long long sum = n * (n + 1) / 2;
        cout << ((sum * sum) - sumOfSquares) << endl;
    }
    return 0;
}
