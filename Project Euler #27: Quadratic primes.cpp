#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool isNumberPrime(int n){
    if(n <= 1)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
int findNumberOfConsecutivePrimes(int a, int b){
    int X = 0;
    int equation = b; // for X = 0.
    while(isNumberPrime(equation)){
        X++;
        equation = X * X + a * X + b;
    }
    return X + 1; // number of consecutive primes
}


int main() {
    int N;
    cin >> N;
    // x^2 + ax + b. a has to be odd and b has to be prime so that the
    // sequence can generate primes of values 0 to x. substitute values x = 0 and x = 1 to see. a is odd so it can be + or -. b has to be + as it has to be prime.
    int maxPrimesGenerated = 1;
    int result_a, result_b;
    for(int a = 1; a <= N; a += 2){
        for(int b = 2; b <= N; b++){
            if(!isNumberPrime(b))
                continue;
           int consecutivePrimesCount = findNumberOfConsecutivePrimes(a, b);
           if(consecutivePrimesCount > maxPrimesGenerated){
               result_a = a;
               result_b = b;
               maxPrimesGenerated = consecutivePrimesCount;
           }

           consecutivePrimesCount = findNumberOfConsecutivePrimes(-a, b);
           if(consecutivePrimesCount > maxPrimesGenerated){
               result_a = -a;
               result_b = b;
               maxPrimesGenerated = consecutivePrimesCount;
           }

        }
    }
    cout << result_a << " " << result_b;
    return 0;
}
