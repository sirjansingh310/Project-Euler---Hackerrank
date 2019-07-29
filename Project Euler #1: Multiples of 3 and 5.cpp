#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n--;
        long long multiplesOf3, multiplesOf5, multiplesOf15;
        long long n1, n2, n3;
        n1 = n / 3;
        n2 = n / 5;
        n3 = n / 15;
        multiplesOf3 = 3 * n1 * (n1 + 1) / 2;
        multiplesOf5 = 5 * n2 * (n2 + 1) / 2;
        multiplesOf15 = 15 * n3 * (n3 + 1) / 2;
        cout << multiplesOf3 + multiplesOf5 - multiplesOf15 << endl;
    }
    return 0;
}
