#include<bits/stdc++.h>
using namespace std;

int findGCD(int a, int b){
    if(b == 0)
        return a;
    return findGCD(b, a % b);
}
int findLCM(int a, int b){
    int gcd  = findGCD(a, b);
    return a * b / gcd;
}
int main(){
    int LCM[41] = {0}; 
    LCM[1] = 1; // LCM of 1
    LCM[2] = 2; // LCM of 1,2
    for(int i = 3; i < 41; i++){
        LCM[i] = findLCM(LCM[i - 1] , i);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << LCM[n] << endl;
    }
    return 0;
}
