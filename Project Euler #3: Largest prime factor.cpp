#include<bits/stdc++.h>
using namespace std;

long long largestPrimeFactor(long long n){
    long long pf;
    while(n % 2 == 0){
        pf = 2;
        n /= 2;
    }
    for(long long i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            n /= i;
            pf = i;
        }
    }
    if(n > 2)
        pf = n;
    return pf;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        cout << largestPrimeFactor(n) << endl;
    }
    return 0;
}
