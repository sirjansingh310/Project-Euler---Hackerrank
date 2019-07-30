#include<bits/stdc++.h>
using namespace std;

// a + b + c = n
// n is known, a can vary from 1 to n - 1
// a^ + b^2 = c^2
// a + b + c = n
// b = n - a - c
// let d = n - a
// b = d - c
// a^2 + b^2 = c^2
// a^2 + (d - c)^2 = c^2
// a^2 + d^2 = 2dc
// therefore, c = (a^2 + d^2) / 2d;
// therefore, b = d - c
// now check for max a * b * c which satisfies pyth. theorem. 
// O(N) solution :) Naive brute force -> O(N^3)
int main(){
    int t;
    cin >> t;
    while(t--){
        long long  n, pro = (long long)-1;
        cin >> n;
        for(int a = 1; a < n; a++){
            int d = n - a;
            int c = ((a * a) + (d * d)) / (2 * d);
            int b = d - c;
            if(b == 0 || c == 0)
                continue;
            if((a * a) + (b * b) == c * c){
                pro = max(pro, (long long)a * b * c);
            }
        }
        cout << pro << endl;
    }
    return 0;
}
