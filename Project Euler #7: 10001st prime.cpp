#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

void findPrimes(){
    bool isPrime[105001];
    memset(isPrime, true, sizeof(isPrime)); 

    for(int p = 2; p * p <= 105000; p++){
        if(isPrime[p]){
            for(int i = p * p; i <= 105000; i += p){
                isPrime[i] = false;
            }
        }
    }
    for(int i = 2; i <= 105000; i++){
        if(isPrime[i])
            primes.push_back(i);
    }
}
int main(){
    findPrimes();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << primes[n - 1] << endl;
    }
    return 0;
}
