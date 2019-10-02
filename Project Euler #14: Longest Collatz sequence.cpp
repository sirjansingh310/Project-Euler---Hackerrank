#include <bits/stdc++.h>
using namespace std;

map<long long, int> memo;
int chain(long long i){
    // check if element already exists in memo
    if(memo.find(i) != memo.end()){
        return memo[i];
    }

    long long next;
    if(i % 2 == 0)
        next = i / 2;
    else
        next = 3 * i + 1;
    int count = 1;
    while(next > 5000001 ){
        if(next % 2 == 0)
            next = next / 2;
        else
            next = 3 * next + 1;
        count++;
    }
    memo[i] =  count + chain(next);
    return memo[i];
    
}



int main() {
    memo[1] = 1;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int maxChain = -1;
        int result = 0;
        for(long long i = n; i >= 1; i--){
            int chainLength = chain(i);
            if(chainLength > maxChain){
                maxChain = chainLength;
                result = i;
            }
        }
        cout << result << endl;
    }
    return 0;
}
