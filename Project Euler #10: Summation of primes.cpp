#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

void generatePrimes(){
    const int max = 1000001;
    bool isPrime[max];
    memset(isPrime, true, sizeof(isPrime));

    for(int p = 2; p * p < max; p++){
        if(isPrime[p]){
            for(int i = p * p; i < max; i += p){
                isPrime[i] = false;
            }
        }
    }

    for(int i = 2; i < max; i++){
        if(isPrime[i])
            primes.push_back(i);
    }
}

int main(){
    int t;
    cin >> t;
    generatePrimes();
    while(t--){
        int n;
        cin >> n;
        long long sum = 0LL;
        for(int i = 0; i < primes.size(); i++){
            if(primes[i] > n)
                break;
            sum += primes[i];
        }
        cout << sum << endl;
    }

    return 0;
}
