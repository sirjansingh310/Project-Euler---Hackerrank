#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int factorSum[(int)1e5 + 1];

void findFactorSum(int n){
    int sum = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            sum += i;
        if(n / i != i)
            sum += n / i;
        }
    }

    factorSum[n] = sum - n;
}
int main() {

    for(int i = 1; i < sizeof(factorSum)/sizeof(factorSum[0]); i++)
       findFactorSum(i);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int sum = 0;
        for(int current = 1; current <= n; current++){
            int currentFactorSum = factorSum[current];
            if(current != currentFactorSum && currentFactorSum <= 100000 && current == factorSum[currentFactorSum]){
                sum += current;
            }
            else if(currentFactorSum > 100000){
                continue;
                // need not find sum of factors if this number is more than 10^5 because 
                // it anyways won't be counted in our final sum(MAX N is 10^5)
            }
        }
        cout << sum << endl;
    }

}
