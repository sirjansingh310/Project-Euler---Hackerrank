#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numberOfFactors(int n){
    if(n == 1)
        return 1;
    int count = 0;
    for(int i = 1; i <=sqrt(n); i++){
        if(n % i == 0){
            if(n / i != i)
                count += 2;
            else
                count++;
        }
    }
    return count;
}
int main() {
    int arr[1001] = {0};
    long temp = 0, currentN = 0; // temp is the number of factors of current triangle number(sum of n natural numbers)

    for(int i = 1; i < 1001; i++){
        while(temp <= i){             
            currentN++;
            if(currentN % 2 == 1){ // faster than numberOfFactors(currentN * (currentN + 1) / 2) . numberofFactors(a*b) = numberOfFactors(a) * numberOfFactors(b)
                temp = numberOfFactors(currentN);
                temp *= numberOfFactors((currentN + 1) / 2); // We did even odd check for dividing currentN * (currentN + 1) / 2 into 2 numbers correctly for our factor function.
                                 // if even-odd check was not done, (currentN + 1) / 2, for even value of currentN would return floor value, hence wrongly dividing into 2 numbers.                
                }
            else{
                temp = numberOfFactors(currentN / 2);
                temp *= numberOfFactors(currentN + 1);
            }
        }
        arr[i] = currentN * (currentN + 1) / 2; // traingle number where temp(storing number of factors) > i. 
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}
