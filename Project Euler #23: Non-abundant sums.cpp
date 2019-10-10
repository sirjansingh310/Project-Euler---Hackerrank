#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> abundant;

int getSumOfDivisors(int n){
    int sum = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            sum += i;
            if(i != n / i)
                sum += n / i;
        }
    }
    return sum - n;
}
void fillAbundantVec(){
    for(int i = 2; i < 28123; i++){
        if(i < getSumOfDivisors(i))
            abundant.push_back(i);
    }
}

bool isSumOfAbundants(int n){
    int sum; 
    int low = 0, high = abundant.size() - 1;
    while(low <= high){
        sum = abundant[low] + abundant[high];
        if(sum > n)
            high--;
        else if(sum < n)
            low++;
        else if(sum == n)
            return true;
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    fillAbundantVec();
    while(t--){
        int n;
        cin >> n;
        if(n >= 28123)
            cout << "YES" << endl;

        else{
            if(isSumOfAbundants(n))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}
